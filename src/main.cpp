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

    //teste       

	// Apenas testes
	PetFera *petfera = new PetFera();
    Interface *inter = new Interface();
    inter->setPet(petfera);
    shared_ptr<Tratador> tratador = make_shared<Tratador>(
		"5335345", "Fulano1", "12/03/2001", Vermelho);
    inter->menu();


	
/*
	shared_ptr<Tratador> tratador2 = make_shared<Tratador>(
		"5686767", "Fulano2", "12/03/2001", Verde);

	shared_ptr<Tratador> tratador3 = make_shared<Tratador>(
		"5389080", "Fulano3", "12/03/2001", Azul);

	shared_ptr<Veterinario> vet1 = make_shared<Veterinario>(
		"242342", "Veterinario1", "25/04/1987", "337247");

	shared_ptr<Veterinario> vet2 = make_shared<Veterinario>(
		"275862", "Veterinario2", "25/04/1987", "878764");

	shared_ptr<Veterinario> vet3 = make_shared<Veterinario>(
		"86786", "Veterinario3", "25/04/1987", "6444775");

	petfera->cadastrarTratador(tratador);
	petfera->cadastrarTratador(tratador2);
	petfera->cadastrarTratador(tratador3);

	petfera->cadastrarVeterinario(vet1);
	petfera->cadastrarVeterinario(vet2);
	petfera->cadastrarVeterinario(vet3);
	
	shared_ptr<Tratador> tratadorAchado = petfera->getTratador("5335345");
	cout << *tratadorAchado << endl;

	cout << "-------------------" << endl;

	petfera->listarTratadores();
	petfera->listarVeterinarios();

	cout << "-------------------" << endl;
	petfera->removerTratador("5335345");
	petfera->removerVeterinario("86786");

	cout << "Tratadores e Veterinários após remoção" << endl;

	petfera->listarTratadores();
	petfera->listarVeterinarios();

*/
	delete petfera;

	return 0;
}
