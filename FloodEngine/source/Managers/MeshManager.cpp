#include "MeshManager.h"

MModelManager::MModelManager() 
{

}

MModelManager::~MModelManager()
{

}

//will throw exception if no such element exists
CModel * MModelManager::Get(const ModelIDType& ID) const
{
	return Models.at(ID).get();
}

bool MModelManager::Load(const ModelIDType& ID, ModelIDType Filename)
{
	std::unique_ptr<CModel> MeshPtr = std::make_unique<CModel>();
	const bool bSuccess = MeshPtr->LoadModel(Filename);
	if (bSuccess)
	{
		Models.emplace(ID, std::move(MeshPtr));

		printf("Mesh %s loaded successfully\n", Filename.c_str());
	}
	else
	{
		printf("Mesh %s loading failed\n", Filename.c_str());
		MeshPtr.reset();
	}

	return bSuccess;
}

void MModelManager::ShutDown()
{
	Clear();
}

void MModelManager::Clear()
{
	Models.clear();
}

void MModelManager::Initialize()
{
	//TODO: move to config
	Load("mesh_cube", "models/Cube.obj");
	Load("mesh_table", "models/PoolTable.obj");
	Load("mesh_dozer", "models/nanosuit.obj");
}
