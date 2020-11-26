#include "interface.hpp"
using namespace std;

void Interface::setPet(PetFera* p){
    pet=p;
}

// Os métodos menu e opções servem para definir qual funcionalidade será utilizada pelo usuário.

void Interface::menu() {
    while(true){
        string escolha="";
        cout << "" << endl;
        cout << "========================MENU INICIAL==================" << endl;
        cout << "Escolha uma das opções abaixo para acessar:" << endl;
        cout << " 1-Gerenciar Tratador \n 2-Gerenciar Veterinário \n 3-Gerenciar Animal \n 4-Realizar Venda \n 5-Sair" << endl;
        cin >> escolha;

        if (escolha=="1" || escolha=="2" || escolha=="3"){
            opcoes(escolha);

        } else if(escolha=="4"){
           
            if(!venderAnimal()){
                cout << "Venda não realizada!"<< endl;
            }
            
        } else if(escolha=="5"){
            break;
        }else {
            cout << "Opção Inválida! Tente outra opção!"<< endl;
        }
    }
}

void Interface::opcoes(string escolha){

    string opcao="";
    cout << "Escolha uma das opções de gerenciamento:" << endl;
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
                if(!apagarAnimal()){
                cout << "Nenhum animal foi removido!"<< endl;
                }

            } else if(opcao=="4"){
                consultarAnimal();

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
    while (true){
        cin.ignore();
        getline (cin,nome);
        if(validaNome(nome)){
            break;
        }else{
            cout << "Nome inválido, tente novamente." << endl;
        }

    }
    cout << "CPF XXX.XXX.XXX-XX:" << endl;
    
    while (true){

        getline (cin,cpf);
        if(validaCPF(cpf)){
            break;
        }else{
            cout << "Formato incorreto, tente novamente." << endl;
        }

    }

    cout << "Data de Nascimento XX/XX/XXXX:" << endl;

    while (true){

        getline (cin,dataNascimento);
        if(validaData(dataNascimento)){
            break;
        }else{
            cout << "Formato incorreto, tente novamente." << endl;
        }

    }
        
    bool cadastrado = false;

    if (tipo == 1){

        cadastrado = cadastroTratador(nome, cpf, dataNascimento);
        if(!cadastrado){
            cout << " " << endl;
            cout << "Cadastro não realizado. Já existe Tratador com esse CPF!" << endl;
            return false;
        }

    } else {
        cadastrado = cadastroVeterinario(nome, cpf, dataNascimento);

        if(!cadastrado){
            cout << " " << endl;
            cout << "Cadastro não realizado. Já existe Veterinario com esse CPF!" << endl;
            return false;
        }
    }

    return true;
}

bool Interface::cadastroTratador(string cpf, string nome, string dataNascimento){

    string nivel="";
    cout << "Informe o nível de segurança.\n" << endl;
    cout << "1-Verde | 2-Vermelho | 3-Azul\n";
    cin >> nivel;
    bool cadastrado = false;

    if(nivel == "1"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Verde);
        cadastrado = pet->cadastrarTratador(tratador);

    } else if(nivel == "2"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Vermelho);
        cadastrado = pet->cadastrarTratador(tratador);
 
    } else if(nivel == "3"){
        shared_ptr<Tratador> tratador = make_shared<Tratador>(nome, cpf, dataNascimento,Azul);
        cadastrado = pet->cadastrarTratador(tratador);

    } else {
        cout << "Opção Inválida, tente outra" << endl;
        cadastrado = cadastroTratador(nome, cpf, dataNascimento);
    }
    
    return cadastrado;
}

bool Interface::cadastroVeterinario(string cpf, string nome, string dataNascimento){

    string codigoCrmv="";
    cout << "Informe o código Crmv do veterinário" << endl;
    cin >> codigoCrmv;

    bool cadastrado = false;

    if(validaCrmv(codigoCrmv)){
        shared_ptr<Veterinario> veterinario = make_shared<Veterinario>(nome, cpf, dataNascimento,codigoCrmv);
        cadastrado = pet->cadastrarVeterinario(veterinario);

    } else {
        cout << "Código inválido, tente outro!" << endl;
        cadastrado = cadastroVeterinario(nome, cpf, dataNascimento);
    }
    return cadastrado;
}


//Método de alteração dos dados dos funionários
    
