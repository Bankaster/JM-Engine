#pragma once
#include "ComponentScript.h"
#include "Globals.h"
#include "ModuleImport.h"
#include "../External/MathGeoLib/include/MathGeoLib.h"

class Bullet : public ComponentScript 
{
public:
	Bullet(GameObject* parent);
	~Bullet();

	void Enable() override;
	void Update() override;
	void Disable() override;
	void DrawInspector() override;

	void ShotBullet(float3 dir, float speed, float time);
	

private:

	float lifeTimeCounter;
	float3 bulletDirection;
	float bulletSpeed;

};