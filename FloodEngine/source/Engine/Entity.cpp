#include "Entity.h"

int CEntity::m_counter = 1;

CEntity::CEntity(const EntityIDType & ID, const bool InIsVisible, const bool InIsActive)
{
	EntityID = ID;
	bIsVisible = InIsVisible;
	bIsActive = InIsActive;
}

CEntity::CEntity(const CEntity& RHS)
{
	Transform = RHS.Transform;
	EntityID = RHS.EntityID;
	bIsVisible = RHS.bIsVisible;
	bIsActive = RHS.bIsActive;
	Components = RHS.Components;
}

const STransform& CEntity::GetTransform() const
{
	return Transform;
}

void CEntity::SetTransform(const STransform& InTransform)
{
	Transform = InTransform;
}

void CEntity::SetPosition(const vec3& InPos)
{
	Transform.Position = InPos;
}

void CEntity::SetRotation(const vec3& InRotation)
{
	Transform.Rotation = InRotation;
}

void CEntity::SetRotation(const float X, const float Y, const float Z)
{
	Transform.Rotation.x = X;
	Transform.Rotation.y = Y;
	Transform.Rotation.z = Z;
}

void CEntity::SetScale(const vec3& InScale)
{
	Transform.Scale = InScale;
}

void CEntity::SetScale(const float InUniformScale)
{
	Transform.Scale.x = InUniformScale;
	Transform.Scale.y = InUniformScale;
	Transform.Scale.z = InUniformScale;
}

vec3 CEntity::GetScale3D() const
{
	return Transform.Scale;
}

EntityIDType CEntity::GetID() const
{
	return EntityID;
}

void CEntity::SetID(const EntityIDType& InID)
{
	EntityID = InID;
}


void CEntity::Update()
{
	if (!bIsActive)
	{
		return;
	}

	for (auto it = Components.begin(); it != Components.end(); ++it)
	{
		it->second->Update();
	}
}

//returns nullptr if there is no such component
const CEntityComponent * CEntity::GetEntityComponent(const EntityComponentIDType& InFamilyID) const
{
	const auto SearchResult = Components.find(InFamilyID);
	if (SearchResult == Components.end())
	{
		return nullptr;
	}
	else
	{
		return SearchResult->second;
	}
}

//set component in entity to passed component, if such component already exists
//replace it with new component and return pointer to replaced component
CEntityComponent * CEntity::SetEntityComponent(CEntityComponent* NewEntityComponent)
{
	auto const SearchResult = Components.find(NewEntityComponent->FamilyID());

	if (SearchResult != Components.end())
	{
		CEntityComponent* CurrComponent = SearchResult->second;
		CurrComponent->SetOwningEntity(nullptr);
		NewEntityComponent->SetOwningEntity(this);
		SearchResult->second = NewEntityComponent;
		return CurrComponent;
	}
	else
	{
		NewEntityComponent->SetOwningEntity(this);
		auto CreatedComponent = Components.emplace(std::make_pair(NewEntityComponent->FamilyID(), NewEntityComponent));
		return CreatedComponent.first->second;
	}
}

void CEntity::ClearComponents()
{
	Components.clear();
}
