#pragma once
#include "glm/gtc/type_ptr.hpp"
#include "Managers/WindowManager.h"
#include "World.h"
using namespace glm;

class CRenderer
{
public:
	CRenderer();
	enum class EAttributeEnum
	{
		VERTEX_POS = 0,
		VERTEX_NORMAL = 1,
		TEXTURE_UV = 2
	};
	enum class EUniformEnum
	{
		MODEL_MATRIX_4X4 = 3,
		VIEW_MATRIX_4X4 = 4,
		PROJECTION_MATRIX_4X4 = 5,
		OBJECT_COLOR_VEC3 = 6,
		LIGHT_COLOR_VEC3 = 7,
		LIGHT_POS_VEC3 = 8,
		CAMERA_POS_VEC3 = 9
	};

	void Initialize(const Shader& InShader, MWindowManager* InWinManager, const int FPSLimit = 0);
	void SetViewMatrix(const mat4& InViewMatrix);
	void SetProjectionMatrix(const mat4& InProjectionMatrix);
	void SetProgram(const Shader& InShader);

	void Draw(const CEntity* InEntity) const;
	void Draw(const CWorld* InWorld);
	void Draw(CScene * scene) const;
	void EnableTexturing(bool flag);
	void ClearBuffer();
	void SwapBuffer();
private:
	//overloads on DrawComponent
	void DrawComponent(const CECVisualMesh* MeshComponent) const;
	bool bIsTexturingEnabled = true;
	//void DrawComponent(Model& model);
	mat4 ViewMatrix;// = nullptr;
	mat4 ProjectionMatrix;// = nullptr;
	Shader DefaultShader;
	MWindowManager* WindowManager;
};