bool Interface::alterarFuncionario(int tipo){
//O usuário começa escolhendo o cpf do usuário que deseja alterar e o dado que será alterado.
    string escolha = "";
    string cpf;
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

        while (true){

            cin >> newNome;
            if(validaNome(newNome)){
                break;
            }else{
                cout << "Nome inválido, tente novamente." << endl;
            }

        }

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

        while (true){

            cin >> newCpf;
            if(validaCPF(newCpf)){
                break;
            }else{
                cout << "Formato incorreto, tente novamente." << endl;
            }

        }

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

        while (true){

            cin >> newData;
            if(validaData(newData)){
                break;
            }else{
                cout << "Formato incorreto, tente novamente." << endl;
            }

        }

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

/*Os dois métodos seguintes cadastram os animais
 do petFera, além disso são usados quatro métodos
 auxiliares para o caso de animais silvestres*/

bool Interface::cadastroAnimal(){
    string codigo="";
    string peso="";
    string altura="";
    short idade=0;
    string especie="";
    bool perigoso;
    short classe=0;
    short manejo=0;   
 
    string cpftratador;
    string cpfveterinario;
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

    /*Aqui serão válidados o tratador e o veterinário do animal, 
        de forma que será possível prosseguir a operação apenas 
        se ambos estiverem cadastrados e o tratador tiver o 
        nível de segurança correto */

    cout << "Informe o CPF do veterinário desse animal:" << endl;
  
    while (true){

        cin >> cpfveterinario;
        if (pet->getVeterinario(cpfveterinario)){
            break;

        }else{
            cout << "Veterinário não encontrado! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
            cin >> sair;
            
            if (sair == "1"){
                return false;
            }
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "CPF: ";
        }
    }
    

    cout << "Informe o CPF do tratador desse animal:" << endl;
   
    while (true){

        cin >> cpftratador ;
        if (pet->getTratador(cpftratador)){
            
            if (pet->getTratador(cpftratador)->getNivelSeguranca() == Vermelho){
                break;
            }else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Azul && perigoso == false && (classe == 2 || classe == 3 || classe == 4)){
                break;
            }else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Verde && perigoso == false && classe == 3){
                break;
            }else{
                cout << "Tratador inválido para o animal! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
                cin >> sair;
            
                if (sair == "1"){
                    return false;
            
                }

                cin.clear();
                cin.ignore(1000,'\n');

                cout << "CPF: ";

            }

        }else{
            cout << "Tratador não encontrado! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
            cin >> sair;
            
            if (sair == "1"){
                 return false;
            
            }
            cin.clear();
            cin.ignore(1000,'\n');

            cout << "CPF: ";

        }
    }


    cadastroClasseAnimal(classe, manejo, codigo, peso, altura, idade, especie, perigoso, cpfveterinario, cpftratador); //Acrescentar Tratador e Veterinário

    return true;

}

//Esse método prossegue o cadastro do animal baseado na classificação escolhida

