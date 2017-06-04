#include "Core\Test.h";
#include <iostream>

int main(int argc, char** argv) {
	MyClass* a = new MyClass();
	std::cout << a->SayHello();
	std::getchar();
	return 0;
}