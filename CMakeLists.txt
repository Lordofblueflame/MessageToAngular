cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify Boost root directory
set(BOOST_ROOT "C:/Repo/boost_1_86_0")
set(Boost_USE_STATIC_LIBS OFF)  # Set to ON if using static libraries
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# Include Boost headers and link directories
include_directories(${BOOST_ROOT})
link_directories(${BOOST_ROOT}/stage/lib)

# Add your executable
add_executable(MyProject main.cpp)  

# Link Boost libraries and Windows socket libraries to your project
target_link_libraries(MyProject  wsock32 ws2_32)
