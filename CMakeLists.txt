cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TextToBitmap VERSION 1.0.0)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(libs)

add_executable(TextToBitmap src/main.cpp)
target_include_directories(TextToBitmap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(TextToBitmap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/font)
target_link_libraries(TextToBitmap PUBLIC TextToBitmapLib)
