#include "petfera.hpp"

PetFera::PetFera(){
	this->gerenciadorArquivos = new IO();
	this->carregarDados();
}

PetFera::~PetFera(){
	this->salvarDados();
	delete this->gerenciadorArquivos;
}

vector<shared_ptr<Animal>> PetFera::getAnimais() const{
	return this->animais;
}

vector<shared_ptr<Tratador>> PetFera::getTratadores() const{
    return this->tratadores;
}

vector<shared_ptr<Veterinario>> PetFera::getVeterinarios() const{
    return this->veterinarios;
}

shared_ptr<Animal> PetFera::getAnimal(string codigo) const{

	for(int i = 0; i < (int) this->animais.size(); i++){

		shared_ptr<Animal> an = this->animais.at(i);
		string codigo2 = an->getCodigo();

		if(codigo.compare(codigo2) == 0){
			return an;
		}
	}
	return shared_ptr<Animal>(nullptr);
}

shared_ptr<Veterinario> PetFera::getVeterinario(string cpf) const {

	for(int i = 0; i < (int) this->veterinarios.size(); i++){
		
		shared_ptr<Veterinario> vet = this->veterinarios.at(i);
		string cpf2 = vet->getCpf();

		if(cpf.compare(cpf2) == 0){
			return vet;
		}
	}
	return shared_ptr<Veterinario>(nullptr);
}

shared_ptr<Tratador> PetFera::getTratador(string cpf) const {

	for(int i = 0; i < (int) this->tratadores.size(); i++){

		shared_ptr<Tratador> tra = this->tratadores.at(i);
		string cpf2 = tra->getCpf();
	
		if(cpf.compare(cpf2) == 0){
			return tra;
		}
	}
	return shared_ptr<Tratador>(nullptr);
}

bool PetFera::cadastrarAnimal(shared_ptr<Animal> animal, string cpfTratador, string cpfVeterinario){
   	
   	/*
	Não cadastra animal repetido e não cadastra caso o 
	Tratador ou Veterinário não existam
   	*/
   	
	if(this->existeAnimal(animal->getCodigo()) 
		|| !this->existeTratador(cpfTratador)
	 	|| !this->existeVeterinario(cpfVeterinario) ){

		return false;
	}

   	shared_ptr<Tratador> trat = this->getTratador(cpfTratador);
   	NivelSeguranca segAnimal = animal->getNivelSeguranca(); 
   	NivelSeguranca segTratador = trat->getNivelSeguranca();

   	if(segTratador < segAnimal){
   		return false;
   	}
	
	animal->setTratador(trat);
	shared_ptr<Veterinario> vet = this->getVeterinario(cpfVeterinario);
	animal->setVeterinario(vet);
	trat->adicionarAnimalTratado(animal);
	vet->adicionarAnimalTratado(animal);
   	this->animais.push_back(animal);

   	return true;
}

bool PetFera::cadastrarTratador(shared_ptr<Tratador> tratador){

	if(this->existeTratador(tratador->getCpf())){
		return false;
	}

    this->tratadores.push_back(tratador);
    return true;
}

bool PetFera::cadastrarVeterinario(shared_ptr<Veterinario> veterinario){

	if(this->existeVeterinario(veterinario->getCpf())){
		return false;
	}

    this->veterinarios.push_back(veterinario);
    return true;
}

bool PetFera::realizarVenda(string codigoAnimal){

	if(!this->existeAnimal(codigoAnimal)){
		return false;
	}

	shared_ptr<Animal> animal = this->getAnimal(codigoAnimal);
	shared_ptr<Veterinario> vet = animal->getVeterinario();
	shared_ptr<Tratador> tra = animal->getTratador();

	vet->removerAnimalTratado(codigoAnimal);
	tra->removerAnimalTratado(codigoAnimal);
	this->removerAnimal(codigoAnimal);

	return true;
}

bool PetFera::removerTratador(string cpfTratador){

	for(int i = 0; i < (int) this->tratadores.size(); i++){

		shared_ptr<Tratador> tra = this->tratadores.at(i);
		string cpf = tra->getCpf();
	
		if(cpfTratador.compare(cpf) == 0){
			this->tratadores.erase(this->tratadores.begin() + i);
			return true;
		}
	}

	return false;
}

bool PetFera::removerVeterinario(string cpfVeterinario){

	for(int i = 0; i < (int) this->veterinarios.size(); i++){

		shared_ptr<Veterinario> vet = this->veterinarios.at(i);
		string cpf = vet->getCpf();
	
		if(cpfVeterinario.compare(cpf) == 0){
			this->veterinarios.erase(this->veterinarios.begin() + i);
			return true;
		}
	}
	return false;
}

