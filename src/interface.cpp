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
        pet->realizarVenda();
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
            //alterarTratador();
            }else if(opcao=="3"){
            //apagarTratador();
            }else if(opcao=="4"){
            //consultarTratador();
            }
        }else if(escolha=="2"){
            if(opcao=="1"){
            cadastroFuncionario(2);
            }else if(opcao=="2"){
            //alterarVeterinario();
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
        cout << "1-Verde\n2-Vermelho\n3-Azul";
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


//Validações
    bool Interface::validaCrmv(string codigoCrmv){
        return true;
}

