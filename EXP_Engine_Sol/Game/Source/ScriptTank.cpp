#include "ScriptTank.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "Bullet.h"



ScriptTank::ScriptTank(GameObject* parent):ComponentScript(parent)
{

}

ScriptTank::~ScriptTank()
{

}

void ScriptTank::Enable()
{

	cannon = parent->children[0];
	//cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, cannonRotation, 0.0f));

	LOG("Script tank enabled");
}

void ScriptTank::Update()
{

	float3 actualPosition = parent->transform->GetPosition();

	//Base Movement
	if(ExternalApp->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		//actualPosition.x += moveSpeed*ExternalApp->DT();
		tankRotation += rotationTankSpeed * ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) 
	{
		//actualPosition.x -= moveSpeed*ExternalApp->DT();
		tankRotation -= rotationTankSpeed * ExternalApp->DT();
	}

	if (ExternalApp->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		//actualPosition.z += moveSpeed*ExternalApp->DT();
		actualPosition += parent->transform->GetForward() * moveSpeed * ExternalApp->DT();
	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		//actualPosition.z -= moveSpeed*ExternalApp->DT();
		actualPosition -= parent->transform->GetForward() * moveSpeed * ExternalApp->DT();
	}
	parent->transform->SetPosition(actualPosition);
	parent->transform->SetRotation(Quat::FromEulerXYZ(0.0f, tankRotation, 0.0f));

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

		cannonRotation += (rotationCannonSpeed * rotationDirection) * ExternalApp->DT();

		cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, cannonRotation, 0.0f));
	}

	//Tank Shooting

	if (ExternalApp->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		ExternalApp->importer->ReadFile("Assets/Models/Primitives/Sphere.fbx");
		ExternalApp->importer->ReadFile("Assets/Textures/Guitar.png");
		GameObject* bulletRef = ExternalApp->scene->gameObjects.back()->Parent;

		float3 bulletSpawnPos = parent->transform->GetPosition() + cannon->transform->GetForward() * 2.0f;
		bulletRef->transform->SetPosition(bulletSpawnPos);
		bulletRef->transform->SetScale({ 0.5,0.5,0.5 });
		Bullet* bulletScript = new Bullet(bulletRef);
		bulletRef->AddComponent(bulletScript);
		bulletScript->ShotBullet(cannon->transform->GetForward() + parent->transform->GetRotation().ToEulerXYZ().Normalized(), 0.5, 5.0f);
	}
}

void ScriptTank::Disable()
{

	LOG("Script Tank disabled");

}

void ScriptTank::DrawInspector()
{
}
