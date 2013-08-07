#pragma once

#include "core/objectmanager.h"
#include "core/component.h"
#include "math/mat4x4.h"

namespace sigurd
{
	class Entity
	{
	protected:
		foundation::Array<Component*> _components;


	public:
		Entity();
	};
}