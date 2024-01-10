#include "ScriptTank.h"
#include "Application.h"
#include "ModuleInput.h"


ScriptTank::ScriptTank(GameObject* parent):ComponentScript(parent)
{

}

ScriptTank::~ScriptTank()
{

}

void ScriptTank::Enable()
{
	LOG("Script tank enabled");
}

void ScriptTank::Update()
{
	ComponentScript::Update();

	float3 actualPosition = parent->Parent->transform->GetPosition();

	//Base Movement
	if(ExternalApp->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		actualPosition.x -= moveSpeed*ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) 
	{
		actualPosition.x += moveSpeed*ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		actualPosition.z += moveSpeed*ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		actualPosition.z -= moveSpeed*ExternalApp->DT();	
	}
	parent->Parent->transform->SetPosition(actualPosition);

	//Cannon Movement
	GameObject* children = parent->Parent->children[0];

	Quat actualRotation = children->transform->GetRotation();

	if (ExternalApp->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT)
	{
		actualRotation = actualRotation.RotateY(20.0f);
	}
	children->transform->SetRotation(actualRotation);

}

void ScriptTank::Disable()
{

	LOG("Script Tank disabled");

}

void ScriptTank::DrawInspector()
{
}
