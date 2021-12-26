#pragma once
#include <unordered_map>
#include "Loaders/ShaderLoader.h"

enum class EShaderType : uint8_t
{
	LAMP_SHADER,
	TABLE_SHADER
};

class MShaderManager
{
public:

	MShaderManager(const MShaderManager&) = delete;
	MShaderManager(MShaderManager&&) = delete;
	MShaderManager& operator=(const MShaderManager&) = delete;
	MShaderManager& operator=(MShaderManager&&) = delete;

	MShaderManager();

	Shader& Get(const EShaderType ShaderType);
	void Initialize();
	void Load(const EShaderType ShaderType, const Shader& InShader);

private:
	std::unordered_map <EShaderType, Shader > ShaderMap;
};
