#include <iostream>
#include "interface.hpp" 
#include "petfera.hpp"

int main(int argc, char const *argv[])
{
	PetFera *petfera = new PetFera();
    Interface *inter = new Interface();
    inter->setPet(petfera);
    inter->menu();
	delete petfera;
	return 0;
}
