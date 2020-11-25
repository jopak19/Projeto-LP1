#pragma once
#include "petfera.hpp"

using namespace std;

class Interface {

private:
    PetFera* pet;
    
public:
    void setPet(PetFera* p);
    void menu();
    void opcoes(string escolha);

    bool cadastroFuncionario(int tipo);
    bool cadastroTratador(string cpf, string nome, string dataNascimento);
    bool cadastroVeterinario(string cpf, string nome, string dataNascimento);

    bool alterarFuncionario(int tipo);
    bool apagarFuncionario(int tipo);
    bool consultarFuncionario(int tipo);
    
    bool cadastroAnimal();
    bool cadastroClasseAnimal(short classe, short manejo, string codigo, string peso, string altura, short idade, string especie, bool perigoso,  shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador);
    bool cadastroManejoAnimal(int tipo);

    //Validações
    bool validaCrmv(string codigoCrmv);
    //int validaCinInt(bool teste, int variavel);
};
