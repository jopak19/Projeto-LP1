#pragma once

#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include "io.hpp"
#include <vector>
#include <string>
#include <memory>

using std::shared_ptr;
using std::string;
using std::vector;

class PetFera {

    public:
       
        PetFera();
        ~PetFera();
        vector<shared_ptr<Animal>> getAnimais() const;
        vector<shared_ptr<Tratador>> getTratadores() const;
        vector<shared_ptr<Veterinario>> getVeterinarios() const;
        shared_ptr<Animal> getAnimal(string codigo) const; 
        shared_ptr<Veterinario> getVeterinario(string cpf) const;
        shared_ptr<Tratador> getTratador(string cpf) const;
        bool cadastrarAnimal(shared_ptr<Animal> animal, 
            string cpfTratador, string cpfVeterinario);
        bool cadastrarTratador(shared_ptr<Tratador> tratador);
        bool cadastrarVeterinario(shared_ptr<Veterinario> veterinario);
        bool realizarVenda(string codigoAnimal);
        bool removerTratador(string cpfTratador);
        bool removerVeterinario(string cpfVeterinario);
        bool removerAnimal(string codigoAnimal);
        bool existeAnimal(string codigoAnimal) const;
        bool existeTratador(string cpfTratador) const;
        bool existeVeterinario(string cpfVeterinario) const;
        void listarAnimais() const;
        void listarTratadores() const;
        void listarVeterinarios() const;

    private:

        string nome;
        vector<shared_ptr<Animal>> animais;
        vector<shared_ptr<Tratador>> tratadores;
        vector<shared_ptr<Veterinario>> veterinarios;
        IO *gerenciadorArquivos;
        void carregarDados();
        void salvarDados();
        void carregarDadosAnimais(vector<vector<string>> animais);
        void carregarInteracoes();
};
