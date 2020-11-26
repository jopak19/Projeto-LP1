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
    bool alteraMarcacao(string classe, string codigo);
    bool alteraExtincao(string classe, string codigo);

    //exotico
    string solicitaTerritorio();
    bool alteraTerritorio(string classe, string codigo);
    //nativo
    Bioma solicitaBioma();  
    bool alteraBioma(string classe, string codigo);

    bool venderAnimal();
    bool apagarAnimal();
    bool consultarAnimal();
    bool alteracaoAnimal();
    
    //Validações
    int validaInt(int num);
    bool validaBool(bool boleano);
    bool validaCrmv(string codigoCrmv);
    string animalExiste();
    bool validaData(string data);
    bool validaCPF(string cpf);
    bool validaNome(string nome);
};
