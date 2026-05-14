#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// fo resizing the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// for closing the window
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {

	//======================================================================================================
	//======================================================================================================
	// intializing the glfw 
	// why is glfw used ?
	// becoz opengl is just a specification the actual impelemntation depends on the device we are using
	// glfw does this implementation part so the opengl doesnt have to worry about it
	glfwInit();
	// configuring the glfw
	// as using opengl 3.3 with core profile ( i.e no backwards dependancies )
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// so we created a new window in this the 1st 2 params are the dimensions on window created
	// next is the title
	// 3rd is monitor ( used for full screen or somethin)
	// for now 3rd and 4th arg are NULL
	GLFWwindow* window = glfwCreateWindow(600, 600, "learning opengl", NULL, NULL);

	// if the window for some reason window is not created
	if (window == NULL) {
		std::cout << "ERROR : WINDOW NOT CREATED" << std::endl;
		glfwTerminate();
		return -1;
	}

	// if valid window then making it current context \
	// ie. any window function im calling are going to be for this window
	glfwMakeContextCurrent(window);


	// now we want to be able to maintain all the glfw pointer without manually doing it 
	// for that we will use GLAD
	
	if (!gladLoadGLLoader(/*this is a data type*/ (GLADloadproc)glfwGetProcAddress)) {
		std::cout << "ERROR : FAILED TO INTIALIZE" << std::endl;
		return -1;
	}

	glViewport(0, 0, 600, 600);

	// so get called every time the window dimensions get changed
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//======================================================================================================
	//======================================================================================================


	while (!glfwWindowShouldClose(window)) {

		// process input
		processInput(window);

		//rendering command
		// .......
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// check for updates and swap the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}