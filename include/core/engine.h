#pragma once

#include "core/renderer.h"


namespace sigurd
{
	class Engine
	{
	protected:
		Renderer _renderer;

	public:
		Engine();

		void frameStep();
	};
}