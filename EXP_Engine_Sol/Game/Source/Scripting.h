#pragma once
#include "Module.h"

class Scripting : public Module
{
private:
	bool enabled;

public:

	Scripting(Application* parent, bool start_enabled = true);
	~Scripting();

	bool Init();
	bool Start();
	update_status Update(float dt);
	bool CleanUp();


};