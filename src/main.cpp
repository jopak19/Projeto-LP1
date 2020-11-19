#include <iostream>
#include <memory>
#include "petfera.hpp"



int main(int argc, char const *argv[])
{
	PetFera *pet = new PetFera();

	// Apenas testes
	std::shared_ptr<Veterinario> v = make_shared<Veterinario>(9090090, "jose", "12/03/1500", 123, 4);
	pet->listarVeterinarios();
	pet->cadastrarTratador(make_shared<Tratador>(9090090, "reinaldo", "12/03/1300", Verde, 2));
	delete pet;
	return 0;
}