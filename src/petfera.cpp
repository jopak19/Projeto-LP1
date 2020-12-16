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
		string altura = animal[1];
		string peso = animal[2];
		short idade = (short) stoi(animal[3]);
		string especie = animal[4];
		shared_ptr<Veterinario> vet = this->getVeterinario(animal[5]);
		shared_ptr<Tratador> tratador = this->getTratador(animal[6]);
		string classe = animal[7];
		bool perigoso = (animal[8].compare("1") == 0);

		if(classe == "ave" || classe == "avenativo" || classe == "aveexotico"){

			/*
	        shared_ptr<Ave> ave = static_pointer_cast<Ave>(animal);
	        atributos.append(ave->getAquatica() ? "1" : "0");
	        atributos.append(",");
	        atributos.append(ave->getPodeVoar()? "1" : "0");
	        */

	    } else if(classe == "anfibio" || classe == "anfibionativo" || classe == "anfibioexotico"){

	    	/*
	        shared_ptr<Anfibio> anfibio = static_pointer_cast<Anfibio>(animal);
	        atributos.append(anfibio->getPeriodoDeMudadepele());
	        atributos.append(",");
	        atributos.append(to_string(anfibio->getTemperaturaDoAmbiente()));
	        */
	    
	    } else if(classe == "reptil" || classe == "reptilnativo" || classe == "reptilexotico" ){

	    	/*
	        shared_ptr<Reptil> reptil = static_pointer_cast<Reptil>(animal);
	        atributos.append(reptil->getPeriodoDeMudadepele());
	        atributos.append(",");
	        atributos.append(to_string(reptil->getTipoDepele()));
	        */

	    } else if(classe == "mamifero" || classe == "mamiferonativo" || classe == "mamiferoexotico" ){

	    	/*
	        shared_ptr<Mamifero> mamifero = static_pointer_cast<Mamifero>(animal);
	        atributos.append(to_string(mamifero->getGestacao()));
	        */
	    }

	    if (classe == "avenativo"){

	    	/*
	        shared_ptr<AveNativo> ave = static_pointer_cast<AveNativo>(animal);
	        atributos.append(",");
	        atributos.append(to_string(ave->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(ave->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(to_string(ave->getBiomaOrigem()));
	        */
	    
	    } else if (classe == "aveexotico"){

	    	/*
	        shared_ptr<AveExotico> ave = static_pointer_cast<AveExotico>(animal);
	        atributos.append(",");
	        atributos.append(to_string(ave->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(ave->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(ave->getTerritorioDeOrigem());
	        */

	    } else if(classe == "anfibionativo"){

	    	/*
	        shared_ptr<AnfibioNativo> anfibio = static_pointer_cast<AnfibioNativo>(animal);
	        atributos.append(",");
	        atributos.append(to_string(anfibio->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(anfibio->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(to_string(anfibio->getBiomaOrigem()));
	        */

	    } else if(classe == "anfibioexotico"){

	    	/*
	        shared_ptr<AnfibioExotico> anfibio = static_pointer_cast<AnfibioExotico>(animal);
	        atributos.append(",");
	        atributos.append(to_string(anfibio->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(anfibio->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(anfibio->getTerritorioDeOrigem());
	        */

	    } else if(classe == "reptilnativo"){

	    	/*
	        shared_ptr<ReptilNativo> reptil = static_pointer_cast<ReptilNativo>(animal);
	        atributos.append(",");
	        atributos.append(to_string(reptil->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(reptil->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(to_string(reptil->getBiomaOrigem()));
	        */

	    } else if (classe == "reptilexotico"){

	    	/*
	        shared_ptr<ReptilExotico> reptil = static_pointer_cast<ReptilExotico>(animal);
	        atributos.append(",");
	        atributos.append(to_string(reptil->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(reptil->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(reptil->getTerritorioDeOrigem());
	        */
	    
	    } else if(classe == "mamiferonativo"){

	    	/*
	        shared_ptr<MamiferoNativo> mamifero = static_pointer_cast<MamiferoNativo>(animal);
	        atributos.append(",");
	        atributos.append(to_string(mamifero->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(mamifero->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(to_string(mamifero->getBiomaOrigem()));
	        */

	    } else if(classe == "mamiferoexotico"){

	    	/*
	        shared_ptr<MamiferoExotico> mamifero = static_pointer_cast<MamiferoExotico>(animal);
	        atributos.append(",");
	        atributos.append(to_string(mamifero->getMarcacaoPermanente()));
	        atributos.append(",");
	        atributos.append(mamifero->getEmExtincao()? "1" : "0");
	        atributos.append(",");
	        atributos.append(mamifero->getTerritorioDeOrigem());
	        */
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