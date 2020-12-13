#pragma once

#include "animal.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"

#include <fstream>
#include <vector>
#include <string>

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

	vector<shared_ptr<Animal>> carregarAnimais() const;
	vector<shared_ptr<Veterinario>> carregarVeterinarios() const;
	vector<shared_ptr<Tratador>> carregarTratadores() const;
};