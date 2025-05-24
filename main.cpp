#include <iostream>
#include "SomeLibDemo/adder.h"
#include "CMakeDemoConfig.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    std::cout << "2 + 3 = " << mearlymath::add(2, 3) << std::endl;
    std::cout << argv[0] << " Version " << CMakeDemo_VERSION_MAJOR << "." << CMakeDemo_VERSION_MINOR << "\n";

    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return EXIT_FAILURE;
    }

    // Create an OpenGL 3.3 core profile context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(300, 300, "GLEW + GLFW Demo", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to open GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW after the context is current
    glewExperimental = GL_TRUE; // ensure modern function pointers
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cerr << "GLEW init failed: "
                  << glewGetErrorString(err) << "\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << "\n";

    // Simple render loop: clear to cornflower blue each frame
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}