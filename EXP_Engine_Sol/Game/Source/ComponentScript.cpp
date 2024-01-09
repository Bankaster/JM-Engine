#pragma once
#include "ComponentScript.h"
#include "GameObject.h"
#include "../External/ImGui/imgui.h"
#include <string>

ComponentScript::ComponentScript(GameObject* parent) : Component(parent)
{
	type = typeComponent::Scripts;
}

ComponentScript::~ComponentScript()
{
}

void ComponentScript::Enable()
{
	inGameMode = true;
}

void ComponentScript::Update() 
{
	if (!inGameMode) {
		return;
	}
	LOG("Component Script update");
	parent->transform->SetPosition({ 10,10,0 });
}

void ComponentScript::Disable()
{
	inGameMode = false;
}

void ComponentScript::DrawInspector()
{

}

void ComponentScript::setGameMode(bool b)
{

	if (b == true) {
		Enable();
	}
	else {
		Disable();
	}

}
