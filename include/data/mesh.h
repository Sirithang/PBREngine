#pragma once

#include "core/objectmanager.h"
#include "math/Vector3.h"

namespace sigurd
{
	namespace data
	{
		struct Vertex
		{
			alfar::Vector3 position;
			alfar::Vector3 uv;
			alfar::Vector3 normal;
		};

		struct Mesh : public ManagedObject
		{
			Vertex*		_vertexData;
			uint32_t*	_indexData;

			int		_nbVertex;
			int		_nbIndex;
		};

		typedef ObjectManager<Mesh, 512> MeshManager;

		namespace mesh
		{
			void objCreated(Mesh& obj);
			void loadFromFile(Mesh& mesh, const char* file);
		}
	}
}