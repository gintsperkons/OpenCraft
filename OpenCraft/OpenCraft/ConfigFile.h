#pragma once

#include "Application.h"
#include "Camera/Camera.h"
#include "Window/Window.h"
#include "World/World.h"

class Application;
class Camera;
class Window;
class World;



class ConfigFile
{
public:
	ConfigFile();
	Application* getApp() { return app; };
	Camera* getCamera() { return camera; };
	Window* getWindow() { return mainWindow; };
	World* getWorld() { return worldStorage; };
	void setApp(Application* tempApp) { app = tempApp; };
	void setCamera(Camera* tempCam) { camera = tempCam; };
	void setWindow(Window* tempWindow) { mainWindow = tempWindow; };
	void setWorld(World* tempWorld) { worldStorage = tempWorld; };

	~ConfigFile();

private:
	Application *app;
	Window *mainWindow;
	Camera *camera;
	World *worldStorage;
};

