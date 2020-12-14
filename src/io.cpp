#include "io.hpp"

IO::IO(){}


bool IO::salvarAnimais(vector<shared_ptr<Animal>> animais){
    fstream stream;
	stream.open("dados/animais_data.csv", ios::out | ios::trunc);

	for(int i = 0; i < (int) animais.size(); i++){

		shared_ptr<Animal> animal = animais[i];

		stream << animal->getCodigo() << "," 
		<< animal->getPeso() << "," 
		<< animal->getAltura() << "," 
		<< animal->getIdade() << ","
        << animal->getEspecie() << ","
        << animal-> getVeterinario()->getCpf() << ","
        << animal-> getTratador()->getCpf() << ","
        << animal-> getClasse() << ","
        << this->atributosExtrasAnimais(animal) << ","
        << animal->getPerigoso()
		<< endl;
	}

	stream.close();
	return true;
}

bool IO::salvarVeterinarios(vector<shared_ptr<Veterinario>> veterinarios){

	fstream stream;
	stream.open("dados/veterinarios_data.csv", ios::out | ios::trunc);

	for(int i = 0; i < (int) veterinarios.size(); i++){

		shared_ptr<Veterinario> vet = veterinarios[i];
        string animaisTratadosStr;
        vector<shared_ptr<Animal>> animaisTratados = vet->getAnimaisTratados();

        for(int i = 0; i < (int) animaisTratados.size(); i++){
            string temp = "," + animaisTratados[i]->getCodigo();
            animaisTratadosStr += temp;
        }

		stream << vet->getCpf() << "," 
		<< vet->getNome() << "," 
		<< vet->getDataNascimento() << "," 
		<< vet->getCodigoCrmv()
        << animaisTratadosStr
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
        string animaisTratadosStr;
        vector<shared_ptr<Animal>> animaisTratados = tratador->getAnimaisTratados();

        for(int i = 0; i < (int) animaisTratados.size(); i++){
            string temp = "," + animaisTratados[i]->getCodigo();
            animaisTratadosStr += temp;
        }

		stream << tratador->getCpf() << "," 
		<< tratador->getNome() << "," 
		<< tratador->getDataNascimento() << "," 
		<< tratador->getNivelSeguranca()
        << animaisTratadosStr
		<< endl;
	}

	stream.close();
	return true;
}


/*vector<shared_ptr<Animal>> IO::carregarAnimais() const {

}*/

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

string IO::atributosExtrasAnimais(shared_ptr<Animal> animal){
                
    string classe = animal->getClasse();
    string atributos = "";    
    
    //Aqui são feitos os castings e recuperados os atributos dos animais a 
    //partir das classes. 

    if(classe == "ave" || classe == "avenativo" || classe == "aveexotico"){

        shared_ptr<Ave> ave = static_pointer_cast<Ave>(animal);
        atributos.append(ave->getAquatica() ? "1" : "0");
        atributos.append(",");
        atributos.append(ave->getPodeVoar()? "1" : "0");

    } else if(classe == "anfibio" || classe == "anfibionativo" || classe == "anfibioexotico"){

        shared_ptr<Anfibio> anfibio = static_pointer_cast<Anfibio>(animal);
        atributos.append(anfibio->getPeriodoDeMudadepele());
        atributos.append(",");
        atributos.append(to_string(anfibio->getTemperaturaDoAmbiente()));
    
    } else if(classe == "reptil" || classe == "reptilnativo" || classe == "reptilexotico" ){

        shared_ptr<Reptil> reptil = static_pointer_cast<Reptil>(animal);
        atributos.append(reptil->getPeriodoDeMudadepele());
        atributos.append(",");
        atributos.append(to_string(reptil->getTipoDepele()));

    } else if(classe == "mamifero" || classe == "mamiferonativo" || classe == "mamiferoexotico" ){

        shared_ptr<Mamifero> mamifero = static_pointer_cast<Mamifero>(animal);
        atributos.append(to_string(mamifero->getGestacao()));
    }

    if (classe == "avenativo"){

        shared_ptr<AveNativo> ave = static_pointer_cast<AveNativo>(animal);
        atributos.append(",");
        atributos.append(to_string(ave->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(ave->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(to_string(ave->getBiomaOrigem()));
    
    } else if (classe == "aveexotico"){

        shared_ptr<AveExotico> ave = static_pointer_cast<AveExotico>(animal);
        atributos.append(",");
        atributos.append(to_string(ave->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(ave->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(ave->getTerritorioDeOrigem());

    } else if(classe == "anfibionativo"){

        shared_ptr<AnfibioNativo> anfibio = static_pointer_cast<AnfibioNativo>(animal);
        atributos.append(",");
        atributos.append(to_string(anfibio->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(anfibio->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(to_string(anfibio->getBiomaOrigem()));

    } else if(classe == "anfibioexotico"){

        shared_ptr<AnfibioExotico> anfibio = static_pointer_cast<AnfibioExotico>(animal);
        atributos.append(",");
        atributos.append(to_string(anfibio->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(anfibio->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(anfibio->getTerritorioDeOrigem());

    } else if(classe == "reptilnativo"){

        shared_ptr<ReptilNativo> reptil = static_pointer_cast<ReptilNativo>(animal);
        atributos.append(",");
        atributos.append(to_string(reptil->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(reptil->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(to_string(reptil->getBiomaOrigem()));

    } else if (classe == "reptilexotico"){
        shared_ptr<ReptilExotico> reptil = static_pointer_cast<ReptilExotico>(animal);
        atributos.append(",");
        atributos.append(to_string(reptil->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(reptil->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(reptil->getTerritorioDeOrigem());
    
    } else if(classe == "mamiferonativo"){

        shared_ptr<MamiferoNativo> mamifero = static_pointer_cast<MamiferoNativo>(animal);
        atributos.append(",");
        atributos.append(to_string(mamifero->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(mamifero->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(to_string(mamifero->getBiomaOrigem()));

    } else if(classe == "mamiferoexotico"){

        shared_ptr<MamiferoExotico> mamifero = static_pointer_cast<MamiferoExotico>(animal);
        atributos.append(",");
        atributos.append(to_string(mamifero->getMarcacaoPermanente()));
        atributos.append(",");
        atributos.append(mamifero->getEmExtincao()? "1" : "0");
        atributos.append(",");
        atributos.append(mamifero->getTerritorioDeOrigem());

    }
    

    return atributos;
}
