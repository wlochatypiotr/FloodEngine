#include "Renderer.h"

CRenderer::CRenderer()
{
}

void CRenderer::Initialize(const Shader& InShader, MWindowManager* InWinManager, const int FPSLimit)
{
	//set pointer for windowManager
	WindowManager = InWinManager;

	//compute view matrix
	ViewMatrix = glm::mat4();
	ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0.0f, 0.0f, -2.6f));
	ViewMatrix = glm::rotate(ViewMatrix, glm::radians(35.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	
	//compute projection matrix
	ProjectionMatrix = glm::mat4();
	ProjectionMatrix = glm::perspective(glm::radians(45.0f), static_cast<GLfloat>(WindowManager->GetWindowWidth()) / static_cast<GLfloat>(WindowManager->GetWindowHeight()), 0.1f, 100.0f);

	//set default shader
	SetProgram(InShader);

	//setup some GL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void CRenderer::SetViewMatrix(const mat4& InViewMatrix)
{
	ViewMatrix = InViewMatrix;
}

void CRenderer::SetProjectionMatrix(const mat4& InProjectionMatrix)
{
	ProjectionMatrix = InProjectionMatrix;
}

void CRenderer::SetProgram(const Shader& InShader)
{
	DefaultShader = InShader;
}



void CRenderer::DrawComponent(const CECVisualMesh* MeshComponent) const
{
	GLuint ShaderProgram = 0;
	if (MeshComponent->ShaderProgram != nullptr)
	{
		glUseProgram(MeshComponent->ShaderProgram->Program);
		ShaderProgram = MeshComponent->ShaderProgram->Program;
	}
	else
	{
		glUseProgram(DefaultShader.Program);
		ShaderProgram = DefaultShader.Program;
	}

	//hardcoede matrix uniform location
	glUniformMatrix4fv(static_cast<unsigned int>(EUniformEnum::MODEL_MATRIX_4X4), 1, GL_FALSE, glm::value_ptr(MeshComponent->ModelMatrix));
	glUniformMatrix4fv(static_cast<unsigned int>(EUniformEnum::VIEW_MATRIX_4X4), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
	glUniformMatrix4fv(static_cast<unsigned int>(EUniformEnum::PROJECTION_MATRIX_4X4), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));

	glUniform3f(static_cast<unsigned int>(EUniformEnum::OBJECT_COLOR_VEC3), MeshComponent->ColorVector.x, MeshComponent->ColorVector.y, MeshComponent->ColorVector.z);

	//this uniform have use for light source
	//hardcoded light value
	//glUniform3f(EUniformEnum::LIGHT_COLOR_VEC3, 1.0f, 1.0f, 1.0f);
	
	//this uniform have use for object lightning
	//hardcoded light position
	//glUniform3f(EUniformEnum::LIGHT_POS_VEC3, 2 *sin(glfwGetTime()), 1.0, 1.0f);

	//hardcoded camera position, need to be updated
	glUniform3f(static_cast<unsigned int>(EUniformEnum::CAMERA_POS_VEC3), 0.0f, 0.0f, 0.0f);

	//setup material
	//GLint matAmbientLoc = glGetUniformLocation(program, "u_material.ambient");
	//GLint matDiffuseLoc = glGetUniformLocation(program, "u_material.diffuse");
	const GLint MatSpecularLoc = glGetUniformLocation(ShaderProgram, "u_material.specular");
	const GLint MatShineLoc = glGetUniformLocation(ShaderProgram, "u_material.shininess");

	//glUniform3f(matAmbientLoc, 0.0f, 0.1f, 0.06f);
	//glUniform3f(matDiffuseLoc, 0.0f, 0.50980392f, 0.50980392f);
	glUniform3f(MatSpecularLoc, 0.50196078f, 0.50196078f, 0.50196078f);
	glUniform1f(MatShineLoc, 16.0f);

	//setup light
	const GLint LightDirectionLoc = glGetUniformLocation(ShaderProgram, "u_light.direction");
	const GLint LightAmbientLoc = glGetUniformLocation(ShaderProgram, "u_light.ambient");
	const GLint LightDiffuseLoc = glGetUniformLocation(ShaderProgram, "u_light.diffuse");
	const GLint LightSpecularLoc = glGetUniformLocation(ShaderProgram, "u_light.specular");
	const GLint LigtPositionLoc = glGetUniformLocation(ShaderProgram, "u_light.position");

	glUniform3f(LightAmbientLoc, 0.2f, 0.2f, 0.2f);
	glUniform3f(LightDiffuseLoc, 1.0f, 1.0f, 1.0f);
	glUniform3f(LightSpecularLoc, 1.0f, 1.0f, 1.0f);
	glUniform3f(LigtPositionLoc, 3 * sin(static_cast<float>(glfwGetTime())), 3.0f, 2.0f);
	//directional light
	glUniform3f(LightDirectionLoc, 3 * sin(static_cast<float>(glfwGetTime())), 3.0f, -2.0f);


	for (const CMesh& Comp : MeshComponent->GetModel()->GetMeshes())
	{
		//if mesh has textures use them as material
		if (bIsTexturingEnabled && Comp.HasTextures())
		{
			GLuint DiffuseNum = 1;
			GLuint SpecularNum = 1;
			for (GLuint i = 0; i < Comp.m_textures.size(); ++i)
			{
				std::stringstream StringStream;
				std::string Number;
				const std::string Name = Comp.m_textures.at(i).type;
				if (Name == "texture_diffuse")
				{
					StringStream << DiffuseNum++;
				}
				else if (Name == "texture_specular")
				{
					StringStream << SpecularNum++;
				}

				Number = StringStream.str();

				glUniform1i(glGetUniformLocation(ShaderProgram, ("u_material." + Name + Number).c_str()), i);
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, Comp.m_textures.at(i).id);
			}

		}
		glBindVertexArray(Comp.m_mesh.VAO);
		glDrawElements(GL_TRIANGLES, Comp.m_mesh.numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
	glUseProgram(0);
}


void CRenderer::Draw(const CEntity* InEntity) const
{
	const CEntityComponent* entityComponent = InEntity->GetEntityComponent(EntityComponentIDType("ECVisual"));
	if (entityComponent != nullptr)
	{
		EntityComponentIDType componentID = entityComponent->ComponentID();

		if (componentID == "ECVisualMesh")
		{
			//call draw mesh
			const CECVisualMesh * mesh = static_cast<const CECVisualMesh*> (entityComponent);
			DrawComponent(mesh);
		}
		else
		{
			if (componentID == "ECVisualSphere")//draw sphere
			{
				const CECVisualSphere * sphere = static_cast<const CECVisualSphere*>(entityComponent);
				//DrawComponent(sphere);
				//draw sphere
			}
		}
	}
	else
		std::cout << "This entity has no visual component!";

}


void CRenderer::Draw(CScene * scene) const
{
	if (scene->IsActive()) {
		using iterator_t = std::unordered_map <EntityIDType, std::unique_ptr<CEntity> >::const_iterator;
		for (iterator_t iter = scene->GetEntities().cbegin(); iter != scene->GetEntities().cend(); ++iter)
		{
			if(iter->second.get()->ShouldBeVisible())
				Draw(iter->second.get());
		}
	}

}

void CRenderer::Draw(const CWorld* World)
{
	ClearBuffer();
	using TIterator = std::unordered_map <scene_id, std::unique_ptr<CScene> >::const_iterator;
		for (TIterator Iterator = World->GetLevels().cbegin(); Iterator != World->GetLevels().cend(); ++Iterator)
		{
			Draw(Iterator->second.get());
		}
	SwapBuffer();
}

void CRenderer::EnableTexturing(bool flag)
{
	bIsTexturingEnabled = flag;
}

//this will be moved to draw scene method
void CRenderer::ClearBuffer()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, WindowManager->GetWindowWidth(), WindowManager->GetWindowHeight());
}

void CRenderer::SwapBuffer()
{
	glfwSwapBuffers(WindowManager->GetWindow());
}

