#pragma once
#include "Loaders/Model.h"
#include "Loaders/ShaderLoader.h"
#include "glm/gtc/matrix_transform.hpp"

using EntityComponentIDType = std::string;
class CEntity;

enum class EComponentTypeEnum {
	MESH_COMPONENT = 0,
	SPHERE_COMPONENT = 1,
	PHYSIC_COMPONET = 2
};

class CEntityComponent
{
public:
	CEntityComponent() : Owner(nullptr) {}
	virtual ~CEntityComponent()  {}

	virtual const EntityComponentIDType ComponentID() const = 0;
	virtual const EntityComponentIDType FamilyID() const = 0;

	virtual void Update() = 0;

	//what if multiple objects have same component ?
	void SetOwningEntity(CEntity* InEntity) { Owner = InEntity; }
	CEntity* GetOwner() const { return Owner; }

private:
	CEntity* Owner; //Entity of which this component is member of
};

//Base class for visual Entity Components
class CECVisual : public CEntityComponent
{
	//common interface
public:
	//virtual ~CECVisual() {}
	virtual const EntityComponentIDType FamilyID() const override
	{
		return EntityComponentIDType("ECVisual");
	}
	virtual void Update() override;


	void SetColor(const float R, const float G, const float B);
	void SetProgram(const Shader& InShaderProgram);
	glm::vec3 ColorVector;
	glm::mat4 ModelMatrix;
	Shader* ShaderProgram = nullptr;

};

//Spherical entity visual component
class CECVisualSphere : public CECVisual
{
public:
	virtual const EntityComponentIDType ComponentID() const
	{
		return EntityComponentIDType("ECVisualSphere");
	}

	CECVisualSphere(/*float radius*/);

	float GetRadius() const { return Radius; }
	void SetRadius(const float InRadius) { Radius = InRadius; }

private:
	float Radius;
};

class CECVisualMesh : public CECVisual
{
public:
	virtual const EntityComponentIDType ComponentID() const
	{
		return EntityComponentIDType("ECVisualMesh");
	}

	void SetMesh(CModel* meshptr);
	CModel* GetModel();
	const CModel* GetModel() const;
private:
	CModel* ModelMesh;
};