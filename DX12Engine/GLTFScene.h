#pragma once

#include "DXUtil.h"
#include "Renderer.h"
#include "Buffers.h"
//#include "Mesh.h"
#include "AssetTypes.h"
#include "AssetsManager.h"


#define CLAMP_TO_EDGE 33071 
#define MIRRORED_REPEAT 33648 
#define REPEAT 10497 


class GLTFScene
{
public:
	GLTFScene() = default;
	void LoadScene(std::shared_ptr<Renderer> renderer, std::shared_ptr<AssetsManager> assetsManager, const tinygltf::Model& model, unsigned int sceneId);
	void ParseSubTree(tinygltf::Node node);
	void BuildMesh(tinygltf::Mesh gltfMesh);
	std::vector<Mesh> getMeshes();

protected:
	std::shared_ptr<Renderer> m_renderer;
	ID3D12GraphicsCommandList* m_cmdList;
	//std::vector<Mesh> m_meshes;
	std::vector<Mesh> m_meshes;
	tinygltf::Model m_model;
};