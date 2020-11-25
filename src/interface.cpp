#include "interface.hpp"
using namespace std;

void Interface::setPet(PetFera* p){
    pet=p;
}

// Os métodos menu e opções servem para definir qual funcionalidade será utilizada pelo usuário.

void Interface::menu() {

    string escolha="";
    cout << "Escolha uma das opções abaixo para acessar:\n";
    cout << " 1-Gerenciar Tratador \n 2-Gerenciar Veterinário \n 3-Gerenciar Animal \n 4-Realizar Venda" << endl;
    cin >> escolha;

    if (escolha=="1" || escolha=="2" || escolha=="3"){
        opcoes(escolha);

    } else if(escolha=="4"){

    /*
    Nessa função realizar venda, é preciso passar o código do animal
    Então provavelmente vai ter que ter alguma coisa pro usuário
    Listar o animal e seus códigos para ele saber qual animal ele 
    está realizando a venda
    */


        //pet->realizarVenda();

    } else {
        cout << "Opção Inválida! Tente outra opção!\n"<< endl;
        menu();
    }
}

void Interface::opcoes(string escolha){

    string opcao="";
    cout << "Escolha uma das opções de gerenciamento:\n";
    cout << " 1-Cadastrar \n 2-Alterar \n 3-Remover \n 4-Consultar" << endl;
    cin >> opcao;

    if(not (opcao=="1" || opcao=="2" || opcao=="3" ||opcao=="4")){
       cout << "Opção Inválida! Tente outra." << endl;
       opcoes(escolha);

    } else {

        if(escolha=="1"){

            if(opcao=="1"){
                cadastroFuncionario(1);

            } else if(opcao=="2"){
                alterarFuncionario(1);

            } else if(opcao=="3"){
                apagarFuncionario(1);

            } else if(opcao=="4"){
                consultarFuncionario(1);
            }

        } else if(escolha=="2"){

            if(opcao=="1"){
                cadastroFuncionario(2);

            } else if(opcao=="2"){
                alterarFuncionario(2);

            } else if(opcao=="3"){
                apagarFuncionario(2);

            } else if(opcao=="4"){
                consultarFuncionario(2);
            }

        }else if(escolha=="3"){

            if(opcao=="1"){
                cadastroAnimal();

            } else if(opcao=="2"){
            //alterarAnimal();

            } else if(opcao=="3"){
            //apagarAnimal();

            } else if(opcao=="4"){
            //consultarAnimal();

            }
        }
    }
}

//Os metodos a seguir dividem o cadastro de funcionário em duas partes

bool Interface::cadastroFuncionario(int tipo){
        
	string cpf;
	string nome;
	string dataNascimento;
        
    cout << "======================CADASTRO FUNCIONÁRIO===================" << endl;
    cout << "Preencha os dados pessoais do funcionário solicitados a seguir.\n"
    << endl;
    cout << "Nome:" << endl;
    cin >> nome;
    //validaNome();
    cout << "CPF XXX.XXX.XXX-XX:" << endl;
    cin >> cpf;
    //validaCPF();
    cout << "Data de Nascimento XX/XX/XX:" << endl;
    cin >> dataNascimento;
    //validaData();
        
    if (tipo == 1){
        cadastroTratador(nome, cpf, dataNascimento);

    } else {
        cadastroVeterinario(nome, cpf, dataNascimento);
    }

    return true;
}

bool Interface::cadastroTratador(string cpf, string nome, string dataNascimento){

    string nivel="";
    cout << "Informe o nível de segurança.\n" << endl;
    cout << "1-Verde | 2-Vermelho | 3-Azul";
    cin >> nivel;

    if(nivel == "1"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Verde);
        pet->cadastrarTratador(tratador);

    } else if(nivel == "2"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Vermelho);
        pet->cadastrarTratador(tratador);
 
    } else if(nivel == "3"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Azul);
        pet->cadastrarTratador(tratador);

    } else {
        cout << "Opção Inválida, tente outra" << endl;
        cadastroTratador(nome, cpf, dataNascimento);
    }
    
    return true;
}

bool Interface::cadastroVeterinario(string cpf, string nome, string dataNascimento){

    string codigoCrmv="";
    cout << "Informe o código Crmv do veterinário\n" << endl;
    if(validaCrmv(codigoCrmv)){
        shared_ptr<Veterinario> veterinario = make_shared<Veterinario>(nome, cpf, dataNascimento,codigoCrmv);
        pet->cadastrarVeterinario(veterinario);

    } else {
        cout << "Código inválido, tente outro!" << endl;
        cadastroVeterinario(nome, cpf, dataNascimento);
    }
    return true;
}


//Método de alteração dos dados dos funionários
    
