#include "ScriptTank.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "Bullet.h"
#include <streambuf>
#include <fstream>


ScriptTank::ScriptTank(GameObject* parent):ComponentScript(parent)
{
	std::ifstream archivo(__FILE__);
	std::string str((std::istreambuf_iterator<char>(archivo)),
		std::istreambuf_iterator<char>());
	scriptText = str;
}

ScriptTank::~ScriptTank()
{

}

void ScriptTank::Enable()
{
	cannon = parent->children[0];
	


	LOG("Script tank enabled");
}

void ScriptTank::Update()
{
	if (bulletPool.size() == 0) {

		for (int i = 0; i < 10; i++)
		{
			ExternalApp->importer->ReadFile("Assets/Models/Primitives/Sphere.fbx");
			ExternalApp->importer->ReadFile("Assets/Textures/bulletTexture.png");
			GameObject* bulletRef = ExternalApp->scene->gameObjects.back()->Parent;
			bulletPool.push_back(bulletRef);

			bulletRef->transform->SetScale({ 0.2,0.2,0.2 });
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
		tankRotation += rotationTankSpeed * ExternalApp->DT();

	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) 
	{
		tankRotation -= rotationTankSpeed * ExternalApp->DT();
	}

	if (ExternalApp->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		actualPosition += parent->transform->GetForward() * moveSpeed * ExternalApp->DT();
	}
	else if (ExternalApp->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		actualPosition -= parent->transform->GetForward() * moveSpeed * ExternalApp->DT();
	}
	parent->transform->SetPosition(actualPosition);
	actualRotation.y += tankRotation;
	parent->transform->SetRotation(Quat::FromEulerXYZ(0.0f,tankRotation, 0.0f));

	//Cannon Movement
	
	float3 mousePosition;
	float3 tankPosition = parent->transform->GetPosition();

	mousePosition.x = ExternalApp->input->GetMouseX();
	mousePosition.y = ExternalApp->input->GetMouseY();

	tankPosition.x += 1050;
	tankPosition.y += 400;

	float3 cannonDirection = tankPosition - mousePosition;
	float angle = atan2(cannonDirection.x, cannonDirection.y);
	cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, angle, 0.0f));

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
				bulletRef->ShotBullet(cannon->transform->GetForward(), bulletSpeed, bulletLife);
				bulletTaken = true;
			}
		}
	}
}

void ScriptTank::Disable()
{
	for (int i = 0; i < bulletPool.size(); i++)
	{
		bulletPool[i]->Disable();
	}
	
	parent->transform->SetPosition({ 0.0f,0.0f,0.0f });
	parent->transform->SetRotation(Quat::FromEulerXYZ(0.0f, 0.0f, 0.0f));
	cannon->transform->SetRotation(Quat::FromEulerXYZ(0.0f, 0.0f, 0.0f));

	LOG("Script Tank disabled");
}

void ScriptTank::DrawInspector()
{

	if (ImGui::CollapsingHeader("Tank Script")) 
	{
		ImGui::PushItemWidth(50);
		ImGui::InputFloat("move Speed", &moveSpeed, 0.0F, 0.0F, "%.1f");
		ImGui::InputFloat("Tank Rotation Speed", &rotationTankSpeed, 0.0F, 0.0F, "%.1f");
		ImGui::InputFloat("Bullet Speed", &bulletSpeed, 0.0F, 0.0F, "%.1f");
		ImGui::InputFloat("Bullet Life", &bulletLife, 0.0F, 0.0F, "%.1f");
		ImGui::PopItemWidth();

		bulletSpeed = bulletSpeed < 10.0f ? 10.0f : bulletSpeed;
		moveSpeed = moveSpeed < 1.0f ? 1.0f : moveSpeed;
		rotationTankSpeed = rotationTankSpeed < 1.0f ? 1.0f : rotationTankSpeed;
		bulletLife = bulletLife < 1.0f ? 1.0f : bulletLife;


		ImGui::Text(scriptText.c_str());
	}


}
