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
		cout << this->animais.at(i)->imprimir() << endl;
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
}

void PetFera::salvarDados(){
	this->gerenciadorArquivos->salvarVeterinarios(this->getVeterinarios());
	this->gerenciadorArquivos->salvarTratadores(this->getTratadores());
}

