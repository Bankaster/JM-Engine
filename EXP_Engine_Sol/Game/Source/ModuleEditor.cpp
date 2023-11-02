#include "Application.h"
#include "ModuleEditor.h"
#include "ModuleWindow.h"
#include "ModuleRenderer3D.h"
#include "ModuleInput.h"

#include "../External/ImGui/imgui.h"
#include "../External/ImGui/backends/imgui_impl_opengl3.h"
#include "../External/ImGui/backends/imgui_impl_sdl2.h"

#include "../External/Glew/include/glew.h"
#include "../External/SDL/include/SDL_opengl.h"

#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#pragma comment (lib, "glu32.lib") /* link Microsoft OpenGL lib   */
#pragma comment (lib, "Game/External/Glew/libx86/glew32.lib")

ModuleEditor::ModuleEditor(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

// Destructor
ModuleEditor::~ModuleEditor ()
{
}

// Called before render is available
bool ModuleEditor::Init()
{
	bool ret = true;
	App->mFPSLog.reserve(30);

	//// Setup Dear ImGui context
	//IMGUI_CHECKVERSION();
	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO(); (void)io;
	//ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	//// Setup Dear ImGui style
	//ImGui::StyleColorsDark();
	////ImGui::StyleColorsClassic();

	//// Setup Platform/Renderer backends
	//ImGui_ImplSDL2_InitForOpenGL(App->window->window, context);
	//ImGui_ImplOpenGL3_Init("#version 130");
	return ret;
}

void ModuleEditor :: DrawEditor()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::DockSpaceOverViewport(NULL, ImGuiDockNodeFlags_PassthruCentralNode);

	aFPS = App->FPS();

	UpdateFPS(aFPS);

	MainMenuBar();

	if (show_demo_window) {
		ImGui::ShowDemoWindow(&show_demo_window);
	}

	if (show_metrics_window) {
		ImGui::ShowMetricsWindow(&show_metrics_window);
	}

	Config();
	Console();

	ImGuiIO& io = ImGui::GetIO(); (void)io;


	// Rendering
	ImGui::Render();
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
 
}

// Called before quitting
bool ModuleEditor::CleanUp()
{
	//// Cleanup
	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplSDL2_Shutdown();
	//ImGui::DestroyContext();

	//SDL_GL_DeleteContext(context);
	return true;
}

void ModuleEditor::UpdateFPS(const float aFPS)
{
	if (App->mFPSLog.size() < 30)
	{
		App->mFPSLog.push_back(aFPS);
	}
	else
	{
		for (unsigned int i = 0; i < App->mFPSLog.size(); i++)
		{
			if (i + 1 < App->mFPSLog.size())
			{
				float copy = App->mFPSLog[i + 1];
				App->mFPSLog[i] = copy;
			}
		}
		App->mFPSLog[App->mFPSLog.capacity() - 1] = aFPS;
	}
}

void ModuleEditor::MainMenuBar() {
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Quit")) {
				
				App->input->quit = true;
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Window"))
		{
			if (ImGui::MenuItem("Configuration")) {
				show_config_window = !show_config_window;
			}
			if (ImGui::MenuItem("Demo Window")) {
				show_demo_window = !show_demo_window;
			}
			if (ImGui::MenuItem("Metrics Window")) {
				show_metrics_window = !show_metrics_window;
			}
			if (ImGui::MenuItem("Hierarchy")) {
				show_hierarchy_window = !show_hierarchy_window;
			}
			if (ImGui::MenuItem("Inspector")) {
				show_inspector_window = !show_inspector_window;
			}
			if (ImGui::MenuItem("Console")) {
				show_console = !show_console;
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("About"))
		{
			ImGui::Text("DaTo Engine by Dani Mariages & Toni Romanos");
			sprintf(label, "Github Repository");
			if (ImGui::Selectable(label, true))	RequestBrowser("https://github.com/DaniMariages/Motors");
			ImGui::EndMenu();
		}


		ImGui::EndMainMenuBar();
	}
}

void ModuleEditor::RequestBrowser(const char* path)
{
	ShellExecuteA(0, "Open", path, 0, "", 5);
}

void ModuleEditor::Config() {
	
	ImGuiStyle& style = ImGui::GetStyle();

	if (show_config_window)
	{
		ImGui::Begin("Configuration", &show_config_window, ImGuiWindowFlags_DockNodeHost);
		if (ImGui::CollapsingHeader("Display"))
		{
			if (ImGui::Checkbox("Fullscreen", &fullscreen)) {
				App->window->FullScreen(fullscreen);
			}
			if (ImGui::Checkbox("Borderless", &borderless)) {
				App->window->Borderless(borderless);
			}
		}
		if (ImGui::CollapsingHeader("Hardware"))
		{
			//Display current hardware and driver capabilities

			ImGui::Text("Using Glew:");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%s", glewGetString(GLEW_VERSION));

			ImGui::Text("Vendor: ");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%s", glGetString(GL_VENDOR));

			ImGui::Text("Renderer: ");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%s", glGetString(GL_RENDERER));

			ImGui::Text("OpenGL version supported: ");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%s", glGetString(GL_VERSION));

			ImGui::Text("GLSL: ");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%s", glGetString(GL_SHADING_LANGUAGE_VERSION));
		}
		if (ImGui::CollapsingHeader("Framerate"))
		{
			ImGui::PlotHistogram("##FPS", &App->mFPSLog[0], App->mFPSLog.size(), 0, "", 0.0f, 100.0f, ImVec2(300, 100));
		}
		if (ImGui::CollapsingHeader("Draw Settings"))
		{
			if (ImGui::Checkbox("Draw", &drawAll)) {
			}
			if (ImGui::Checkbox("Normals", &drawAllFaces)) {
			}
			if (ImGui::Checkbox("Vertex", &drawAllVertex)) {
			}			
			if (ImGui::Checkbox("Textures", &drawTextures)) {
			}
			
		}
		if (ImGui::CollapsingHeader("View"))
		{
			if (ImGui::Checkbox("Top", &top)) {
			}
			if (ImGui::Checkbox("Front", &front)) {
			}
			if (ImGui::Checkbox("Left side", &side_1)) {
			}
			if (ImGui::Checkbox("Right side", &side_2)) {
			}
		}
		if(ImGui::CollapsingHeader("Renderer")) {
			if (ImGui::Checkbox("Shader", &shader)) {
				if (shader) {
					glEnable(GL_LIGHTING);
				}				
				else {
					glDisable(GL_LIGHTING);
				}
			}
			if (ImGui::Checkbox("Cull face", &cullface)) {
				if (cullface) {
					glEnable(GL_CULL_FACE);
				}
				else {
					glDisable(GL_CULL_FACE);
				}
			}
		}
		if (show_hierarchy_window)
		{
			ImGui::Begin("Hierarchy", &show_hierarchy_window);
			static int seleccion = -1;
			for (int i = 0; i < App->renderer3D->gameObjects.size(); i++)
			{
				if (ImGui::Selectable(App->renderer3D->gameObjects[i]->Name.c_str(), seleccion == i))
				{
					show_inspector_window = !show_inspector_window;
				}
				ImGui::Text("%d", i);
			}
			ImGui::End();
		}

		ImGui::End();
	}
}

void ModuleEditor::Console()
{
	ImGuiStyle& style = ImGui::GetStyle();

	if (show_console) {
		ImGui::Begin("Console", &show_console);

		for (int i = 0; i < log_history.size(); i++)
		{
			ImGui::Text("%s", log_history[i].c_str());
		}
		ImGui::End();
	}
}