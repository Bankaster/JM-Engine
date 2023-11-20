#pragma once
#ifndef MODULE_EDITOR
#define MODUEL_EDITOR

#include <string>

#include "Module.h"
#include "Globals.h"
#include <vector>

#define YELLOW ImVec4(1.0f, 1.0f, 0.0f, 1.0f)
class GameObject;

class ModuleEditor : public Module
{
public:

	ModuleEditor(Application* app, bool start_enabled = true);
	~ModuleEditor();

	bool Init() override;
	void DrawEditor();
	bool CleanUp() override;

	void Config();
	void MainMenuBar();
	void DemoWindow();

	void DrawInspector();
	void DrawHierarchy();
	void Inspector();
	void HierarchyWindow(GameObject* gameObject);

	void RequestBrowser(const char* path);

	/*void AddFPS(const float aFPS);*/

	std::vector<std::string> log_history;
	float aFPS;

	void UpdateFPS(const float aFPS);
	void ModuleEditor::Console();

	char label[32];

	bool show_console_window = true;
	
	bool show_demo_window = false;
	bool show_metrics_window = false;
	bool show_config_window = true;
	bool show_hierarchy_window = true;
	bool show_inspector_window = true;
	bool show_console = true;

	bool drawAll = true;
	bool drawAllFaces = false;
	bool drawAllVertex = false;
	bool drawTextures = true;

	bool top = false;
	bool front = false;
	bool side_1 = false;
	bool side_2 = false;

	bool shader = true;
	bool cullface = true;

	bool drawSelected = true;
	bool drawSelectedVertex = false;
	bool drawSelectedFaces = false;
	bool drawSelectedTexture = true;

	//Public variable to know which model is selected
	int posOfSelected = -1;

	bool openTreeNode = false;

	bool Wireframe = false;
	bool lights = true;

	bool fullscreen = false;
	bool borderless = false;

};

#endif //MODULE_EDITOR