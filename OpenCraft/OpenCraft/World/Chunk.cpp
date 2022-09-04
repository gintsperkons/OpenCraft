#include "Chunk.h"
Chunk::Chunk()
{
}

void Chunk::CreateChunk(long long x, long long y)
{
    chunkX = x;
    chunkY = y;
    for (int i = 0; i < heigth; i++)
    {
        std::vector<std::vector<Block*>> v2d;
        for (int j = 0; j < width; j++)
        {
            std::vector<Block*> v1d;
            for (int k = 0; k < depth; k++)
            {
                v1d.push_back(new Air());
            }
            v2d.push_back(v1d);
        }
        chunkData3d.push_back(v2d);
    }
}

std::string Chunk::GetBlock(long long x, long long y, long long z)
{
    
    return chunkData3d[y][x][z]->GetType();
}

Chunk::~Chunk()
{
}