cmake_minimum_required(VERSION 3.11.3)
project(manelbrot)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(mandelbrot ${SOURCES})

set_property(TARGET mandelbrot PROPERTY CXX_STANDARD 17)
target_link_libraries(mandelbrot ${OpenCV_LIBRARIES})

# target_compile_options(mandelbrot PRIVATE -Wall -Wextra)
