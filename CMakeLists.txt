cmake_minimum_required(VERSION 4.0.2)

project(CMakeDemo VERSION 1.1)

find_package(GLEW REQUIRED)

configure_file(CMakeDemoConfig.h.in CMakeDemoConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

# So we can access CMakeDemoConfig.h in root level
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(SomeLibDemo)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)

target_link_libraries(${PROJECT_NAME} PUBLIC Adder glfw GLEW::GLEW)