#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include "io.hpp"
#include <iostream>
#include "vector"
using namespace std;

string getNomePorCpfVeterinario(string cpfVeterinario, vector<shared_ptr<Veterinario>> veterinarios){

	for(int i = 0; i < (int) veterinarios.size(); i++){
		shared_ptr<Veterinario> vet = veterinarios.at(i);
		string cpf = vet->getCpf();
	
		if(cpfVeterinario.compare(cpf) == 0){
			return vet->getNome();
		}
	}
	return "não encontrado";
}
string getNomePorCpfTratador(string cpfTratador, vector<shared_ptr<Tratador>> tratadores){

	for(int i = 0; i < (int) tratadores.size(); i++){
		shared_ptr<Tratador> tra = tratadores.at(i);
		string cpf = tra->getCpf();
	
		if(cpfTratador.compare(cpf) == 0){
			return tra->getNome();
		}
	}
	return "não encontrado";
}
void filtrarVeterinario(vector<vector<string>>& an, vector<shared_ptr<Veterinario>> veterinarios, string nomeVet){
    for(int i = (int) an.size()-1; 0 <= i ;  i--){
        string nomeVeterinario = getNomePorCpfVeterinario(an[i][5], veterinarios);
        if(nomeVeterinario.compare(nomeVet) != 0){
            an.erase(an.begin() + i);
        } 

    };
}
void filtrarTratador(vector<vector<string>> &an, vector<shared_ptr<Tratador>> tratadores, string tra){
    
    for(int i = (int) an.size()-1; 0 <= i ;  i--){
        string nomeTratador = getNomePorCpfTratador(an[i][6], tratadores);
        if(nomeTratador.compare(tra) != 0){
            an.erase(an.begin() + i);
        } 
    };
}
void filtrarClasse(vector<vector<string>> &an, string classe){
    for(int i = (int) an.size()-1; 0 <= i ;  i--){
        if(an[i][7].substr(0, classe.size()).compare(classe) != 0) {
            an.erase(an.begin() + i);
        }
    };
}
void salvar(vector<vector<string>> &an,string nome_arquivo){
    fstream stream;
	stream.open("dados/" + nome_arquivo+".csv", ios::out | ios::trunc);
    for(int i =0; i < (int) an.size(); i++){
        for(int j = 0, k = 1; j < (int) an[i].size(); j++, k++){
            stream << an[i][j];
            if(k < (int) an[i].size()) stream << ",";
        }
        stream << endl;
    }
    stream.close();
}


int main(int argc, char const *argv[])
{

    if(argc == 1 || (argc%2) != 0){
        cout << "argumentos invalidos" << endl;
        exit(0);
    } 
    IO *io = new IO;
    vector<vector<string>> animais;
    vector<shared_ptr<Veterinario>> vet;
    vector<shared_ptr<Tratador>> tra;


    animais = io->carregarAnimais();
    for(int i = 1; i< argc; i+=2){
        string op = (string)argv[i];
        if(op.compare("-c") == 0) filtrarClasse(animais, argv[i+1]);
        if(op.compare("-v") == 0){
            vet = io->carregarVeterinarios();
            filtrarVeterinario(animais, vet, argv[i+1]);
        } 
        if(op.compare("-t") == 0){
            tra = io->carregarTratadores();
            filtrarTratador(animais, tra, argv[i+1]);
        }
        
    }
    salvar(animais, argv[argc-1]);
	delete io;
	return 0;
}
