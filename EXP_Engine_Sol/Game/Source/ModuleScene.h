#pragma once
#pragma once
#include "Module.h"
#include "Globals.h"
#include "GameObject.h"

#include <vector>

class ModuleScene : public Module
{
public:
	ModuleScene(Application* app, bool start_enabled = true);
	~ModuleScene();

	bool Init();
	update_status PreUpdate(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

	GameObject* CreateGameObject(std::string Name, GameObject* parent);
	

public: 

	GameObject* rootGameObject = nullptr;
	std::vector<GameObject*> gameObjects;
	GameObject* gameObjectSelected = nullptr;

	
};