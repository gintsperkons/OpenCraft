#include "World.h"
World::World()
{
	std::vector<std::                                                                                                                                                                                                                                                
		vector<int>> v2d;
}

void World::getCurrentChunk()
{
	printf("%i\n", loadedChunks.size());
	if (first == true)
	{
		tempChunk = new Chunk();
		tempChunk->CreateChunk(0, 0);
		currentChunk = tempChunk;
		loadedChunks.push_back(currentChunk);
		first = false;
	}
	lastChunk = currentChunk;
	lastChunkX = currentChunk->getX();
	lastChunkY = currentChunk->getY();
	cameraX = floor(floor(config->getCamera()->getX()) / 16);
	cameraZ = floor(floor(config->getCamera()->getZ()) / 16);
	
	printf("%i:%i\n", currentChunk->getX(), currentChunk->getY());
	printf("%s\n",currentChunk->GetBlock(0, 0, 0).c_str());
	if (currentChunk->getX() == cameraX && currentChunk->getY() == cameraZ)
	{
		return;
	}
	//get current position and set as current chunlk
	for (size_t i = 0; i < loadedChunks.size(); i++)
	{
		if (loadedChunks.at(i)->getX() == cameraX && loadedChunks.at(i)->getY() == cameraZ)
		{
			currentChunk = loadedChunks.at(i);
			return;
		}
	}
	if (lastChunkY != cameraX || lastChunkY != cameraZ)
	{
		printf("\n\n\ntest\n\n\n");
		currentChunk = CreateChunk(cameraX, cameraZ);
		currentChunk->CreateChunk(cameraX, cameraZ);
		loadedChunks.push_back(currentChunk);

	}

	//TODO create new chunks

	
}

Chunk* World::CreateChunk(long long x, long long y)
{
	Chunk *temp = new Chunk();
	return temp;

}

void World::AddBlock(long long x, long long y, long long z, Block* b1)
{
}

std::string World::GetBlock(long long x, long long y, long long z)
{
	return currentChunk->GetBlock(y,x,z);
}

World::~World()
{
}