#include "device-manager.h"
#include <fstream>
#include <iostream>
#include <iomanip>

namespace device_manager {

DeviceManager::DeviceManager(const std::string& filename) : filename_(filename) {
  LoadFromFile();
}

void DeviceManager::AddDevice(const std::string& name, bool is_active) {
  int id = next_id_++;
  devices_.push_back({id, name, is_active});
  SaveToFile();
  std::cout << "Device added with ID: " << id << "\n";
}

void DeviceManager::RemoveDevice(int id) {
  auto it = std::remove_if(devices_.begin(), devices_.end(),
                           [id](const Device& device) { return device.id == id; });
  if (it != devices_.end()) {
    devices_.erase(it, devices_.end());
    SaveToFile();
    std::cout << "Device removed.\n";
  } else {
    std::cout << "Device not found.\n";
  }
}

void DeviceManager::ListDevices() const {
  std::cout << "\nDevices:\n";
  for (const auto& device : devices_) {
    std::cout << "ID: " << device.id
              << ", Name: " << device.name
              << ", Active: " << (device.is_active ? "Yes" : "No") << "\n";
  }
}

void DeviceManager::FilterDevices(bool is_active) const {
  std::cout << "\nFiltered Devices (Active = " << (is_active ? "Yes" : "No") << "):\n";
  for (const auto& device : devices_) {
    if (device.is_active == is_active) {
      std::cout << "ID: " << device.id
                << ", Name: " << device.name << "\n";
    }
  }
}

void DeviceManager::SaveToFile() const {
  std::ofstream file(filename_);
  if (file) {
    nlohmann::json j;
    for (const auto& device : devices_) {
      j.push_back({{"id", device.id}, {"name", device.name}, {"is_active", device.is_active}});
    }
    file << std::setw(4) << j;
  }
}

void DeviceManager::LoadFromFile() {
  std::ifstream file(filename_);
  if (file) {
    nlohmann::json j;
    file >> j;
    for (const auto& item : j) {
      devices_.push_back({item.at("id"), item.at("name"), item.at("is_active")});
      next_id_ = std::max(next_id_, item.at("id").get<int>() + 1);
    }
  }
}

}  // namespace device_manager
