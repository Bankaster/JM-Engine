#include "Bullet.h"

Bullet::Bullet(GameObject* parent):ComponentScript(parent)
{

}

Bullet::~Bullet()
{
}

void Bullet::Enable()
{
}

void Bullet::Update()
{

	if (lifeTimeCounter >= 0.0f) 
	{
		float3 actualParent = parent->transform->GetPosition();

		lifeTimeCounter -= ExternalApp->DT();
		parent->transform->SetPosition(actualParent + (bulletDirection * bulletSpeed));

	}
	else 
	{
		parent->Disable();
		parent->children[0]->Disable();
	}

	LOG("Hola soc una bala");

}

void Bullet::Disable()
{
}

void Bullet::DrawInspector()
{
}

void Bullet::ShotBullet(float3 dir, float speed, float time)
{

	lifeTimeCounter = time;
	bulletDirection = dir.Normalized();
	bulletSpeed = speed;

}