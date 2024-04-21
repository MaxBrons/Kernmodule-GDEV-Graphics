#include "Core.h"

#include <iostream>
#include <glfw/include/GLFW/glfw3.h>
#include <glad/glad.h>

int main()
{
	if (!glfwInit())
		return 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		return 0;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "New Window", NULL, NULL);
	if (window == NULL)
	{
    	std::cout << "Failed to create GLFW window" << std::endl;
    	glfwTerminate();
    	return -1;
	}

	glViewport(0, 0, 1280, 720);
	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window))
	{
	    glfwSwapBuffers(window);
	    glfwPollEvents();    
	}

	glfwTerminate();
	return 0;
}