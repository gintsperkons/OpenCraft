#pragma once

#include <stdio.h>
#include <string.h>
#include <cmath>
#include<vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "ConfigFile.h"
#include "Mesh/Mesh.h"
#include "Shader/Shader.h"
#include "Mesh/Blocks/Block.h"
#include "Texture.h"

class ConfigFile;

class Application
{
public:
	Application();
	Application(ConfigFile *tempConfig) { config = tempConfig; };
	void createGrid(unsigned int size);
	void CreateShaders();
	int StartApp();
	~Application();
private:

	//Window dimensions
	const GLint width = 1080, height = 720;
	const float toRadians = 3.14159265f / 180.0f;


	std::vector<Shader> shaderList;

	GLfloat deltaTime = 0.0f;
	GLfloat lastTime = 0.0f;


	ConfigFile* config;

	Texture cobbleStoneTexture;
};
