#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Input processing
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Shader Sources
//================================================================================================================

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

//================================================================================================================


int main() {

    // THE GLFW AND GLAD STUFF
    //=====================================================================================================================
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

    //=====================================================================================================================
    
    // SHADER PROGRAM
    //=====================================================================================================================

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
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        // checking status of the fragment shader now
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            return -1;
        }

        // link Shaders into a Program
        unsigned int shaderProgram = glCreateProgram();
        // okay here the order how you link does not matter cause the ids themselves tell what kind of shader it is 
        glAttachShader(shaderProgram, fragmentShader);
        glAttachShader(shaderProgram, vertexShader);
        glLinkProgram(shaderProgram);

        // Delete shaders as they're linked into the program now
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // checking status of the shader program now
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::PROGRAM::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
            return -1;
        }

    //=====================================================================================================================
    
    // VAO , VBO and EBO 
    //=====================================================================================================================
        
        //suppose initially we take 3 vertices
        float vertices[] = {
             0.5f,  0.5f, 0.0f,  
             0.5f, -0.5f, 0.0f,  
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
            
        };
        
        unsigned int indices[] = {
            0,1,2,
            0,2,3
        };
        
        // store the VBO and also how to access it 
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        
        glBindVertexArray(VAO);
        
        unsigned int EBO;
        glGenBuffers(1, &EBO);
        
        // so we made a unique id for a vertex buffer
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        // then we selected that buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // then we send data for that buffer , selected the size of the buffer and then assigned type of buffer according to how many
        // times its going to be accessed
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,GL_STATIC_DRAW);
        
        // okay so now we have to tell opengl how to access this info in buffer
        // vertex buffer
        //  '----' <= attribute 1
        // || x1 | y1 | z1 | x2 | y2 | z2 | ... ... ||
        //  '--------------'
        //    | vertex 1 |
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        // argument 1 : specifies the location of the vertex attribute
        // argument 2 : number of values in the attribute
        // argument 3 : type of values in the attribute
        // argument 4 : whether to normalize or not
        // argument 5 : stride length
        // argument 6 : idk ?
        
        glEnableVertexAttribArray(0);

    //=====================================================================================================================    

    // Render loop

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our object
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES , 6,GL_UNSIGNED_INT,0);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // deleting the buffers
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}