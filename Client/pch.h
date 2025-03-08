#pragma once
//#define _WIN32_WINNT 0x0A00
//#define SFML_STATIC

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360
#define FRAME 60

#define SCALE 30.0f
#define SCALE_SIZE 2.0f / SCALE

#define TIME_STEP 1.0f / 60.0f
#define SUB_STEP_COUNT 2

//Library
#ifdef _DEBUG
#pragma comment(lib, "box2d-3.0.0\\build\\src\\Debug\\box2d.lib")

#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-main-s-d.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-graphics-d.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-window-d.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-system-d.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-audio-d.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-network-d.lib")
#else

#pragma comment(lib, "box2d-3.0.0\\build\\src\\Release\\box2d.lib")

#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-main-s.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-graphics.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-window.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-system.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-audio.lib")
#pragma comment(lib, "SFML-3.0.0\\lib\\sfml-network.lib")
#endif

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

using namespace std;