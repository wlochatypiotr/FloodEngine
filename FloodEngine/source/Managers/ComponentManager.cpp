#include "ComponentManager.h"



MComponentManager::MComponentManager()
{
}


MComponentManager::~MComponentManager()
{
}

void MComponentManager::Initialize()
{

}

void MComponentManager::AddComponent(const EntityComponentIDType & ID, EComponentTypeEnum Type)
{
	std::unique_ptr<CEntityComponent> Component;// = std::make_unique<CECVisualMesh>();
												//m_components.emplace(id, std::move(component));

	switch (Type)
	{
	case EComponentTypeEnum::MESH_COMPONENT:
		Component = std::make_unique<CECVisualMesh>();
		Components.emplace(ID, std::move(Component));
		break;
		/*case SPHERE_COMPONENT:
		component = std::make_unique<CECVisualSphere>();
		m_components.emplace(id, std::move(component));
		break;*/
	default:
		printf("Wrong component type");
	}
}

CEntityComponent * MComponentManager::GetComponent(const EntityComponentIDType & ID) const
{
	return Components.at(ID).get();
}
