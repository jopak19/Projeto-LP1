#pragma once

#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class PetFera {

    public:
       
        // PetFera(string nome, int identificador); TODO
        // ~PetFera(); TODO
        //string getNome() const;
        //int getIdentificador() const;
        vector<shared_ptr<Animal>> getAnimais() const;
        vector<shared_ptr<Tratador>> getTratadores() const;
        vector<shared_ptr<Veterinario>> getVeterinarios() const;
        shared_ptr<Animal> getAnimal(string codigo) const;
        shared_ptr<Veterinario> getVeterinario(string cpf) const;
        shared_ptr<Tratador> getTratador(string cpf) const;
        bool cadastrarAnimal(shared_ptr<Animal> animal);
        bool cadastrarTratador(shared_ptr<Tratador> tratador);
        bool cadastrarVeterinario(shared_ptr<Veterinario> veterinario);
        bool realizarVenda();
        bool removerTratador();
        bool removerVeterinario();
        void editarAnimal(shared_ptr<Animal> animal);
        void editarTratador(shared_ptr<Tratador> tratador);
        void editarVeterinario(shared_ptr<Veterinario> veterinario);
        void listarAnimais() const;
        void listarTratadores() const;
        void listarVeterinarios() const;

    

    private:

        string nome;
        int identificador;
        vector<shared_ptr<Animal>> animais;
        vector<shared_ptr<Tratador>> tratadores;
        vector<shared_ptr<Veterinario>> veterinarios;
};
