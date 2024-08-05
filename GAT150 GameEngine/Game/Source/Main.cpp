#include "Engine.h"
#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[])
{
	bool quit = false;
	//initialize engine
	g_engine.Initialize();
	
	while (!quit) {
		//input

		//update
		g_engine.Update();

		//create frame
		g_engine.GetRenderer().SetColor(random(255), random(255), random(255), 0);
		g_engine.GetRenderer().BeginFrame();
		
		//draw frame
		g_engine.GetRenderer().EndFrame();

	}
	g_engine.Shutdown();
	return 0;
}