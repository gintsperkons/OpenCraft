#pragma once


#include <GL/glew.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm\gtc\type_ptr.hpp>


class Mesh
{
public:
	Mesh();

	void CreateMesh(GLfloat* vertices, unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	static void RenderAll(std::vector<Mesh*> meshList, GLuint uniformModel, GLuint uniformColor);
	void ClearMesh();

	~Mesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;

};

