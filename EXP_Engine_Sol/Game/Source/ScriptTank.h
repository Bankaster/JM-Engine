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

	float moveSpeed = 8.0f;
	float rotationCannonSpeed = 3.0f;
	float rotationTankSpeed = 3.0f;
	
private:

	GameObject* cannon;
	bool cannonActive = false;
	int actualMousePosition;
	float tankRotation = 0.0f;
	float cannonRotation = 0.0f;
	std::vector <GameObject*> bulletPool;

};