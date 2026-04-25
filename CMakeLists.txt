cmake_minimum_required(VERSION 3.27)
project(TrainingPointer)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES 
    "source/main.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC "./source")