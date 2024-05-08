#include "corepch.h"
#include "VertexArray.h"
#include "Log.h"

namespace KMG
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_RendererID);
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::Bind()
    {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddVertexBuffer(const s_ptr<VertexBuffer>& vertexBuffer)
    {
        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();

        for (const auto& layout : vertexBuffer->GetLayouts())
        {
            glVertexAttribPointer(
                m_VertexBufferIndex,
                GetLayoutElementCount(layout.Type),
                LayoutTypeToGLType(layout.Type),
                layout.Normalized ? GL_TRUE : GL_FALSE,
                vertexBuffer->GetStride(),
                (const void*)layout.Offset
            );

            glEnableVertexAttribArray(m_VertexBufferIndex);
            m_VertexBufferIndex++;
        }

        m_VertexBuffers.push_back(vertexBuffer);
        glBindVertexArray(0);
    }

    void VertexArray::SetIndexBuffer(const s_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }

    s_ptr<VertexArray> VertexArray::Create()
    {
        return MakeShared<VertexArray>();
    }
}
