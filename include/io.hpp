#pragma once

#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include "nivelseguranca.hpp"

#include "ave.hpp"
#include "anfibio.hpp"
#include "reptil.hpp"
#include "mamifero.hpp"
#include "anfibionativo.hpp"
#include "anfibioexotico.hpp"
#include "reptilnativo.hpp"
#include "reptilexotico.hpp"
#include "aveexotico.hpp"
#include "avenativo.hpp"
#include "mamiferonativo.hpp"
#include "mamiferoexotico.hpp"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::shared_ptr;
using std::vector;

#include <memory>

class IO {

public:

	IO();
	bool salvarAnimais(vector<shared_ptr<Animal>> animais);
	bool salvarVeterinarios(vector<shared_ptr<Veterinario>> veterinarios);
	bool salvarTratadores(vector<shared_ptr<Tratador>> tratadores);

	vector<vector<string>> carregarAnimais() const;
	vector<shared_ptr<Veterinario>> carregarVeterinarios() const;
	vector<shared_ptr<Tratador>> carregarTratadores() const;

private:
    string atributosExtrasAnimais(shared_ptr<Animal> animal);
    
};
