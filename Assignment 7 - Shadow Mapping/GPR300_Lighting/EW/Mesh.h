//Author: Eric Winebrenner

#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace ew {
	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 tangent;
		glm::vec2 uv;
		Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 tangent, glm::vec2 uv)
			: position(position), normal(normal), tangent(tangent), uv(uv) {};
	};

	/// <summary>
	/// Just holds a bunch of vertex + face (indices) data
	/// </summary>
	struct MeshData {
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
	};

	/// <summary>
	/// Holds OpenGL buffers, can be drawn
	/// </summary>
	class Mesh {
	public:
		Mesh(MeshData* meshData);
		~Mesh();
		void draw();
	private:
		GLuint mVAO, mVBO, mEBO;
		GLsizei mNumIndices;
		GLsizei mNumVertices;
	};
}