bool PetFera::removerAnimal(string codigoAnimal){

	for(int i = 0; i < (int) this->animais.size(); i++){

		shared_ptr<Animal> animal = this->animais.at(i);
		string codigo = animal->getCodigo();
	
		if(codigo.compare(codigoAnimal) == 0){
			this->animais.erase(this->animais.begin() + i);
			return true;
		}
	}
	return false;
}

bool PetFera::existeAnimal(string codigoAnimal) const {

	for(int i = 0; i < (int) this->animais.size(); i++){
		shared_ptr<Animal> animal = this->animais.at(i);
		string codigo = animal->getCodigo();
	
		if(codigo.compare(codigoAnimal) == 0){
			return true;
		}
	}
	return false;
}

bool PetFera::existeTratador(string cpfTratador) const {

	for(int i = 0; i < (int) this->tratadores.size(); i++){
		shared_ptr<Tratador> tra = this->tratadores.at(i);
		string cpf = tra->getCpf();
	
		if(cpfTratador.compare(cpf) == 0){
			return true;
		}
	}
	return false;
}

bool PetFera::existeVeterinario(string cpfVeterinario) const {

	for(int i = 0; i < (int) this->veterinarios.size(); i++){
		shared_ptr<Veterinario> vet = this->veterinarios.at(i);
		string cpf = vet->getCpf();
	
		if(cpfVeterinario.compare(cpf) == 0){
			return true;
		}
	}
	return false;
}

void PetFera::listarAnimais() const{

	for(int i = 0; i < (int) this->animais.size(); i++){
		cout << this->animais.at(i) << endl;
	}
}

void PetFera::listarTratadores() const{

	for(int i = 0; i < (int) this->tratadores.size(); i++){
		cout << *this->tratadores.at(i) << endl;
	}
}

void PetFera::listarVeterinarios() const{

	for(int i = 0; i < (int) this->veterinarios.size(); i++){
		cout << *this->veterinarios.at(i) << endl;
	}
}

void PetFera::carregarDados(){
	this->veterinarios = this->gerenciadorArquivos->carregarVeterinarios();
	this->tratadores = this->gerenciadorArquivos->carregarTratadores();
	this->carregarDadosAnimais(this->gerenciadorArquivos->carregarAnimais());
}

void PetFera::salvarDados(){
	this->gerenciadorArquivos->salvarVeterinarios(this->getVeterinarios());
	this->gerenciadorArquivos->salvarTratadores(this->getTratadores());
    this->gerenciadorArquivos->salvarAnimais(this->getAnimais());
    this->carregarInteracoes();
}

