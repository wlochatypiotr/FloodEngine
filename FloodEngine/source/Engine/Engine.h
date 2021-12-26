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

class Engine
{
public:
	Engine();
	~Engine();
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;

	bool Initialize();
	void Shutdown();
	double GetCurrentTime() const;
	double GetDeltaTime() const;
	void TickClock();
	void SetFrameLimit(int FPSLimit);
	bool ShouldDrawNextFrame();

	MWindowManager* GetWindowManager() const { return WindowManager.get();  }
	MInputManager* GetInputManager() const { return InputManager.get(); }
	MShaderManager* GetShaderManager() const { return ShaderManager.get(); }
	MModelManager* GetMeshManager() const { return MeshManager.get(); }
	MComponentManager* GetComponentManager() const { return ComponentManager.get(); }

	CRenderer* GetRenderer() const { return Renderer.get(); }
	CWorld* GetWorld() const { return World.get(); }

private:
	std::unique_ptr<MWindowManager> WindowManager;
	std::unique_ptr<MInputManager> InputManager;
	std::unique_ptr<MShaderManager> ShaderManager;
	std::unique_ptr<MModelManager> MeshManager;
	std::unique_ptr<MComponentManager> ComponentManager;
	//std::unique_ptr<CPhysXWorld> m_physXWorld;

	std::unique_ptr<CRenderer> Renderer;
	std::unique_ptr<CWorld> World;

	double LastFrame = 0;
	double CurrentFrame = 0;
	int FrameLimit = 0;
	double FrameLimitAccumulator;
};

