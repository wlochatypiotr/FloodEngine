#pragma once
#include "Loaders/Model.h"
#include <unordered_map>
#include <memory>

using ModelIDType = std::string;

class MModelManager
{
public:
	MModelManager(const MModelManager&) = delete;
	MModelManager(MModelManager&&) = delete;
	MModelManager& operator=(const MModelManager&) = delete;
	MModelManager& operator=(MModelManager&&) = delete;

	MModelManager();
	~MModelManager();

	CModel* Get(const ModelIDType& ID) const;
	bool Load(const ModelIDType& ID, ModelIDType Filename);
	void ShutDown();
	void Clear();
	void Initialize();
private:
	std::unordered_map <ModelIDType, std::unique_ptr<CModel> > Models;
};
