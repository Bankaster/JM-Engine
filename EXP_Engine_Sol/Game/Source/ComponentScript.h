#pragma once
#include "Component.h"
#include "Globals.h"
#include "ModuleImport.h"
#include "../External/MathGeoLib/include/MathGeoLib.h"

class ComponentScript : public Component
{
private:
	
	bool inGameMode = false;

public:
	ComponentScript(GameObject* parent);
	~ComponentScript();

	void Enable() override;
	void Update() override;
	void Disable() override;
	void DrawInspector() override;
	
	void setGameMode(bool b);

};
