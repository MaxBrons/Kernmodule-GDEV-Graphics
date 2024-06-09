#include "corepch.h"
#include "Renderer.h"

namespace KMG
{
	glm::mat4 Renderer::s_ViewProjectionMatrix = glm::mat4(1);

	void Renderer::Initialize()
	{
		RenderCommands::Initialize();
	}

	void Renderer::OnWindowResized(uint32_t width, uint32_t height)
	{
		RenderCommands::SetViewport(0, 0, width, height);
	}

	void Renderer::Begin(const Camera3D& camera)
	{
		s_ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::End()
	{
		
	}

	void Renderer::Submit(const s_ptr<Shader>& shader, const s_ptr<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", s_ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		RenderCommands::DrawIndexed(vertexArray);
	}

}
