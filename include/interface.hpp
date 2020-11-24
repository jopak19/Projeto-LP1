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

    
    //Validações
    bool validaCrmv(string codigoCrmv);
};
