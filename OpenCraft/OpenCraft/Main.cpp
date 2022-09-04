#include "Application.h"
#include "ConfigFile.h"
int main()
{
	ConfigFile *config = new ConfigFile();
	config->setApp(new Application(config)) ;
	return config->getApp()->StartApp();
}