bool Interface::cadastroClasseAnimal(short classe, short manejo, string codigo, string peso, string altura, short idade, string especie, bool perigoso, string cpfveterinario, string cpftratador){
    
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
        
            //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Anfibio> anfibio = make_shared<Anfibio>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, temperaturaDoAmbiente, perigoso);
                pet->cadastrarAnimal(anfibio, cpftratador, cpfveterinario);
                cout << "Anfíbio doméstico cadastrado: " << codigo << endl;

            }else if (manejo ==2) { //Nativo

                shared_ptr<AnfibioNativo> anfibio = make_shared<AnfibioNativo>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, temperaturaDoAmbiente, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                 pet->cadastrarAnimal(anfibio, cpftratador, cpfveterinario);
                 cout << "Anfíbio Silvestre Nativo cadastrado: " << codigo << endl;

            }else{ //Exótico

                shared_ptr<AnfibioExotico> anfibio = make_shared<AnfibioExotico>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, temperaturaDoAmbiente, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(anfibio, cpftratador, cpfveterinario);
                cout << "Anfíbio Silvestre Exótico cadastrado: " << codigo << endl;
            }


            break;
        }
        case 2:{ //Réptil
        
            string periodoDeMudaDePele="";
            string tipo;
            TipoDePele tipoDePele;

            cout << "Informe o período de muda de pele do animal" << endl;
            cin >> periodoDeMudaDePele;
            cout << "Informe o tipo de pele do animal: 1- ESCAMAS | 2-CARAPACA | 3-PLACADERMICA" << endl;

            while (true){
                
                cin >> tipo;
                if (tipo == "1"){
                    tipoDePele = ESCAMAS;
                    break;

                }else if (tipo== "2"){
                    tipoDePele = CARAPACA;
                    break;

                }else if (tipo == "3"){
                    tipoDePele = PLACADERMICA;
                    break;

                }else{
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }

            }
        

             //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Reptil> reptil = make_shared<Reptil>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Réptil doméstico cadastrado: " << codigo << endl;

            }else if (manejo ==2) { //Nativo

                shared_ptr<ReptilNativo> reptil = make_shared<ReptilNativo>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Réptil Silvestre Nativo cadastrado: " << codigo << endl;

            }else{ //Exótico

                shared_ptr<ReptilExotico> reptil = make_shared<ReptilExotico>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Rétpil Silvestre Exótico cadastrado: " << codigo << endl;
            }

            break;
        }
        case 3:{ //Ave

            bool aquatica;
            bool podeVoar;

            cout << "A ave é aquática? 0-NÃO | 1-SIM" << endl;
            
            while (true){

                if (cin >> aquatica){
                    break;

                }else{
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }

            }

            cout << "A ave voa? 0-NÃO | 1-SIM " << endl;

            while (true){

                if (cin >> podeVoar){
                    break;

                }else{
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }

            }


             //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Ave> ave = make_shared<Ave>(codigo, peso, altura, idade, especie, aquatica, podeVoar, perigoso);
                pet->cadastrarAnimal(ave, cpftratador, cpfveterinario);
                cout << "Ave doméstico cadastrado: " << codigo << endl;

            }else if (manejo ==2) { //Nativo

                shared_ptr<AveNativo> ave = make_shared<AveNativo>(codigo, peso, altura, idade, especie, aquatica, podeVoar, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(ave, cpftratador, cpfveterinario);
                cout << "Ave Silvestre Nativo cadastrado: "  << codigo << endl;

            }else{ //Exótico

                shared_ptr<AveExotico> ave = make_shared<AveExotico>(codigo, peso, altura, idade, especie, aquatica, podeVoar, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(ave, cpftratador, cpfveterinario);
                cout << "Ave Silvestre Exótico cadastrado: " << codigo << endl;
            }


            break;
        }
        case 4:{ //Mamífero

            Gestacao gestacao;
            string escolha = ""; 
            cout << "Informe o tipo de gestação do animal: 1-MONOTREMADO | 2-MARSUPIAL | 3-PLACENTARIO" << endl;

            while (true){
                
                cin >> escolha;
                if (escolha == "1"){
                    gestacao= MONOTREMADO;
                    break;

                }else if (escolha== "2"){
                    gestacao = MARSUPIAL;
                    break;

                }else if (escolha == "3"){
                    gestacao = PLACENTARIO;
                    break;

                }else{
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }

            }

            //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Mamifero> mamifero = make_shared<Mamifero>(codigo, peso, altura, idade, especie, gestacao, perigoso);
                pet->cadastrarAnimal(mamifero, cpftratador, cpfveterinario);
                cout << "Mamífero doméstico cadastrado: "<< codigo << endl;

            }else if (manejo ==2) { //Nativo

                shared_ptr<MamiferoNativo> mamifero = make_shared<MamiferoNativo>(codigo, peso, altura, idade, especie,  gestacao, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(mamifero, cpftratador, cpfveterinario);
                cout << "Mamífero Silvestre Nativo cadastrado: " << codigo << endl;

            }else{ //Exótico

                shared_ptr<MamiferoExotico> mamifero = make_shared<MamiferoExotico>(codigo, peso, altura, idade, especie,  gestacao, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(mamifero, cpftratador, cpfveterinario);
                cout << "Mamífero Silvestre Exótico cadastrado: " << codigo << endl;
            }

            break;
        }
    }


    return true;
}

//Os métodos a seguir solicitam os demais dados para animais Silvestres nativos e exóticos

