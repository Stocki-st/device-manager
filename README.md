# Device Manager Project

This project provides a simple console-based device management system. Users can add, remove, list, and filter devices.

## Features
- Add new devices with a name and active/inactive status.
- Remove devices by ID.
- List all devices.
- Filter devices by their status.

## Requirements
- C++17
- CMake 3.10 or higher
- [nlohmann/json](https://github.com/nlohmann/json)

## Build Instructions
1. Clone the repository.
2. Navigate to the project directory.
3. Create a build directory:
   ```bash
   mkdir build && cd build
   ```
4. Run CMake and build:
   ```bash
   cmake ..
   make
   ```

## Usage
Run the `device_manager` executable to start the program. Follow the menu prompts to manage devices.
