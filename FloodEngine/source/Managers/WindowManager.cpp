#include "WindowManager.h"



MWindowManager::MWindowManager()
{
}


MWindowManager::~MWindowManager()
{
}

void MWindowManager::Initialize(int majorVersion, int minorVersion, int screenWidth, int screenHeight)
{

	printf("Initializing GLFW version %s \n", glfwGetVersionString());
	printf("Using OpenGL version %s", glGetString(GL_VERSION));
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glewExperimental = GL_TRUE;
	//windows setup
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, "PoolDozer", nullptr, nullptr);
	glfwMakeContextCurrent(m_window);
	if (glewInit() == GLEW_OK)
	{
		printf("Failed to initialize GLEW");
	}
	else
	{
		printf("Successfully created GLFW window %d x %d", m_screenWidth, m_screenHeight);
	}

}

void MWindowManager::ShutDown()
{
	glfwTerminate();
}

