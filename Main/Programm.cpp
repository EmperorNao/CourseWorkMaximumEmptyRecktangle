#include "Controller.h"
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "RUS");
	Controller controller;
	controller.run();
	
}