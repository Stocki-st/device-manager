#ifndef DEVICE_MANAGER_H_
#define DEVICE_MANAGER_H_

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace device_manager {

struct Device {
  int id;
  std::string name;
  bool is_active;
};

class DeviceManager {
 public:
  explicit DeviceManager(const std::string& filename);
  void AddDevice(const std::string& name, bool is_active);
  void RemoveDevice(int id);
  void ListDevices() const;
  void FilterDevices(bool is_active) const;

 private:
  void SaveToFile() const;
  void LoadFromFile();

  std::string filename_;
  std::vector<Device> devices_;
  int next_id_ = 1;
};

}  // namespace device_manager

#endif  // DEVICE_MANAGER_H_
