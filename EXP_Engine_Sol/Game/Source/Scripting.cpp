#include "../External/ImGui/imgui.h"
#include "Application.h"
#include "ModuleScene.h"
#include "Scripting.h"

Scripting::Scripting(Application* parent, bool start_enabled) : Module(parent, start_enabled)
{
	LOG("Module Scripting created");
}

Scripting::~Scripting()
{
	LOG("Module Scripting destructor");
}

bool Scripting::Init()
{
	LOG("Module Scripting Init");
	return false;
}

bool Scripting::Start()
{
	LOG("Module Scripting Start");
	return false;
}

update_status Scripting::Update(float dt)
{
	if (!App->scene->gameTime.IsRunning()) {
		return UPDATE_CONTINUE; //to skip to the rest of the code
	}
	LOG("Module Scripting Update");
	return update_status();
}

bool Scripting::CleanUp()
{
	LOG("Module Scripting CleanUp");
	return false;
}
