#pragma once

#include "../Mesh.h"

#include <cmath>
#include <string>

class Block: public Mesh
{
	public:
		Block();

		Mesh* CreateBlock(long long x, long long y, long long z);
		void setType(std::string newType) { type = newType; };
		std::string GetType() { return type; };
		~Block();

	private:
		const unsigned int numOfVertices = 24;
		const unsigned int	numOfIndices = 36;
		std::string type = "";
		Mesh* objectMesh;




};

