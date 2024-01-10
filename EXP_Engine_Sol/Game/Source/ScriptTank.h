#pragma once
#include "ComponentScript.h"
#include "Globals.h"
#include "ModuleImport.h"
#include "../External/MathGeoLib/include/MathGeoLib.h"

class ScriptTank : public ComponentScript
{
public:
	ScriptTank(GameObject* parent);
	~ScriptTank();

	void Enable() override;
	void Update() override;
	void Disable() override;
	void DrawInspector() override;

	float moveSpeed = 1.0f;

};