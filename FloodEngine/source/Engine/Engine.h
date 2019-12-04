#pragma once
#include "Managers/ShaderManager.h"
#include "Managers/WindowManager.h"
#include "Managers/InputManager.h"
#include "Managers/ShaderManager.h"
#include "Managers/MeshManager.h"
#include "Managers/ComponentManager.h"
#include "World.h"
#include "Renderer.h"
#include "PhysXWorld.h"
#include <memory>

class CEngine
{
public:
	CEngine();
	~CEngine();
	CEngine(const CEngine&) = delete;
	CEngine& operator=(const CEngine&) = delete;
	bool StartUp();
	void ShutDown();
	double GetCurrentTime();
	double GetDeltaTime();
	void TickClock();
	void SetFrameLimit(int FPSLimit);
	bool ShouldDrawNextFrame();
	CWindowManager * GetWindowManager() const { return m_windowManager.get();  }
	CInputManager * GetInputManager() const { return m_inputManager.get(); }
	CShaderManager * GetShaderManager() const { return m_shaderManager.get(); }
	CModelManager * GetMeshManager() const { return m_meshManager.get(); }
	CRenderer * GetRenderer() const { return m_renderer.get(); }
	CComponentManager * GetComponentManager() const { return m_componentManager.get(); }
	CWorld * GetWorld() const { return m_world.get(); }

private:
	std::unique_ptr<CWindowManager> m_windowManager;
	std::unique_ptr<CInputManager> m_inputManager;
	std::unique_ptr<CShaderManager> m_shaderManager;
	std::unique_ptr<CRenderer> m_renderer;
	std::unique_ptr<CModelManager> m_meshManager;
	std::unique_ptr<CComponentManager> m_componentManager;
	//std::unique_ptr<CPhysXWorld> m_physXWorld;
	std::unique_ptr<CWorld> m_world;

	double LastFrame = 0;
	double CurrentFrame = 0;
	int FrameLimit = 0;
	double FrameLimitAccumulator;
};
