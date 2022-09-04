
#include "Application.h"
std::vector<Mesh*> meshList;

Application::Application()
{

}




void Application::createGrid(unsigned int size)
{

	for ( size_t x = 0; x < size; x++)
	{
		
		for (size_t y = 0; y < size; y++)
		{
			for (size_t z = 0; z < size; z++)
			{
				
				Block* b1 = new Block();
				config->getWorld()->AddBlock(x,y,z,b1);
				meshList.push_back(b1->CreateBlock(x, y, z));
			}
		}
	}
}

void Application::CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->Create();
	shaderList.push_back(*shader1);
}

int Application::StartApp()
{
	config->getWindow()->setConfig(config);
	config->getWorld()->setConfig(config);
	config->getCamera()->setConfig(config);
	config->getWindow()->Initialise();

	createGrid(16);
	CreateShaders();


	config->setCamera(new Camera(glm::vec3(0.0f, 5.0f, 10.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f));

	cobbleStoneTexture = Texture("Textures/cobblestone.png");
	cobbleStoneTexture.LoadTexture();

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformColor;
	glm::mat4 projection = glm::perspective(45.0f, config->getWindow()->getBufferWidth() / config->getWindow()->getBufferHeight(), 0.1f, 250.0f);
	
	// Loop until window closed
	while (!config->getWindow()->getShouldClose())
	{
		config->getWorld()->getCurrentChunk();
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;
		// Get + Hendle user input events
		glfwPollEvents();
		printf("x:%f,y:%f,z:%f ",config->getCamera()->getX(), config->getCamera()->getY(), config->getCamera()->getZ());
		//printf("%s\n", config->getWorld()->GetBlock(floor(config->getCamera()->getY()), floor(config->getCamera()->getX()), floor(config->getCamera()->getZ())).c_str());
		config->getCamera()->keyControl(config->getWindow()->getsKeys(), deltaTime);
		config->getCamera()->mouseControl(config->getWindow()->getXChange(), config->getWindow()->getYChange());

		// Clear window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cobbleStoneTexture.UseTexture();
		shaderList[0].Use();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformColor = shaderList[0].GetColorLocation();
		
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(config->getCamera()->calculateViewMatrix()));

		Mesh::RenderAll(meshList,uniformModel, uniformColor);
		
		glUseProgram(0);

		config->getWindow()->swapBuffers();
	}
	return 0;
}
Application::~Application()
{
}