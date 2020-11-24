# include "funcionario.hpp"

Funcionario::Funcionario(string cpf, string nome, string dataNascimento):
	cpf(cpf), nome(nome), dataNascimento(dataNascimento){
}

string Funcionario::getNome() const{
	return this->nome;
}

string Funcionario::getDataNascimento() const {
	return this->dataNascimento;
}

string Funcionario::getCpf() const {
	return this->cpf;
}


void Funcionario::setDataNascimento(string dataNascimento){
    this->dataNascimento = nome;
}
void Funcionario::setCpf(string cpf){
    this->cpf = cpf;
}
void Funcionario::setNome(string nome){
    this->nome = nome;
}

void Funcionario::adicionarAnimalTratado(shared_ptr<Animal> animal){
	this->animaisTratados.push_back(animal);
}

bool Funcionario::removerAnimalTratado(string codigoAnimal){

	for(int i = 0; i < (int) this->animaisTratados.size(); i++){

		Animal animal = *this->animaisTratados.at(i);
		string codigo = animal.getCodigo();
	
		if(codigo.compare(codigoAnimal) == 0){
			this->animaisTratados.erase(this->animaisTratados.begin() + i);
			return true;
		}
	}
	return false;
}

int Funcionario::getQuantidadeAnimaisTratados() const {
	return this->quantidadeAnimaisTratados;
}

vector<shared_ptr<Animal>> Funcionario::getAnimaisTratados() const {
	return this->animaisTratados;
}

