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



