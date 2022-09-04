#pragma once
#include <vector>

#include "../Application.h"
#include "../Mesh/Blocks/Block.h"
#include "Chunk.h"
class Application;
class World
{
public:
	World();
	void getCurrentChunk();
	Chunk* CreateChunk(long long x, long long y); //16x16x256
	void AddBlock(long long x, long long y, long long z, Block* b1);;
	std::string GetBlock(long long x, long long y, long long z);
	Chunk *tempChunk;
	void setConfig(ConfigFile *tempConfig) { config = tempConfig; };
	~World();

private:
	ConfigFile *config;
	std::vector<Chunk*> loadedChunks;
	int renderDistance = 1;
	Chunk *currentChunk;
	Chunk *lastChunk;
	int lastChunkX;
	int lastChunkY;
	int cameraX;
	int cameraZ;
	bool first = true;
};



