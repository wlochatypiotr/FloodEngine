#pragma once
#include "GLFW/glfw3.h"


class MInputManager
{
public:
	MInputManager();

	MInputManager(const MInputManager &) = delete;
	MInputManager(MInputManager&&) = delete;
	MInputManager& operator=(const MInputManager &) = delete;
	MInputManager& operator=(MInputManager&&) = delete;

	static void KeyCallback(GLFWwindow * InWindow, const int Key, const int Scancode, const int Action, const int Mode);
	void Initialize(GLFWwindow* InWindow);
	void SetupKeyCallback();
	static void ProcessInput();
	static bool Keys[1024];
	static GLFWwindow * Window;
};