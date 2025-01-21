cmake_minimum_required(VERSION 3.16)
project(DeviceManager)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)

add_executable(device_manager
    src/main.cpp
    src/device_manager.cpp
)

target_include_directories(device_manager
    PRIVATE 
        include
)

target_link_libraries(device_manager 
    PRIVATE 
        nlohmann_json::nlohmann_json
)
