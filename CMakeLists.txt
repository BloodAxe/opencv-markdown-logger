cmake_minimum_required(VERSION 2.8)
project(markdown-logger)

# Search for required software packages:
find_package(OpenCV REQUIRED)

#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system program_options unit_test_framework serialization REQUIRED)

# Set global flags
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

ADD_DEFINITIONS(-std=c++11)

# Add include directories to search path:
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

# Add link directories:
link_directories(${OpenCV_LIBRARY_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Add targets
add_executable(basic-example example01.cpp markdown.hpp markdown.cpp)
add_executable(opencv-example opencv-example.cpp markdown.hpp markdown.cpp markdown-opencv.hpp)

target_link_libraries(basic-example ${OpenCV_LIBS})
target_link_libraries(opencv-example ${OpenCV_LIBS})