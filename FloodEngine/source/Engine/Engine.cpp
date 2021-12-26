#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
	//1
	//init windowManager
	GLuint bGLSuccess = glGetError();
	WindowManager = std::make_unique<MWindowManager>();
	WindowManager->Initialize(3, 3, 1920, 1080);
	bGLSuccess = glGetError();
	//2
	//init input manager - move to initialize
	InputManager = std::make_unique<MInputManager>();
	InputManager->Initialize(WindowManager->GetWindow());
	bGLSuccess = glGetError();
	//3
	//init shader mgr and load shaders in Initialize method
	ShaderManager = std::make_unique<MShaderManager>();
	ShaderManager->Initialize();
	//4
	//init MeshManager and load some meshes
	MeshManager = std::make_unique<MModelManager>();
	MeshManager->Initialize();

	//5
	ComponentManager = std::make_unique<MComponentManager>();
	//loadcomponents
	//m_componentManager->Initialize();

	//6
	//init Renderer with s default shader
	Renderer = std::make_unique<CRenderer>();
	Renderer->Initialize(ShaderManager->Get(ShaderManager->EShaderType::TABLE_SHADER), this->GetWindowManager());
	//7

	//Initialzie PhysX engine
	//m_physXWorld = std::make_unique<CPhysXWorld>();
	//m_physXWorld->StartUp();	
	//8 
	//Init world
	World = std::make_unique<CWorld>();
	World->Initialize(GetComponentManager());

	return false;
}

void Engine::Shutdown()
{
	//8
	//shutdown world

	//7
	//m_physXWorld->ShutDown();

	//6
	//m_renderer->ShutDown();

	//5
	//m_componentManager->ShutDown();

	//4
	MeshManager->ShutDown();

	//3
	//m_shaderManager->ShutDown();

	//2
	//m_inputManager->ShutDown();

	//1
	WindowManager->ShutDown();
}

double Engine::GetCurrentTime() const
{
	return glfwGetTime();
}

double Engine::GetDeltaTime() const
{
	return CurrentFrame - LastFrame;
}

void Engine::TickClock()
{
	LastFrame = CurrentFrame;
	CurrentFrame = GetCurrentTime();
	if (FrameLimit != 0)
	{
		FrameLimitAccumulator += GetDeltaTime();
	}
}

void Engine::SetFrameLimit(int FPSLimit)
{
	FrameLimit = FPSLimit;
}

bool Engine::ShouldDrawNextFrame()
{
	//FramLimit = 0 equals no limit
	if (FrameLimit == 0)
	{
		return true;
	}
	else
	{
		double MaxFrameTime = 1.0 / FrameLimit;
		if (FrameLimitAccumulator > MaxFrameTime)
		{
			FrameLimitAccumulator -= MaxFrameTime;
			return true;
		}
		else
		{
			return false;
		}
	}
}
