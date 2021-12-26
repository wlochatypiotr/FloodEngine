#include "ShaderManager.h"

MShaderManager::MShaderManager()
{
}

Shader& MShaderManager::Get(const EShaderType ShaderType)
{
	return ShaderMap[ShaderType];
}

void MShaderManager::Initialize()
{
	//TODO:move paths to config
	Load(EShaderType::LAMP_SHADER, Shader("shaders/Phong_VS.frag", "shaders/ColorOnly_FS.frag"));
	Load(EShaderType::TABLE_SHADER, Shader("shaders/Phong_VS.frag", "shaders/Phong_FS.frag"));
}

void MShaderManager::Load(const EShaderType ShaderType, const Shader& InShader)
{
	ShaderMap.emplace(ShaderType, InShader);
}
