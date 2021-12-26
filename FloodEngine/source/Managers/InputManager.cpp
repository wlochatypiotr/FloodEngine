#include "InputManager.h"


bool MInputManager::Keys[1024];
GLFWwindow * MInputManager::Window = nullptr;

MInputManager::MInputManager()
{
}

void MInputManager::KeyCallback(GLFWwindow * InWindow,const int Key, const int Scancode, const int Action, const int Mode)
{
	if (Key == GLFW_KEY_ESCAPE && Action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(Window, GL_TRUE);
	}

	if (Key >= 0 && Key < 1024)
	{
		if (Action == GLFW_PRESS)
		{

			Keys[Key] = true;
		}
		else if (Action == GLFW_RELEASE)
		{
			Keys[Key] = false;
		}
	}
}

void MInputManager::Initialize(GLFWwindow* InWindow)
{
	Window = InWindow;
	glfwSetKeyCallback(Window, MInputManager::KeyCallback);
	glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void MInputManager::ProcessInput()
{
	glfwPollEvents();
}

