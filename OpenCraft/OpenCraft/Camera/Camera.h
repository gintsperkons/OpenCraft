#pragma once

#include<GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "../ConfigFile.h"

class ConfigFile;

class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat xChange, GLfloat yChange);

	float getX() { return position.x; };
	float getY() { return position.y; };
	float getZ() { return position.z; };

	glm::mat4 calculateViewMatrix();

	void setConfig(ConfigFile* tempConfig) { config = tempConfig; };
	~Camera();

private:
	ConfigFile *config;

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	GLfloat xChange = 0.0f;
	GLfloat yChange = 0.0f;


	GLfloat yaw = 0.0f;
	GLfloat pitch = 0.0f;

	GLfloat moveSpeed;
	GLfloat turnSpeed;
	bool firstMove = true;

	void update();

};

