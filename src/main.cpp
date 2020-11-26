#include <iostream>
#include "interface.hpp" 
#include "tratador.hpp"
#include "veterinario.hpp"
#include "nivelseguranca.hpp"
#include <vector>
#include <string>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;


int main(int argc, char const *argv[])
{

	PetFera *petfera = new PetFera();
    Interface *inter = new Interface();
    inter->setPet(petfera);
    inter->menu();


	delete petfera;
	delete inter;

	return 0;
}
