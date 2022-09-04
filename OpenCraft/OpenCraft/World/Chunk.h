#pragma once
#include <vector>


#include "../Mesh/Blocks/Block.h"
#include "../Mesh/Blocks/Base/Air.h"
class Chunk
{
public:
	Chunk();
	void CreateChunk(long long x, long long y);
	void ReplaceBlock(long long x, long long y, long long z, Block* b1);
	std::string GetBlock(long long x, long long y, long long z);
	int getX() { return chunkX; };
	int getY() { return chunkY; };
	~Chunk();

private:
	int width = 16;
	int depth = 16;
	int heigth = 256;


	long long chunkX = 0;
	long long chunkY = 0;

	std::vector < std::vector < std::vector<Block*>>> chunkData3d;//16x16x256
};


