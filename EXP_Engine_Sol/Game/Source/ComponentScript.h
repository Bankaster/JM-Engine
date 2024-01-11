#pragma once
#include "Component.h"
#include "Globals.h"
#include "ModuleImport.h"
#include "../External/MathGeoLib/include/MathGeoLib.h"

class ComponentScript : public Component
{

public:
	ComponentScript(GameObject* parent);
	~ComponentScript();

	void Enable() override = 0;
	void Update() override = 0;
	void Disable() override = 0;
	void DrawInspector() override = 0;

};
