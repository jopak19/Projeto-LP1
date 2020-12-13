#include "io.hpp"

IO::IO(){}

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
*/
vector<shared_ptr<Veterinario>> IO::carregarVeterinarios() const {

	std::vector<shared_ptr<Veterinario>> veterinarios;

	fstream stream;
	stream.open("dados/veterinarios_data.csv");

	if(!stream.is_open()){
		return veterinarios;
	}

	vector<string> dados; 
    string linha;
    string dado;
    string temp;

    while(getline(stream, linha)) {
 		
 		dados.clear();
    	stringstream s(linha); 
  
        while (getline(s, dado, ',')) { 
            dados.push_back(dado);
        }

        shared_ptr<Veterinario> vet = make_shared<Veterinario>(
        	dados[0], dados[1], dados[2], dados[3]);

        veterinarios.push_back(vet);

    }

    stream.close();
	return veterinarios;
}


vector<shared_ptr<Tratador>> IO::carregarTratadores() const {

	std::vector<shared_ptr<Tratador>> tratadores;

	fstream stream;
	stream.open("dados/tratadores_data.csv");

	if(!stream.is_open()){
		return tratadores;
	}

	if(stream.peek() == EOF){
		return tratadores;
	}

	vector<string> dados; 
    string linha;
    string dado;
    string temp;

    while(getline(stream, linha)) {
 		
 		dados.clear();
    	stringstream s(linha); 
  
        while (getline(s, dado, ',')) { 
            dados.push_back(dado);
        }

        int numeroNivel = stoi(dados[3]);
        NivelSeguranca nivel;

        if(numeroNivel == 0){
        	nivel = Verde;

        } else if (numeroNivel == 1){
        	nivel = Azul;

        } else if (numeroNivel == 2){
        	nivel = Vermelho;
        }

        shared_ptr<Tratador> tratador = make_shared<Tratador>(
        	dados[0], dados[1], dados[2], nivel);

        tratadores.push_back(tratador);
    }

    stream.close();
	return tratadores;

}
