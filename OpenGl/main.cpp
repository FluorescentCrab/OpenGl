#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	// initialize glfw
	glfwInit();

	// configuring the glfw 
	// -----------------------------------------------------------------------------
	// setting the opengl version as 3.3
	// =============================================================
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// =============================================================
	// setting the opengl profile as core
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// -----------------------------------------------------------------------------

	// so creating a new windows obj.
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn Opengl", NULL, NULL);

	// checking if the window was created sucessfully
	if (window == NULL) {
		std::cout << "failed to create GLFW window" << std::endl;

		glfwTerminate();
		return -1;
	}
	// making it the current context of the thread
	glfwMakeContextCurrent(window);

	// getting all the opengl pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "failed to init. GLAD" << std::endl;
		return -1;
	}

	// configuring the viewport
	glViewport(0, 0, 800, 600);

	// making sure the window when resized also resizes the viewport
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// while we dont want the window to close
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		// clearing background to a specific color
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}