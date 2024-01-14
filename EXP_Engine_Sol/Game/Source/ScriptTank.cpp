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
	if (bulletPool.size() == 0) {

		for (int i = 0; i < 10; i++)
		{
			ExternalApp->importer->ReadFile("Assets/Models/Primitives/Sphere.fbx");
			ExternalApp->importer->ReadFile("Assets/Textures/Guitar.png");
			GameObject* bulletRef = ExternalApp->scene->gameObjects.back()->Parent;
			bulletPool.push_back(bulletRef);

			bulletRef->transform->SetScale({ 0.3,0.3,0.3 });
			Bullet* bulletScript = new Bullet(bulletRef);
			bulletRef->AddComponent(bulletScript);
			bulletRef->Disable();
		}
	}
	float3 actualPosition = parent->transform->GetPosition();
	float3 actualRotation = parent->transform->GetRotation().ToEulerXYZ();

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
	actualRotation.y += tankRotation;
	parent->transform->SetRotation(Quat::FromEulerXYZ(0.0f,tankRotation, 0.0f));

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
		bool bulletTaken = false;

		for (int i = 0; i < bulletPool.size() && !bulletTaken; i++)
		{
			if(bulletPool[i]->active == false)
			{
				bulletPool[i]->Enable();
				float3 bulletSpawnPos = parent->transform->GetPosition() + cannon->transform->GetForward() * 2.0f;
				bulletPool[i]->transform->SetPosition(bulletSpawnPos);
				Bullet* bulletRef = (Bullet*) bulletPool[i]->GetComponent(typeComponent::Scripts);
				bulletRef->ShotBullet(cannon->transform->GetForward(), 0.5, 3.0f);
				bulletTaken = true;
			}
		}
	}
}

void ScriptTank::Disable()
{
	//for (int i = 0; i < bulletPool.size(); i++)
	//{
	//	ExternalApp->scene->DeleteGameObject(bulletPool[i]);
	//}
	bulletPool.clear();
	LOG("Script Tank disabled");

}

void ScriptTank::DrawInspector()
{

	if (ImGui::CollapsingHeader("Tank Script")) {
		float tempMoveSpeed = moveSpeed;
		ImGui::InputFloat("movement Speed", &tempMoveSpeed);
		moveSpeed = tempMoveSpeed;
	}

}
