#pragma once

#include "core/component.h"
#include <gl/GL.h>

namespace sigurd
{
	namespace component
	{
		struct MeshRenderer : public Component
		{
			//id of mesh in the MeshManager
			uint32_t _mesh;

			GLuint _indexbuffer;
			GLuint _vertexbuffer;

			//todo : add bbox here, allowing to do frustum culling
		};

		typedef ObjectManager<MeshRenderer, 512> MeshRendererManager;

		namespace meshrenderer
		{
			
		}
	}
}