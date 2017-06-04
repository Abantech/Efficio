#include "Core\include\Sensor.h";
#include "Core\include\Event.h";
#include <iostream>

int main(int argc, char** argv) {
	Efficio::Sensor* a = new Efficio::Sensor();
	std::cout << a->GetSource();
	Efficio::Event* e = new Efficio::Event("");
	std::getchar();
	return 0;
}