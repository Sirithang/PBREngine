#pragma once

#include "core/objectmanager.h"

namespace sigurd
{
	enum ComponentType
	{
		MESHRENDERER
	};

	struct Component : public ManagedObject
	{
		ComponentType _type;
	};
}