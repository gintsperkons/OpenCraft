#pragma once

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../ConfigFile.h"

class ConfigFile;
class Window
{
public:
	Window();
	void setConfig(ConfigFile* tempConfig) { config = tempConfig; };

	Window(GLint windowWidth, GLint windowHeight);

	int Initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

	bool* getsKeys() { return keys; }

	GLfloat getXChange();
	GLfloat getYChange();


	void swapBuffers() { glfwSwapBuffers(mainWindow); }


	~Window();


private:
	ConfigFile *config;

	GLFWwindow* mainWindow;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

	bool keys[1024];

	GLfloat lastX = 0.0f, lastY = 0.0f;
	GLfloat xChange = 0.0f, yChange = 0.0f;

	bool mouseFirstMoved;

	void createCallbacks();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};

