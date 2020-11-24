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

   if(escolha=="1" || escolha=="2" || escolha=="3"){
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
            //cadastroAnimal();

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

//Validações
bool Interface::validaCrmv(string codigoCrmv){
    return true;
}

