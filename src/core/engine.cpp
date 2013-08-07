#include "core/engine.h"

using namespace sigurd;

Engine::Engine()
{
	
}

//---------------------------

void Engine::frameStep()
{
	_renderer.renderFrame();
}