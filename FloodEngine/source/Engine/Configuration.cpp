#include "Configuration.h"


//unsigned CoreGlobals::GThreadsNum;

//ShaderManager Configuration::m_shaders;
//CInputManager Configuration::m_inputManager;

//glm::mat4 CoreGlobals::GViewMatrix = glm::mat4();
//glm::mat4 CoreGlobals::GProjectionMatrix = glm::mat4();
//glm::mat4 CoreGlobals::GBoardModelMatrix = glm::mat4();
//glm::mat4 CoreGlobals::GLampModelMatrix = glm::mat4();
//
//glm::vec3 CoreGlobals::GBoardColor;
//glm::vec3 CoreGlobals::GLightColor;
//
//glm::vec3 CoreGlobals::GLightPosition;
//
//GLuint CoreGlobals::GScreenHeight;
//GLuint CoreGlobals::GScreenWidth;




//bool Configuration::m_keys[1024];

//GLFWwindow* CoreGlobals::GWindow = nullptr;

//void Configuration::Initialize()
//{
//	CoreGlobals::GThreadsNum = std::thread::hardware_concurrency();
//
//	//InitializeGLFW();
//	//InitializeInputManager();
//	InitializeColors();
//	InitializeMarices();
//	//InitializeOpenGL();
//	//InitializeShaders();
//}

//void Configuration::InitializeShaders()
//{
//	m_shaders.Load(Configuration::EShaderType::LAMP_SHADER, Shader ("shaders/VS.frag", "shaders/LampShader.frag"));
//	m_shaders.Load(Configuration::EShaderType::TABLE_SHADER, Shader ("shaders/VS.frag", "shaders/FS.frag"));
//}

//void Configuration::InitializeMarices()
//{
	//m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -2.6f));
	//m_view = glm::rotate(m_view, glm::radians(35.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//m_projection = glm::perspective(glm::radians(45.0f), (GLfloat)1366 / (GLfloat)768, 0.1f, 100.0f);

	//m_boardModel = glm::rotate(m_boardModel, glm::radians(135.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//m_boardModel = glm::translate(m_boardModel, glm::vec3(0.0f, -50.0f, 5.0f));

	//m_boardModel = glm::rotate(m_boardModel, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//m_boardModel = glm::translate(m_boardModel, glm::vec3(0.0f, -1.0f, -1.40f));
	//m_boardModel = glm::scale(m_boardModel, glm::vec3(1.0f, 1.0f, 1.0f));

	//m_lampModel = glm::scale(m_lampModel, glm::vec3(0.5f, 0.5f, 0.5f));
	//m_lampModel = glm::translate(m_lampModel, m_lightPosition);
	//m_lampModel = glm::rotate(m_lampModel, glm::radians(95.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//}
//
//void Configuration::InitializeColors()
//{
//	CoreGlobals::GBoardColor = glm::vec3 (0.902, 0.902, 0.980);
//	CoreGlobals::GLightColor = glm::vec3 (1.0f, 1.0f, 1.0f);
//
//	//positions
//	CoreGlobals::GLightPosition = glm::vec3(0.0f, 1.0f, -5.0f);
//
//}

//void Configuration::InitializeGLFW()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	glewExperimental = GL_TRUE;
//
//	//windows setup
//	CoreGlobals::GScreenWidth = 1366;
//	CoreGlobals::GScreenHeight = 768;
//	CoreGlobals::GWindow = glfwCreateWindow(CoreGlobals::GScreenWidth, CoreGlobals::GScreenHeight, "PoolDozer", nullptr, nullptr);
//	glfwMakeContextCurrent(CoreGlobals::GWindow);
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Failed to initialize GLEW" << std::endl;
//		//return -1;
//		//throw some exception ?
//	}
//}

//void Configuration::InitializeInputManager()
//{
//	m_inputManager.m_window = CoreGlobals::GWindow;
//	glfwSetKeyCallback(CoreGlobals::GWindow, m_inputManager.KeyCallback);
//	glfwSetInputMode(CoreGlobals::GWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//}

//void Configuration::InitializeOpenGL()
//{
//	glViewport(0, 0, 1366, 768);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glDisable(GL_TEXTURE_2D);
//}

//void Configuration::KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	if (key >= 0 && key < 1024)
//	{
//		if (action == GLFW_PRESS)
//			m_keys[key] = true;
//		else if (action == GLFW_RELEASE)
//			m_keys[key] = false;
//	}
//}
