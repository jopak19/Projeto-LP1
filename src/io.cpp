#include "io.hpp"

IO::IO(){

}

/*
bool IO::salvarAnimais(vector<shared_ptr<Animal>> animais){

}
*/
bool IO::salvarVeterinarios(vector<shared_ptr<Veterinario>> veterinarios){

	fstream stream;
	stream.open("dados/veterinarios_data.csv", ios::out | ios::trunc);

	for(int i = 0; i < (int) veterinarios.size(); i++){

		shared_ptr<Veterinario> vet = veterinarios[i];

		stream << vet->getCpf() << "," 
		<< vet->getNome() << "," 
		<< vet->getDataNascimento() << "," 
		<< vet->getCodigoCrmv()
		<< endl;
	}

	stream.close();
	return true;
}


bool IO::salvarTratadores(vector<shared_ptr<Tratador>> tratadores){

	fstream stream;
	stream.open("dados/tratadores_data.csv", ios::out | ios::trunc);

	for(int i = 0; i < (int) tratadores.size(); i++){

		shared_ptr<Tratador> tratador = tratadores[i];

		stream << tratador->getCpf() << "," 
		<< tratador->getNome() << "," 
		<< tratador->getDataNascimento() << "," 
		<< tratador->getNivelSeguranca()
		<< endl;
	}

	stream.close();
	return true;
}

/*
vector<shared_ptr<Animal>> IO::carregarAnimais() const {

}

vector<shared_ptr<Veterinario>> IO::carregarVeterinarios() const {

}

vector<shared_ptr<Tratador>> IO::carregarTratadores() const {

}*/