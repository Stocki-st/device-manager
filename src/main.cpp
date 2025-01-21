#include "device-manager.h"

#include <iostream>
#include <string>


enum class MenuOption {
  AddDevice = 1,
  RemoveDevice,
  ListDevices,
  FilterDevices,
  Exit
};

int main() {
  device_manager::DeviceManager manager("devices.json");

  while (true) {
    std::cout << "\nDevice Manager\n";
    std::cout << static_cast<int>(MenuOption::AddDevice) << ". Add Device\n";
    std::cout << static_cast<int>(MenuOption::RemoveDevice) << ". Remove Device\n";
    std::cout << static_cast<int>(MenuOption::ListDevices) << ". List Devices\n";
    std::cout << static_cast<int>(MenuOption::FilterDevices) << ". Filter Devices\n";
    std::cout << static_cast<int>(MenuOption::Exit) << ". Exit\n";
    std::cout << "Enter your choice: ";

    int choice_int;
    std::cin >> choice_int;
    auto choice = static_cast<MenuOption>(choice_int);

    switch (choice) {
      case MenuOption::AddDevice: {
        std::cin.ignore();
        std::string name;
        bool is_active;
        std::cout << "Enter device name: ";
        std::getline(std::cin, name);
        std::cout << "Is the device active? (1 for Yes, 0 for No): ";
        std::cin >> is_active;
        manager.AddDevice(name, is_active);
        break;
      }
      case MenuOption::RemoveDevice: {
        int id;
        std::cout << "Enter device ID to remove: ";
        std::cin >> id;
        manager.RemoveDevice(id);
        break;
      }
      case MenuOption::ListDevices:
        manager.ListDevices();
        break;
      case MenuOption::FilterDevices: {
        bool is_active;
        std::cout << "Filter by status (1 for Active, 0 for Inactive): ";
        std::cin >> is_active;
        manager.FilterDevices(is_active);
        break;
      }
      case MenuOption::Exit:
        std::cout << "Exiting...\n";
        return 0;
      default:
        std::cout << "Invalid choice. Try again.\n";
    }
  }
}
