#pragma once

#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>

#include<GL/glew.h>

class Shader
{
public:
	Shader();
	void Create();

	std::string ReadFile(std::string fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetColorLocation();


	void Use();
	void Clear();


	~Shader();

private:
	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformColor;
	std::string vertexLocation = "Shaders/shader.vert", fragmentLocation = "Shaders/shader.frag";
	void Compile(const char* vertexCode, const char* fragmentCode);
	void Add(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

