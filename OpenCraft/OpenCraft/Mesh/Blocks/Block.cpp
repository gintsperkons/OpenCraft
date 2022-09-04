#include "Block.h"

long long int cordinates[3] = {0,0,0}; //x,y,z


unsigned int indices[]{
		0,2,1,
		0,3,2,
		4,5,6,
		5,7,6,
		8,9,10,
		8,10,11,
		12,13,14,
		13,15,14,
		16,17,18,
		17,19,18,
		20,21,22,
		21,23,22,


};



Block::Block()
{
}

Mesh* Block::CreateBlock(long long x, long long y, long long z)
{
	cordinates[0] = x;
	cordinates[1] = y;
	cordinates[2] = z;
	float size = 1.0;


	GLfloat vertices[] = {
	cordinates[0],			cordinates[1],			cordinates[2], 0.0f,1.0f, // 0
	cordinates[0] + size,	cordinates[1],			cordinates[2], 0.0f,0.0f, // 1
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2], 1.0f,0.0f, //2
	cordinates[0],			cordinates[1] + size,	cordinates[2], 1.0f,1.0f, //3
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2], 0.0f,0.0f, //4
	cordinates[0],			cordinates[1] + size,	cordinates[2], 0.0f,1.0f, //5
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2] + size, 1.0f,0.0f, //6
	cordinates[0],			cordinates[1] + size,	cordinates[2] + size, 1.0f,1.0f, //7
	cordinates[0],			cordinates[1],			cordinates[2] + size, 0.0f,0.0f, //8
	cordinates[0] + size,	cordinates[1],			cordinates[2] + size, 0.0f,1.0f, //9
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2] + size, 1.0f,1.0f, //10
	cordinates[0],			cordinates[1] + size,	cordinates[2] + size, 1.0f,0.0f, //11
	cordinates[0],			cordinates[1],			cordinates[2], 0.0f,0.0f, // 12
	cordinates[0] + size,	cordinates[1],			cordinates[2], 0.0f,1.0f, // 13
	cordinates[0],			cordinates[1],			cordinates[2] + size, 1.0f,0.0f, //14
	cordinates[0] + size,	cordinates[1],			cordinates[2] + size, 1.0f,1.0f, //15
	cordinates[0],			cordinates[1],			cordinates[2], 0.0f,0.0f, // 16
	cordinates[0],			cordinates[1],			cordinates[2] + size, 0.0f,1.0f, //17
	cordinates[0],			cordinates[1] + size,	cordinates[2], 1.0f,0.0f, //18
	cordinates[0],			cordinates[1] + size,	cordinates[2] + size, 1.0f,1.0f, //19
	cordinates[0] + size,	cordinates[1],			cordinates[2], 0.0f,1.0f, // 20
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2], 1.0f,1.0f, //21
	cordinates[0] + size,	cordinates[1],			cordinates[2] + size, 0.0f,0.0f, //22
	cordinates[0] + size,	cordinates[1] + size,	cordinates[2] + size, 1.0f,0.0f, //23

		//x							y						z		u  	 v
	//cordinates[0],			cordinates[1],			cordinates[2], 0.0f,1.0f, // 0
	//cordinates[0] + size,	cordinates[1],			cordinates[2], 0.0f,0.0f, // 1
	//cordinates[0] + size,	cordinates[1] + size,	cordinates[2], 1.0f,1.0f, //2
	//cordinates[0],			cordinates[1] + size,	cordinates[2], 1.0f,0.0f, //3
	//cordinates[0],			cordinates[1],			cordinates[2] + size, 1.0f,0.0f, //4
	//cordinates[0] + size,	cordinates[1],			cordinates[2] + size, 1.0f,1.0f, //5
	//cordinates[0] + size,	cordinates[1] + size,	cordinates[2] + size, 0.0f,1.0f, //6
	//cordinates[0],			cordinates[1] + size,	cordinates[2] + size, 0.0f,0.0f, //7

	};

	
	objectMesh = new Mesh();
	objectMesh->CreateMesh(vertices, indices, 120,36);
	return objectMesh;
}

Block::~Block()
{
}