void PetFera::carregarDadosAnimais(vector<vector<string>> animais){
	
	for(int i = 0; i < (int) this->animais.size(); i++) {

		vector<string> animal = animais[i];
		string codigo = animal[0];
		string peso = animal[1];
        string altura = animal[2];
		short idade = (short) stoi(animal[3]);
		string especie = animal[4];
		shared_ptr<Veterinario> vet = this->getVeterinario(animal[5]);
		shared_ptr<Tratador> tratador = this->getTratador(animal[6]);
        string cpfTratador = animal[6];
        string cpfVet = animal[5];
		string classe = animal[7];
		bool perigoso = (animal[8].compare("1") == 0);

		if(classe == "ave"){

			 shared_ptr<Ave> ave = make_shared<Ave>(codigo, peso, altura, idade, especie, (animal[9].compare("1") == 0), (animal[10].compare("1") == 0), perigoso);
             cadastrarAnimal(ave, cpfVet, cpfTratador);

	    } else if(classe == "anfibio"){
            shared_ptr<Anfibio> anfibio = make_shared<Anfibio>(codigo, peso, altura, idade, especie, animal[9], stoi(animal[10]), perigoso);
            cadastrarAnimal(anfibio,  cpfVet, cpfTratador);

	    
	    } else if(classe == "reptil"){
             shared_ptr<Reptil> reptil = make_shared<Reptil>(codigo, peso, altura, idade, especie, animal[9], convertePele(animal[10]), perigoso);
             cadastrarAnimal(reptil, cpfVet, cpfTratador);


	    } else if(classe == "mamifero" ){
            shared_ptr<Mamifero> mamifero = make_shared<Mamifero>(codigo, peso, altura, idade, especie, converteGestacao(animal[9]), perigoso);
            cadastrarAnimal(mamifero, cpfVet, cpfTratador);

	    }else if (classe == "avenativo"){

	    	shared_ptr<AveNativo> ave = make_shared<AveNativo>(codigo, peso, altura, idade, especie, (animal[9].compare("1") == 0), (animal[10].compare("1") == 0), (short) stoi(animal[11]),(animal[12].compare("1") == 0), converteBioma(animal[13]), perigoso);
            cadastrarAnimal(ave, cpfVet, cpfTratador);
	    
	    } else if (classe == "aveexotico"){
            shared_ptr<AveExotico> ave = make_shared<AveExotico>(codigo, peso, altura, idade, especie, (animal[9].compare("1") == 0), (animal[10].compare("1") == 0), (short) stoi(animal[11]), (animal[12].compare("1") == 0), animal[13], perigoso);
            cadastrarAnimal(ave, cpfVet, cpfTratador);

	    } else if(classe == "anfibionativo"){
            shared_ptr<AnfibioNativo> anfibio = make_shared<AnfibioNativo>(codigo, peso, altura, idade, especie, animal[9], stoi(animal[10]), stoi(animal[11]), (animal[12].compare("1") == 0), converteBioma(animal[13]), perigoso);
            cadastrarAnimal(anfibio,  cpfVet, cpfTratador);

	    } else if(classe == "anfibioexotico"){
            shared_ptr<AnfibioExotico> anfibio = make_shared<AnfibioExotico>(codigo, peso, altura, idade, especie, animal[9], stoi(animal[10]), stoi(animal[11]), (animal[12].compare("1") == 0), animal[13], perigoso);
            cadastrarAnimal(anfibio,  cpfVet, cpfTratador);


	    } else if(classe == "reptilnativo"){
            shared_ptr<ReptilNativo> reptil = make_shared<ReptilNativo>(codigo, peso, altura, idade, especie, animal[9], convertePele(animal[10]), stoi(animal[11]), (animal[12].compare("1") == 0), converteBioma(animal[13]), perigoso);
            cadastrarAnimal(reptil, cpfVet, cpfTratador);

	    } else if (classe == "reptilexotico"){
            shared_ptr<ReptilExotico> reptil = make_shared<ReptilExotico>(codigo, peso, altura, idade, especie, animal[9], convertePele(animal[10]), stoi(animal[11]), (animal[12].compare("1") == 0), animal[13], perigoso);
            cadastrarAnimal(reptil, cpfVet, cpfTratador);

	    } else if(classe == "mamiferonativo"){

            shared_ptr<MamiferoNativo> mamifero = make_shared<MamiferoNativo>(codigo, peso, altura, idade, especie, converteGestacao(animal[9]), stoi(animal[10]), (animal[11].compare("1") == 0), converteBioma(animal[12]), perigoso);
            cadastrarAnimal(mamifero, cpfVet, cpfTratador);


	    } else if(classe == "mamiferoexotico"){
            shared_ptr<MamiferoExotico> mamifero = make_shared<MamiferoExotico>(codigo, peso, altura, idade, especie, converteGestacao(animal[9]), stoi(animal[10]), (animal[11].compare("1") == 0), animal[12], perigoso);
            cadastrarAnimal(mamifero, cpfVet, cpfTratador);
	    	
	    }
	}
}

void PetFera::carregarInteracoes(){
	
	/*
	Recupera as relações entre os animais, tratadores
	e veterinários após carregar os objetos através da 
	leitura dos arquivos csv.
	*/

	for(int i = 0; i < (int) this->animais.size(); i++) {

		shared_ptr<Animal> animal = this->animais[i];
		shared_ptr<Tratador> tratador = animal->getTratador();
		shared_ptr<Veterinario> vet = animal->getVeterinario();

		if(tratador != nullptr){
			tratador->adicionarAnimalTratado(animal);
		}

		if(vet != nullptr){
			vet->adicionarAnimalTratado(animal);
		}
	}
}


Bioma PetFera::converteBioma(string bioma){

    if(bioma == "0"){
        return AMAZONIA;
    }else if(bioma == "1"){ 
        return CAATINGA;
    }else if(bioma == "2"){
        return PAMPA;
    }else if(bioma == "3"){
        return CERRADO;
    }else if(bioma == "4"){
        return PANTANAL;
    }else if(bioma =="5"){
        return MATAATLANTICA;
    }else{
        return CAATINGA;
    }
}

TipoDePele PetFera::convertePele(string pele){

    if(pele == "0"){
        return ESCAMAS;
    }else if(pele == "1"){
        return CARAPACA;
    }else{
        return PLACADERMICA;
    }
};

Gestacao PetFera::converteGestacao(string gest){
   
    if(gest == "0"){
        return MONOTREMADO;
    }else if(gest == "1"){
        return MARSUPIAL;
    }else{
        return PLACENTARIO;
    }

};
