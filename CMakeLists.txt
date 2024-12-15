cmake_minimum_required(VERSION 3.28)
project(hello_world_juce)

set(CMAKE_CXX_STANDARD 17)

find_package(juce CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        juce::juce_core
)
