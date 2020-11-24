#include "interface.hpp"

void Interface::setPet(PetFera* p){
    pet=p;
}

// Os métodos menu e opções servem para definir qual funcionalidade será utilizada pelo usuário.

void Interface::menu(){
   string escolha="";
   cout << "Escolha uma das opções abaixo para acessar:\n";
   cout << " 1-Gerenciar Tratador \n 2-Gerenciar Veterinário \n 3-Gerenciar Animal \n 4-Realizar Venda" << endl;
   cin >> escolha;
   if(escolha=="1" || escolha=="2" || escolha=="3"){
        opcoes(escolha);
   }else if(escolha=="4"){

    /*
    Nessa função realizar venda, é preciso passar o código do animal
    Então provavelmente vai ter que ter alguma coisa pro usuário
    Listar o animal e seus códigos para ele saber qual animal ele 
    está realizando a venda
    */


        //pet->realizarVenda();

   }else{
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
    }else{
        if(escolha=="1"){
            if(opcao=="1"){
            cadastroFuncionario(1);
            }else if(opcao=="2"){
            alterarFuncionario(1);
            }else if(opcao=="3"){
            //apagarTratador();
            }else if(opcao=="4"){
            //consultarTratador();
            }
        }else if(escolha=="2"){
            if(opcao=="1"){
            cadastroFuncionario(2);
            }else if(opcao=="2"){
            alterarFuncionario(2);
            }else if(opcao=="3"){
            //apagarVeterinario();
            }else if(opcao=="4"){
            //consultarVeterinario();
            }
        }else if(escolha=="3"){
            if(opcao=="1"){
            //cadastroAnimal();
            }else if(opcao=="2"){
            //alterarAnimal();
            }else if(opcao=="3"){
            //apagarAnimal();
            }else if(opcao=="4"){
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
        }else{
            cadastroVeterinario(nome, cpf, dataNascimento);
        }

        return true;
}

    bool Interface::cadastroTratador(string cpf, string nome, string dataNascimento)
{
        string nivel="";
        cout << "Informe o nível de segurança.\n" << endl;
        cout << "1-Verde | 2-Vermelho | 3-Azul";
        cin >> nivel;
        if(nivel == "1"){
             Tratador* tratador = new Tratador(nome, cpf, dataNascimento,Verde);
             //adicionar tratador ao petfera
        }else if(nivel == "2"){
            Tratador* tratador = new Tratador(nome, cpf, dataNascimento,Vermelho);
             //adicionar tratador ao petfera
        }else if(nivel == "3"){
            Tratador* tratador = new Tratador(nome, cpf, dataNascimento,Azul);
             //adicionar tratador ao petfera
        }else{
            cout << "Opção Inválida, tente outra" << endl;
            cadastroTratador(nome, cpf, dataNascimento);
        }
    
        return true;
}
    bool Interface::cadastroVeterinario(string cpf, string nome, string dataNascimento){
        string codigoCrmv="";
        cout << "Informe o código Crmv do veterinário\n" << endl;
        if(validaCrmv(codigoCrmv)){
            Veterinario* veterinario = new Veterinario(nome, cpf, dataNascimento,codigoCrmv);
        }else{
            cout << "Código inválido, tente outro!" << endl;
            cadastroVeterinario(nome, cpf, dataNascimento);
        }
        return true;
}


//Método de alteração dos dados dos funionários
    
    bool Interface::alterarFuncionario(int tipo){
//O usuário começa escolhando o cpf do usuário que deseja alterar e o dado que será alterado.
         string escolha = "";
         string cpf = "";
         cout << "Informe cpf do funcionário para as alterações:" << endl;
         cin >> cpf;
         bool valida=false;
         cout << "Informe o que deseja alterar:" << endl;
         if(tipo == 1){
              cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Nivel de Segurança\n" << endl;
         }else{
              cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Código CRMV\n" << endl; 
         while (valida==false){
            cin >> escolha;
            if (escolha=="1" || escolha=="2" || escolha=="3" || escolha=="4"){
                valida = true;
            }else{
                 cout << "Opção inválida, tente novamente" << endl;
            }
         } 
}
//Aqui será ferita a alteração baseada na escolha do usuário
        Funcionario *pessoa; //=================================================================================
        if(tipo==1){
            Tratador pessoa1 = *pet->getTratador(cpf);
            pessoa = &pessoa1;
        }else{
            Veterinario pessoa1 = *pet->getVeterinario(cpf);
            pessoa = &pessoa1;
        }//=====================================================================================================
        
        switch(stoi(escolha)){
            case 1 :
                {
                string newNome = "";
                cout << "Informe o novo nome:" << endl;
                cin >> newNome;
                pessoa->alterarDados(pessoa->getCpf(),newNome,pessoa->getDataNascimento());
                break;
                }
            case 2 :
                {
                string newCpf = "";
                cout << "Informe o novo cpf:" << endl;
                cin >> newCpf;
                //altera
                break;
                }
            case 3 :
                {
                string newData = "";
                cout << "Informe o novo cpf:" << endl;
                cin >> newData;
                //altera
                break;
                }
            case 4 :
                {
                if(tipo==1){
                    string newNivel="";
                    cout << "Informe o nível de segurança.\n" << endl;
                    cout << "1-Verde | 2-Vermelho | 3-Azul";
                    valida=false;
                    while (valida==false){
                        cin >> newNivel;
                        if (newNivel=="1" || newNivel=="2" || newNivel=="3"){
                        valida = true;
                        }else{
                        cout << "Opção inválida, tente outra." << endl;
                        }
                    }
                    //pessoa1->setNivelSeguranca(Verde);===============================================================
                }else{
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
                    //alterar;===============================================================
                    
                }
                break;
                }
                
        }
    
       return true;    
}




//Validações
    bool Interface::validaCrmv(string codigoCrmv){
        return true;
}

