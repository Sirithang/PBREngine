#pragma once

#include "core/component.h"
#include "math/vector3.h"

namespace sigurd
{
	namespace component
	{
		struct Transform : public Component
		{
			alfar::Vector3		position;
			alfar::Quaternion	quaternion;

			alfar::Matrix4x4	_matrix;
		};

		namespace transform
		{
			void computeTransform(Transform& trans);
		}
	}
}