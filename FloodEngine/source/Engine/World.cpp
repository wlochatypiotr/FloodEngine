#include "World.h"
CScene::~CScene()
{

}

CScene::CScene(CWorld * world) : m_world(world)
{

}

CEntity * CScene::GetEntity(const EntityIDType & id)
{
	return m_entities.at(id).get();
}

CEntityComponent * CScene::GetComponent(const EntityComponentIDType & id)
{
	return m_world->GetComponent(id);
}

void CScene::AddNewEntity(const EntityIDType & id)
{
	std::unique_ptr<CEntity> entity = std::make_unique<CEntity>(id);

	m_entities.emplace(id, std::move(entity));
}



void CScene::AddNewEntity(const EntityIDType& id, CEntity * copy)
{
	std::unique_ptr<CEntity> entity = std::make_unique<CEntity>(id);
	entity.get()->Transform = copy->Transform;
	entity.get()->bIsVisible = copy->bIsVisible;
	entity.get()->bIsActive = copy->bIsActive;
	entity.get()->Components = copy->Components;
}

void CScene::AddComponent(const EntityComponentIDType& id, EComponentTypeEnum type)
{
	m_world->AddComponent(id, type);
}


void CScene::SetActive(bool activationState)
{
	m_isActive = activationState;
}

bool CScene::IsActive()
{
	return m_isActive;
}

const std::unordered_map <EntityIDType, std::unique_ptr<CEntity> > & CScene::GetEntities() const
{
	return m_entities;
}

void CScene::Update()
{
	if (IsActive()) {
		using iterator_t = std::unordered_map <EntityIDType, std::unique_ptr<CEntity> >::iterator;
		for (iterator_t iter = m_entities.begin(); iter != m_entities.end(); ++iter)
		{
			iter->second.get()->Update(/*time*/);
		}
	}
}

CWorld::CWorld()
{
}

CWorld::~CWorld()
{
}

void CWorld::Initialize(MComponentManager * manager)
{
	m_componentManager = manager;
}

CEntity * CWorld::GetEntity(const EntityIDType & id)
{
	return m_entities.at(id).get();
}

CEntityComponent * CWorld::GetComponent(const EntityComponentIDType & id)
{
	return m_componentManager->GetComponent(id);
}

//constructs CEntity object with id set to id
void CWorld::AddNewEntity(const EntityIDType & id)
{
	std::unique_ptr<CEntity> entity = std::make_unique<CEntity>(id);

	m_entities.emplace(id, std::move(entity));
}
//type 0 = MESH
//type 1 = SPHERE
//type 2 = PHYSX_COMPONENT
void CWorld::AddComponent(const EntityComponentIDType & id, EComponentTypeEnum type)
{
	m_componentManager->AddComponent(id, type);
}


CScene * CWorld::AddScene(const scene_id & sceneName, bool isActive)
{
	std::unique_ptr<CScene> scene = std::make_unique<CScene>(this);
	auto ret = scene.get();
	ret->SetActive(isActive);
	m_levels.emplace(sceneName, std::move(scene));
	return ret;
}

CScene * CWorld::GetScene(const scene_id & sceneName)
{
	return m_levels.at(sceneName).get();
}

const std::unordered_map <scene_id, std::unique_ptr<CScene> >& CWorld::GetLevels() const 
{
	return m_levels;
}

void CWorld::Update()
{
	using iterator_t = std::unordered_map <scene_id, std::unique_ptr<CScene> >::iterator;
	for (iterator_t iter = m_levels.begin(); iter != m_levels.end(); ++iter)
	{
		iter->second.get()->Update(/*time*/);
	}
}

