#include "EntityComponent.h"
#include "Entity.h"

void CECVisual::Update()
{
	const CEntity* Owner = GetOwner();
	const STransform& Trans = Owner->GetTransform();
	//update world-model matrix 
	// scale -> translate -> rotate
	ModelMatrix = glm::mat4();

	// scale 
	ModelMatrix = glm::scale(ModelMatrix, Trans.Scale);
	
	//rotation
	if (Trans.Rotation.x != 0)
	{
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Trans.Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (Trans.Rotation.y != 0)
	{
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Trans.Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	if (Trans.Rotation.z != 0)
	{
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Trans.Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	//translate
	ModelMatrix = glm::translate(ModelMatrix, Trans.Position);
}

void CECVisual::SetColor(const float R, const float G, const float B)
{
	ColorVector[0] = R;
	ColorVector[1] = G;
	ColorVector[2] = B;

}

void CECVisual::SetProgram(const Shader& InShaderProgram)
{
	ShaderProgram = ShaderProgram;
}


void CECVisualMesh::SetMesh(CModel* InMeshPtr)
{

	ModelMesh = InMeshPtr;
	
}
CModel * CECVisualMesh::GetModel()
{
	return ModelMesh;
}

const CModel* CECVisualMesh::GetModel() const
{
	return ModelMesh;
}
