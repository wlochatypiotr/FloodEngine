#pragma once
#include "EntityComponent.h"
#include <map>


using namespace glm;
class CRenderer;
using EntityIDType = std::string;


struct STransform {
	vec3 Position;
	vec3 Rotation; // x, y, z rotations
	vec3 Scale;

	STransform() = default;

	STransform(const STransform& RHS)
	{
		Position = RHS.Position;
		Rotation = RHS.Rotation;
		Scale = RHS.Scale;
	}
};

class CEntity
{
	friend class CScene;
public:
	using EntityIDType = std::string;

	CEntity(const EntityIDType& ID, const bool IsVisible = true, const bool IsActive = true);
	//hoe copy c should work ?!
	CEntity(const CEntity& RHS);

	const STransform& GetTransform() const;
	void SetTransform(const STransform& InTransform);
	void SetPosition(const vec3& InPos);
	void SetRotation(const vec3& InRotation);
	void SetRotation(const float X, const float Y, const float Z);
	void SetScale(const vec3& InScale);
	void SetScale(const float InUniformScale);
	vec3 GetScale3D() const;
	EntityIDType GetID() const;
	void SetID(const EntityIDType& InID);

	bool ShouldBeVisible() const { return bIsVisible; }
	void SetVisible(const bool InFlag) { bIsVisible = InFlag; }

	//void SetActive(bool activationState);

	bool ShouldBeActive() const { return bIsActive; }
	void SetActive(const bool InFlag) { bIsActive = InFlag; }

	//This function will update all Entity components
	//TODO: 
	//add time as argument for use of some components
	void Update();

	const CEntityComponent* GetEntityComponent(const EntityComponentIDType& InFamilyID) const;
	CEntityComponent* SetEntityComponent(CEntityComponent* NewEntityComponent);
	void ClearComponents();

private:
	STransform Transform;
	EntityIDType EntityID;
	bool bIsVisible;
	bool bIsActive;

	//for CEntity copy constructor
	//TODO: unused
	static int m_counter;

	using ComponentTableType = std::map<const EntityComponentIDType, CEntityComponent*>;
	ComponentTableType Components; //map of all the components;
};
