#include "ConfigFile.h"

ConfigFile::ConfigFile()
{
	app = new Application();
	mainWindow = new Window();
	camera = new Camera();
	worldStorage = new World();
}

ConfigFile::~ConfigFile()
{
}