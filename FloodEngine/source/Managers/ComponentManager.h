#pragma once
#include <unordered_map>
#include <memory>
#include "Engine/EntityComponent.h"

class MComponentManager
{
public:
	MComponentManager();
	~MComponentManager();

	MComponentManager(const MComponentManager&) = delete;
	MComponentManager(MComponentManager&&) = delete;
	MComponentManager& operator=(const MComponentManager&) = delete;
	MComponentManager& operator=(CEntityComponent&&) = delete;

	void Initialize();
	void AddComponent(const EntityComponentIDType& ID, EComponentTypeEnum Type);
	CEntityComponent* GetComponent(const EntityComponentIDType& ID) const;

private:
	std::unordered_map <EntityComponentIDType, std::unique_ptr<CEntityComponent> > Components;
};

