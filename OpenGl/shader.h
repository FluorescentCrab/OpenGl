#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include  <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	// id of the shader program
	unsigned int ID;

	// constructor
	Shader(const char* vertexPath, const char* fragmentPath);
	//destructor
	~Shader();

	// to use shader program
	void use();

	// setting the uniforms
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4 value) const;
	
};

#endif