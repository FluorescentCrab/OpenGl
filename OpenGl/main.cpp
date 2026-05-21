#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

// P1 C5 Q3
// So using two shader program with diff fragment shader

std::string readFile(const std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "ERROR CANNOT OPEN FILE : " << fileName << std::endl;
        return "";
    }

    std::stringstream ss {};
    ss << file.rdbuf();
    file.close();

    return ss.str();
}

// Callback for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Input processing
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}



int main() {

    // glfw init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // creating a window using glfw
    GLFWwindow* window = glfwCreateWindow(600, 600, "Learning OpenGL - Fixed", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // so what this does is if we call it it resizes the window accordingly to the new dimensions 
    // if we dont use it then the displayed content will remain the same size just we will see more of the screen
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //loading glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    const std::string fragment1ShaderSourceCpp = readFile("fragment1.glsl");
    const std::string fragment2ShaderSourceCpp = readFile("fragment2.glsl");
    const std::string vertexShaderSourceCpp = readFile("vertex.glsl");

    const char* fragment1ShaderSource = fragment1ShaderSourceCpp.c_str();
    const char* fragment2ShaderSource = fragment2ShaderSourceCpp.c_str();
    const char* vertexShaderSource = vertexShaderSourceCpp.c_str();

    //okay so making a vertex shader
    // so this gives the shader a unique id 
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // this is the actual data of the shader we are linking that to the unique id 
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // idk what 2nd and last arg does 
    // compiling the shader
    glCompileShader(vertexShader);

    // now what if i want to check if the compilation of the shader was successful or not?
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }

    // similar to the above vertex shader
    unsigned int fragment1Shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment1Shader, 1, &fragment1ShaderSource, NULL);
    glCompileShader(fragment1Shader);

    // checking status of the fragment shader now
    glGetShaderiv(fragment1Shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment1Shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT:1::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }

    // link Shaders into a Program
    unsigned int shaderProgram1 = glCreateProgram();
    // okay here the order how you link does not matter cause the ids themselves tell what kind of shader it is 
    glAttachShader(shaderProgram1, fragment1Shader);
    glAttachShader(shaderProgram1, vertexShader);
    glLinkProgram(shaderProgram1);


    // similar to the above vertex shader
    unsigned int fragment2Shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment2Shader, 1, &fragment2ShaderSource, NULL);
    glCompileShader(fragment2Shader);

    // checking status of the fragment shader now
    glGetShaderiv(fragment2Shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment2Shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT:2::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }

    // link Shaders into a Program
    unsigned int shaderProgram2 = glCreateProgram();
    // okay here the order how you link does not matter cause the ids themselves tell what kind of shader it is 
    glAttachShader(shaderProgram2, fragment2Shader);
    glAttachShader(shaderProgram2, vertexShader);
    glLinkProgram(shaderProgram2);

    // Delete shaders as they're linked into the program now
    glDeleteShader(vertexShader);
    glDeleteShader(fragment1Shader);
    glDeleteShader(fragment2Shader);

    // checking status of the shader program now
    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    
    // checking status of the shader program now
    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }

    // triangle 1
    float vertices1[] = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    // triangle 2
    float vertices2[] = {
         0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    unsigned int VAO1;
    unsigned int VBO1;

    glGenVertexArrays(1, &VAO1);
    glBindVertexArray(VAO1);

    glGenBuffers(1, &VBO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    glEnableVertexAttribArray(0);



    unsigned int VAO2;
    unsigned int VBO2;

    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);

    glGenBuffers(1, &VBO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);


    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our object
        glUseProgram(shaderProgram1);
        glBindVertexArray(VAO1);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram2);
        glBindVertexArray(VAO2);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);     <= so this is not needed as we will not be using EBO
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO1);
    glDeleteVertexArrays(1, &VAO2);

    glDeleteBuffers(1, &VBO1);
    glDeleteBuffers(1, &VBO2);
    glDeleteProgram(shaderProgram1);
    glDeleteProgram(shaderProgram2);

    glfwTerminate();
    return 0;
}