bool Interface::alterarFuncionario(int tipo){
//O usuário começa escolhendo o cpf do usuário que deseja alterar e o dado que será alterado.
    string escolha = "";
    string cpf = "";
    cout << "Informe cpf do funcionário para as alterações:" << endl;
    cin >> cpf;
    bool valida=false;
    cout << "Informe o que deseja alterar:" << endl;

    if(tipo == 1){
        cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Nivel de Segurança\n" << endl;

    } else {
        cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Código CRMV\n" << endl;
    }
    while (valida==false){
        cin >> escolha;
        if (escolha=="1" || escolha=="2" || escolha=="3" || escolha=="4"){
            valida = true;

        } else {
            cout << "Opção inválida, tente novamente" << endl;
        }
    } 

    //Aqui será feita a alteração baseada na escolha do usuário
    if (escolha=="1"){
        string newNome = "";
        cout << "Informe o novo nome:" << endl;
        cin >> newNome;

        if(tipo==1){
            if (pet->getTratador(cpf)!=NULL){
                pet->getTratador(cpf)->setNome(newNome);
                cout << "Nome alterado!" << endl;

            } else {
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if (pet->getVeterinario(cpf)!=NULL){
                pet->getVeterinario(cpf)->setNome(newNome);
                cout << "Nome alterado!" << endl;

            }else{
                cout << "Veterinario não encontrado." << endl;
            }
        }

    } else if (escolha=="2"){
        string newCpf = "";
        cout << "Informe o novo cpf:" << endl;
        cin >> newCpf;

        if(tipo==1){
            if (pet->getTratador(cpf)!=NULL){
                pet->getTratador(cpf)->setCpf(newCpf);
                cout << "CPF alterado!" << endl;
            }else{
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if (pet->getVeterinario(cpf)!=NULL){
                pet->getVeterinario(cpf)->setCpf(newCpf);
                cout << "CPF alterado!" << endl;

            } else {
                cout << "Veterinario não encontrado." << endl;
            }
        }

    } else if (escolha=="3"){

        string newData = "";
        cout << "Informe o nova Data de Nascimeto:" << endl;
        cin >> newData;

        if(tipo==1){
            if (pet->getTratador(cpf)!=NULL){
                pet->getTratador(cpf)->setDataNascimento(newData);
                cout << "Data alterada!" << endl;

            } else {
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if (pet->getVeterinario(cpf)!=NULL){
                pet->getVeterinario(cpf)->setDataNascimento(newData);
                cout << "Data alterada!" << endl;

            } else {
                cout << "Veterinario não encontrado." << endl;
            }
        }

    } else if (escolha=="4"){

        if(tipo==1){
            string newNivel="";
            NivelSeguranca novoNivel;
            cout << "Informe o nível de segurança.\n" << endl;
            cout << "1-Verde | 2-Vermelho | 3-Azul";
            valida=false;

            while (valida==false){

                cin >> newNivel;

                if (newNivel=="1" || newNivel=="2" || newNivel=="3"){
                    valida = true;

                } else {
                    cout << "Opção inválida, tente outra." << endl;
                }
            }

            if (pet->getTratador(cpf)!=NULL){

                if(newNivel=="1"){
                    novoNivel = Verde;

                } else if (newNivel=="2"){
                    novoNivel = Vermelho;

                } else{
                    novoNivel = Azul;
                }

                pet->getTratador(cpf)->setNivelSeguranca(novoNivel);
                cout << "Nivel alterada!" << endl;

                } else{
                    cout << "Tratador não encontrado." << endl;
                }

        } else {
            string newCodigo="";
            cout << "Informe o novo código do veterinário\n" << endl;
            cin >> newCodigo;
            valida = false;

            while (valida==false){
                cin >> newCodigo;

                if(not validaCrmv(newCodigo)){
                    cout <<  "Código Inválido, tente outro." << endl;

                }

                valida = validaCrmv(newCodigo);
            }

            if (pet->getVeterinario(cpf)!=NULL){
                pet->getVeterinario(cpf)->setCodigoCrmv(newCodigo);
                cout << "Código alterado!" << endl;

            }else{
                cout << "Veterinario não encontrado." << endl;

            }
        }   
    }
    return true;    
}

bool Interface::apagarFuncionario(int tipo){
    string cpf="";
    if(tipo==1){
        cout << "Informe CPF do Tratador que deseja remover." << endl;
        cin >> cpf;

        if(pet->removerTratador(cpf)){
             cout << "Tratador removido." << endl;

        } else{
            cout << "Tratador não encontrado." << endl; 
        }  

    } else {
        cout << "Informe CPF do Veterinario que deseja remover." << endl;
        cin >> cpf;

        if(pet->removerVeterinario(cpf)){
             cout << "Veterinário removido." << endl;

        } else {
            cout << "Veterinário não encontrado." << endl; 
        } 
    }
    return true;
}


//Consulta de Funcionario
bool Interface::consultarFuncionario(int tipo){ 

    string escolha="";
    cout << "Escolha o tipo de busca: 1- Por CPF | 2- Listar Todos" << endl;
    cin >> escolha;

    if (escolha == "1"){

        string cpf="";
        cout << "Informe CPF do funcionário que deseja buscar." << endl;
        cin >> cpf;

        if(tipo==1){

            if(pet->getTratador(cpf)){
                cout << *pet->getTratador(cpf) << endl; 
            } else{
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if(pet->getVeterinario(cpf)){
                cout << *pet->getVeterinario(cpf) << endl; 

            } else{
                cout << "Tratador não encontrado." << endl;
            }
        }

    } else if(escolha=="2"){

        if(tipo==1){
            pet->listarTratadores();

        }else{
            pet->listarVeterinarios();

        }

    } else{
        cout << "Opção Inválida, tente outra." << endl;
        consultarFuncionario(tipo);
    }
    return true;
}

//Os três métodos seguintes cadastram os animais do petFera

bool Interface::cadastroAnimal(){
    string codigo="";
    string peso="";
    string altura="";
    short idade=0;
    string especie="";
    bool perigoso;
    short classe=0;
    short manejo=0;   
 
    shared_ptr<Tratador> tratador;
    shared_ptr<Veterinario> veterinario;
    string cpf="";

    string sair="";

    cout << "======================CADASTRO ANIMAL======================" << endl;
    cout << "Informe os dados gerais do animal que deseja cadastrar." << endl;
    cout << "PESO e ALTURA respectivamente:" << endl;
    cin >> peso >> altura;
    cout << "Idade do animal:" << endl;
        
    while (true){

        if (!(cin >> idade)){
            cout << "Idade inválida, tente novamente." << endl;
            cin.clear();
            cin.ignore(1000,'\n');

        }else{
           break;

        }

    }

    cout << "Espécie (ex.: tartaruga, águia, etc.):" << endl;
    cin >> especie;
    cout << "O animal é perigoso ou venenoso? 0-NÃO | 1-SIM" << endl;

    while (true){

        if (cin >> perigoso){
            break;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n');   
        }

    }
    
    codigo = especie + to_string(pet->getAnimais().size());
    
    cout << "Informe a classificação do animal: 1-Anfíbio | 2-Réptil | 3-Ave | 4-Mamifero " << endl;

    while (true){

        if (cin >> classe && (classe == 1 || classe == 2 || classe == 3 || classe == 4)){
            break;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }

    cout << "Informe o tipo do animal: 1-Doméstico | 2-Silvestre Nativo | 3-Silvestre Exótico" << endl;

    while (true){

        if (cin >> manejo && (manejo == 1 || manejo == 2 || manejo == 3)){
            break;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }
    //Associar tratador e veterinário
    cout << "Informe o CPF do veterinário desse animal:" << endl;
  
    while (true){

        cin >> cpf;
        if (pet->getVeterinario(cpf)){
            break;

        }else{
            cout << "Veterinário não encontrado! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
            cin >> sair;
            
            if (sair == "1"){
                return false;
            }

            cout << "CPF: ";
        }
    }
    
    veterinario = pet->getVeterinario(cpf);

    cout << "Informe o CPF do tratador desse animal:" << endl;
    cin >> cpf; 
   
    while (true){

        cin >> cpf;
        if (pet->getTratador(cpf)){
            
            if (pet->getTratador(cpf)->getNivelSeguranca() == Vermelho){
                break;
            }else if (pet->getTratador(cpf)->getNivelSeguranca() == Azul && perigoso == false && (classe == 2 || classe == 3 || classe == 4)){
                break;
            }else if (pet->getTratador(cpf)->getNivelSeguranca() == Verde && perigoso == false && classe == 3){
                break;
            }

        }else{
            cout << "Tratador inválido para o animal! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
            cin >> sair;
            
            if (sair == "1"){
                 return false;

            }

            cout << "CPF: ";

        }
    }

    
    tratador = pet->getTratador(cpf);

    cadastroClasseAnimal(classe, manejo, codigo, peso, altura, idade, especie, perigoso, veterinario, tratador); //Acrescentar Tratador e Veterinário

    return true;
}

//Esse método prossegue o cadastro do animal baseado na classificação escolhida
bool Interface::cadastroClasseAnimal(short classe, short manejo, string codigo, string peso, string altura, short idade, string especie, bool perigoso, shared_ptr<Veterinario> veterinario, shared_ptr<Tratador> tratador){
    
    bool valida=false;

    switch (classe){
    
        case 1:{ //Anfíbio

            string periodoDeMudaDePele="";
            int temperaturaDoAmbiente=0;

            cout << "Informe o período de muda de pele do animal" << endl;
            cin >> periodoDeMudaDePele;
            cout << "Informe a temperatura média do ambiente para o animal." << endl;

            while (!valida){

                if (cin >> temperaturaDoAmbiente){
                    valida=true;

                }else{
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }

            }

            if (manejo == 1){
                //Cadastrar

            }else if (manejo ==2) {
                //Aqui vou passar todos os dados para o método de NATIVO

            }else{
                //Aqui vou passar todos os dados para o método de EXÓTICO
            }

            break;
        }
        case 2:{ //Réptil


            break;
        }
        case 3:{ //Ave

            break;
        }
        case 4:{ //Mamífero

            break;
        }
    }


    return true;
}

//Validações
bool Interface::validaCrmv(string codigoCrmv){
    return true;
}

/*int Interface::validaCinInt(bool teste, int variavel){
   
    while (true){

        if (teste){
    
            return variavel;

        }else{

            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }
    return variavel;
}*/

