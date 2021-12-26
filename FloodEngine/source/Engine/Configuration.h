//#pragma once
//#include "Loaders/ShaderLoader.h" // add GL/glew
//#include "Managers/InputManager.h"	//add GLFW order here matters
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include <thread>
//#include "Managers/ShaderManager.h"
//#include "Managers/InputManager.h"

//using uint = unsigned int;

//class Config
//{
//	Config(int GLMajorVer, int GLMinorVer, uint SreenX, uint ScreenY, uint ThreadsNum) :
//	OpenGLMajorVer(GLMajorVer),
//	OpenGLMinorVer(GLMinorVer),
//	ScreenWidth(SreenX),
//	ScreenHeight(ScreenY),
//	ProcessThreads(ThreadsNum)
//	{}
//
//
//	const int OpenGLMajorVer;
//	const int OpenGLMinorVer;
//	const uint ScreenWidth;
//	const uint ScreenHeight;
//	const uint ProcessThreads;
//};

//namespace CoreGlobals
//{
//	static GLuint GScreenWidth;
//	static GLuint GScreenHeight;
//	static GLFWwindow* GWindow;
//
//	//matrices
//	static glm::mat4 GViewMatrix;
//	static glm::mat4 GProjectionMatrix;
//
//	static glm::mat4 GBoardModelMatrix;
//	static glm::mat4 GLampModelMatrix;
//
//	static glm::vec3 GBoardColor;
//	static glm::vec3 GLightColor;
//
//	static glm::vec3 GLightPosition;
//
//	static unsigned int GThreadsNum;
//};

//enum class EShaderType : uint8_t
//{
//	LAMP_SHADER,
//	TABLE_SHADER
//};

//class Configuration
//{
//public:
//	Configuration() = delete;
//	Configuration(const Configuration&) = delete;
//	Configuration& operator=(const Configuration&) = delete;

	//managers /TODo: move somewhere else - engine ?
	//static ShaderManager m_shaders;
	//static CInputManager m_inputManager;

	//enum m_vertexAttributes {
	//	VERTEX_POSITION = 0,
	//	VERTEX_NORMAL = 1,
	//	MODEL_MATRIX = 3,
	//	VIEW_MATRIX = 4,
	//	PROJECTION_MATRIX = 5,
	//	OBJECT_COLOR = 6,
	//	LIGHT_COLOR = 7,
	//	LIGHT_SOURCE_POS = 8
	//};

	//static void Initialize();
	//static void InitializeShaders();
	//static void InitializeMarices();
	//static void InitializeColors();
	//static void InitializeGLFW();
	//static void InitializeInputManager();
	//static void InitializeOpenGL();

	//static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

	//static bool m_keys[1024];
//};