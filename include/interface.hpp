#pragma once
#include "petfera.hpp"
#include "anfibionativo.hpp"
#include "anfibioexotico.hpp"
#include "reptilnativo.hpp"
#include "reptilexotico.hpp"
#include "aveexotico.hpp"
#include "avenativo.hpp"
#include "mamiferonativo.hpp"
#include "mamiferoexotico.hpp"
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
    bool cadastroClasseAnimal(short classe, short manejo, string codigo, string peso, string altura, short idade, string especie, bool perigoso,   string cpfveterinario, string cpftratador);
    
    //silvestre
    int solicitaMarcacao();
    bool solicitaExtincao();

    //exotico
    string solicitaTerritorio();

    //nativo
    Bioma solicitaBioma();  

    bool venderAnimal();
    bool apagarAnimal();
    bool consultarAnimal();
    
    //Validações
    bool validaCrmv(string codigoCrmv);
    string animalExiste();
};
