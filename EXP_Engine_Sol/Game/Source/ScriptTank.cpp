#include "ScriptTank.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleScene.h"



ScriptTank::ScriptTank(GameObject* parent):ComponentScript(parent)
{

}

ScriptTank::~ScriptTank()
{

}

void ScriptTank::Enable()
{

	cannon = parent->Parent->children[0];
	//cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, cannonRotation, 0.0f));

	LOG("Script tank enabled");
}

void ScriptTank::Update()
{

	float3 actualPosition = parent->Parent->transform->GetPosition();

	//Base Movement
	if(ExternalApp->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		actualPosition.x += moveSpeed*ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) 
	{
		actualPosition.x -= moveSpeed*ExternalApp->DT();

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
	
	if (ExternalApp->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_DOWN)
	{
		cannonActive = true;
		actualMousePosition = ExternalApp->input->GetMouseX();
	}

	else if (ExternalApp->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_UP)
	{
		cannonActive = false;
	}


	if (cannonActive) 
	{

		int mousePositionDif = actualMousePosition - ExternalApp->input->GetMouseX();

		int rotationDirection = 0;

		if (mousePositionDif > 0) {

			rotationDirection = 1;

		}
		else if (mousePositionDif < 0) {

			rotationDirection = -1;

		}

		cannonRotation += (rotationSpeed * rotationDirection) * ExternalApp->DT();

		cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, cannonRotation, 0.0f));
	}

	//Tank Shooting

	if (ExternalApp->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		ExternalApp->importer->ReadFile("Assets/Models/Primitives/Sphere.fbx");
		ExternalApp->importer->ReadFile("Assets/Textures/Guitar.png");
		GameObject* bulletRef = ExternalApp->scene->gameObjects.back();
		bulletRef->transform->SetGlobalPosition(parent->Parent->transform->GetPosition());
		bulletRef->transform->SetScale({ 0.5,0.5,0.5 });
	}
}

void ScriptTank::Disable()
{

	LOG("Script Tank disabled");

}

void ScriptTank::DrawInspector()
{
}