int Interface::solicitaMarcacao(){

    int marcacao=0;
    cout << "Informe o número de marcação permanente do animal de acordo com o orgão responsável:" << endl;    

    while (true){

        if (cin >> marcacao){
            return marcacao;

        }else{
            cout << "Opção inválida, tente um inteiro." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }
    return 0;
}


bool Interface::solicitaExtincao(){

    bool extincao;
    cout << "A espécie corre risco de extinção? 0-NÃO | 1-SIM" << endl;

    while (true){

        if (cin >> extincao){
            return extincao;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }
    return false;
}


string Interface::solicitaTerritorio(){

    string territorio="";
    cout << "Informe o território de origem do animal" << endl;
    cin >> territorio;
    return territorio;

}


Bioma Interface::solicitaBioma(){
    string escolha="";
    cout << "Informe o bioma de origem do animal: 1-AMAZONIA | 2-CAATINGA | 3-PAMPA | 4-CERRADO | 5-PANTANAL | 6-MATAATLANTICA" << endl;
    
    while (true){
        cin >> escolha;
        if (escolha == "1"){

            return AMAZONIA;
        
        }else if(escolha == "2"){

            return CAATINGA;

        }else if(escolha == "3"){

            return PAMPA;

        }else if(escolha == "4"){

            return CERRADO;

        }else if(escolha == "5"){

            return PANTANAL;

        }else if(escolha == "6"){

            return MATAATLANTICA;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }

} 


//VenderAnimal

bool Interface::venderAnimal(){
    string codigo="";
    cout << "Informe o código do animal que será vendido:" << endl;
    codigo = animalExiste();

    if (codigo == ""){
        return false;
    }

    pet->realizarVenda(codigo);
    cout << "Venda Realizada!" << endl;
    return true;

}

//ApagarAnimal

bool Interface::apagarAnimal(){

    string codigo="";
    cout << "Informe o código do animal que deseja apagar:" << endl;
    codigo = animalExiste();

    if (codigo == ""){
        return false;
    }
    pet->removerAnimal(codigo);
    cout << "Animal Removido!" << endl;
    return true;
}


//Consultar Animal

bool Interface::consultarAnimal(){
    int escolha;
    cout << "Informe o tipo de consulta que deseja realizar: " << endl;
    cout << "1-Por Veterinário | 2-Por Tratador | 3-Por Classe | 4-Listar Todos | 5-Por código | 6-Por Espécie"  << endl;

    while (true){

        if (cin >> escolha && (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6)){
            break;

        }else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }

    }

    switch (escolha){

        case 1:{

            string cpf = "";
            string sair = "";
            cout << "Informe o CPF do veterinário:" << endl;
  
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

                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "CPF: ";
                }
            }

            int tamanho = pet->getVeterinario(cpf)->getAnimaisTratados().size();
            if (tamanho == 0){
                cout << "Esse veterinário ainda não tratou nenhum animal!" << endl;
            }else{
                for (int i = 0; i < tamanho; i++){
                    cout << "entrou" << endl;
                    cout << *((pet->getVeterinario(cpf))->getAnimaisTratados())[i] << endl;
                }
            }  

            break;

        }
        case 2:{

            string cpf = "";
            string sair = "";
            cout << "Informe o CPF do tratador:" << endl;
  
            while (true){

                cin >> cpf;
                if (pet->getTratador(cpf)){

                    break;

                }else{
                    cout << "Veterinário não encontrado! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
                    cin >> sair;
 
                    if (sair == "1"){
                        return false;
                    }

                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "CPF: ";
                }
            }

            int tamanho = pet->getTratador(cpf)->getAnimaisTratados().size();
            if (tamanho == 0){
                cout << "Esse veterinário ainda não tratou nenhum animal!" << endl;
            }else{
                for (int i = 0; i < tamanho; i++){
                    cout << *((pet->getTratador(cpf))->getAnimaisTratados())[i] << endl;
                }
            }  

             break;
        }
        case 3:{
             break;
        }
        case 4:{

             pet->listarAnimais();
             break;

        }
        case 5:{

             string codigo;
             cout << "Informe o código do animal:" << endl;
             codigo = animalExiste();

             if (codigo==""){
                return false;
             }else{
                cout << *pet->getAnimal(codigo) << endl;
             } 

             break;

        }
        case 6:{

             string especie;
             cout << "Informe a espécie que deseja buscar:" << endl;
             cin >> especie;

             int tamanho = pet->getAnimais().size();

             cout << "------------------Animais Encontrados-----------------" << endl;
             for (int i = 0; i < tamanho; i++){
                
                if (pet->getAnimais()[i]->getEspecie() == especie){
                    cout << *pet->getAnimais()[i] << endl;
                }

             }

             break;
        }
    }
    return true;
}


//Seguem alguns métodos auxiliares para validação


string Interface::animalExiste(){
    string sair;
    string codigo="";
    while (true){

        cin >> codigo;
                
        if(pet->getAnimal(codigo)){

            return codigo;

        }else{

             cout << "Animal não encontrado, digite 1 para sair ou outra tecla para tentar novamente." << endl;
             cin >> sair;
            
             if (sair == "1"){
                return "";
             }

             cin.clear();
             cin.ignore(1000,'\n');
             cout << "Código: ";
       }
    }
}

bool Interface::validaCrmv(string codigoCrmv){
    return true;
}

bool Interface::validaData(string data){
    //xx/xx/xxxx
    if(data.size() == 10){
        for (int i = 0; i < 10; i++){
            if(i == 2 ||i == 5){

                if(data[i]!='/'){
                    return false;
                } 

            }else if(!isdigit(data[i])){

                    return false;

            }
        }
        return true;
  
    }else{

     return false;

    }
}



bool Interface::validaCPF(string cpf){
    //xxx.xxx.xxx-xx
    if(cpf.size() == 14){
        for (int i = 0; i < 14; i++){
            if(i == 3 ||i == 7){

                if(cpf[i]!='.'){
                    return false;
                } 

            }else if(i == 11){

                if(cpf[i]!='-'){
                    return false;
                } 

            }else if(!isdigit(cpf[i])){

                    return false;

            }
        }
        return true;
  
    }else{

     return false;

    }
}


bool Interface::validaNome(string nome){

    int t = nome.size();
    if(!(nome=="")){
        for (int i = 0; i < t ; i++){

            if(isdigit(nome[i])){
                return false;
            }
         }  
 
    }else{

        return false;

    }
    
    return true;
}


