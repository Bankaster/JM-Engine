#pragma once

// Warning disabled ---
#pragma warning( disable : 4577 ) // Warning that exceptions are disabled
#pragma warning( disable : 4530 )

#include <windows.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define CAP(n) ((n <= 0.0f) ? n=0.0f : (n >= 1.0f) ? n=1.0f : n=n)

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define PI 3.14159265358979323846264338327950288


typedef unsigned int uint;

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------
#define SCREEN_WIDTH 1720
#define SCREEN_HEIGHT 1024
#define SCREEN_SIZE 1
#define WIN_FULLSCREEN false
#define WIN_RESIZABLE true
#define WIN_BORDERLESS false
#define WIN_FULLSCREEN_DESKTOP false
#define VSYNC true
#define TITLE "JM Engine"

// Colors ------------
#define GREEN ImVec4(0.1f, 1.0f, 0.0f, 1.0f)
#define YELLOW ImVec4(1.0f, 1.0f, 0.0f, 1.0f)
#define PURPLE ImVec4(0.5f, 0.5f, 1.0f, 1.0f)
#define BLUE ImVec4(0.0f, 0.0f, 1.0f, 1.0f)
#define RED ImVec4(1.0f, 0.0f, 0.0f, 1.0f)
#define WHITE ImVec4(1.0f, 1.0f, 1.0f, 1.0f);


class Application;

#define RELEASE_ARRAY( x )	\
	{						\
		if( x != nullptr )	\
		{					\
           delete[] x;		\
	       x = nullptr;		\
		}					\
	}

