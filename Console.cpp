#include "Engine.h"
#include <iostream>

int main(int argc, char** argv) {
	Efficio::Engine engine;
	engine.Start();

	while (true)
	{
		std::cout << engine.GetFrame()->ID << "\n";
	}
	return 0;
}