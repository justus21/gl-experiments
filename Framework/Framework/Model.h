#pragma once
#include <glm/glm.hpp>
#include <assimp/material.h>
#include <string>
#include <vector>
#include <unordered_map>

namespace fw
{

class Model
{
public:
	struct Mesh
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec3> tangents;
		std::vector<glm::vec2> UVs;
		std::vector<unsigned int> indices;

		using Materials = std::unordered_map<aiTextureType, std::vector<std::string>>;
		Materials materials;
	};

	using Meshes= std::vector<Mesh>;

	explicit Model();
	~Model();
	Model(const Model&) = delete;
	Model(Model&&) = delete;
	Model& operator=(const Model&) = delete;
	Model& operator=(Model&&) = delete;

	bool loadModel(const std::string& file);
	const Meshes& getMeshes() const;

private:
	Meshes meshes;
};

} // fw