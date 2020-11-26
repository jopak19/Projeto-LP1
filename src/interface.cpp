#include "interface.hpp"
using namespace std;

void Interface::setPet(PetFera* p){
    pet=p;
}

/* Os métodos menu e opções servem para definir qual funcionalidade
 será utilizada pelo usuário. A partir da funcionalidade escolhida
 o usuário é direcionado para os métodos específicos.*/

void Interface::menu() {

    while(true){

        string escolha="";
        cout << "" << endl;
        cout << "========================MENU INICIAL==================" << endl;
        cout << "Escolha uma das opções abaixo para acessar:" << endl;
        cout << " 1-Gerenciar Tratador \n 2-Gerenciar Veterinário \n 3-Gerenciar Animal \n 4-Realizar Venda \n 5-Sair" << endl;
        cin >> escolha;

        if (escolha=="1" || escolha=="2" || escolha=="3"){

            opcoes(escolha); /*Chamando o método para a próxima etapa de Menu*/

        } else if(escolha=="4"){
           
            if(!venderAnimal()){
                cout << "Venda não realizada!"<< endl;
            }
            
        } else if(escolha=="5"){
            break;

        } else {
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
                alteracaoAnimal();

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

/*O método cadastrar funcionário recebe um inteiro que indica o tipo de
 funcionário será cadastrado e solicita os dados comuns a todos. Após os
 dados comuns estarem preenchidos, são chamados os métodos específicos
 cadastrarTratador e cadastrarVeterinario baseando-se no tipo passado.*/

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

        } else{
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

/*Os métodos cadastroTratador e cadastroVeterinario recebem os dados já preenchidos
 em cadastrarFuncionario e então solicitam os demais dados necessários para finalizar
 o cadastro, isto é, Nível de Segurança para tratador e/ou crvm para veterinário.
 Após receber os dados o funcionário é implementado de acordo com a classe derivada e
 inserido no vetor da classe PetFera*/
 
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
        cadastroTratador(nome, cpf, dataNascimento);
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


/*O método alterarFuncionario recebe a variável tipo, que indica tratador ou veterinario,
 e então solicita ao usuário o cpf do funcionário que será alterado e o tipo de alteração
 que deseja realizar. De acordo com a opção escolhida, o usuário pode informar o novo valor
 que será setado no atributo do funcionário.*/
    
bool Interface::alterarFuncionario(int tipo){

    string escolha = "";
    string cpf;
    cout << "Informe cpf do funcionário para as alterações:" << endl;
    cin >> cpf;
    cout << "Informe o que deseja alterar:" << endl;

    if(tipo == 1){

        cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Nivel de Segurança\n" << endl;

    } else {

        cout << "1-Nome | 2-CPF | 3-Data de Nascimento | 4- Código CRMV\n" << endl;

    }

    while (true){

        cin >> escolha;
        if (escolha=="1" || escolha=="2" || escolha=="3" || escolha=="4"){
            break;

        } else {
            cout << "Opção inválida, tente novamente" << endl;
        }

    } 

    /* Nesse trecho serão solicitados os novos dados de acordo com a opção escolhida.
     Será feita uma validação semelhante a realizada no momento do cadastro e então o
     novo dado será setado. Uma das validações que ocorre tanto em alteração quanto em
     cadastro é garantir que não serão criados dois tratadores ou dois veterinários com
     mesmo cpf. */

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

            if (pet->getTratador(cpf)!=nullptr){
                pet->getTratador(cpf)->setNome(newNome);
                cout << "Nome alterado!" << endl;
            } else {
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if (pet->getVeterinario(cpf)!=nullptr){
                pet->getVeterinario(cpf)->setNome(newNome);
                cout << "Nome alterado!" << endl;
            } else{
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

            if(pet->existeTratador(newCpf)){
                cout << "CPF Não alterado. Já existe Veterinario com esse CPF!" << endl;
                return false;
            }

            if (pet->getTratador(cpf)!=nullptr){
                pet->getTratador(cpf)->setCpf(newCpf);
                cout << "CPF alterado!" << endl;
            } else{
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if(pet->existeVeterinario(newCpf)){
                cout << "CPF Não alterado. Já existe Veterinario com esse CPF!" << endl;
                return false;
            }

            if (pet->getVeterinario(cpf)!=nullptr){
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

            } else{
                cout << "Formato incorreto, tente novamente." << endl;
            }

        }

        if(tipo==1){

            if (pet->getTratador(cpf)!=nullptr){
                pet->getTratador(cpf)->setDataNascimento(newData);
                cout << "Data alterada!" << endl;
            } else {
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            if (pet->getVeterinario(cpf)!=nullptr){
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
            cout << "1-Verde | 2-Vermelho | 3-Azul\n";
          
            while (true){

                cin >> newNivel;
                if (newNivel=="1" || newNivel=="2" || newNivel=="3"){
                    break;

                } else {
                    cout << "Opção inválida, tente outra." << endl;
                }

            }

            if (pet->getTratador(cpf)!=nullptr){

                if(newNivel=="1"){
                    novoNivel = Verde;

                } else if (newNivel=="2"){ 
                    novoNivel = Vermelho;

                } else{
                    novoNivel = Azul;
                }

                pet->getTratador(cpf)->setNivelSeguranca(novoNivel);
                cout << "Nivel alterada!" << endl;

            }else{
                cout << "Tratador não encontrado." << endl;
            }

        } else {

            string newCodigo="";
            cout << "Informe o novo código do veterinário\n" << endl;
            cin >> newCodigo;
            bool valida = false;

            while (valida==false){

                cin >> newCodigo;
                if(not validaCrmv(newCodigo)){
                    cout <<  "Código Inválido, tente outro." << endl;
                }
                valida = validaCrmv(newCodigo);
            }

            if (pet->getVeterinario(cpf)!=nullptr){
                pet->getVeterinario(cpf)->setCodigoCrmv(newCodigo);
                cout << "Código alterado!" << endl;

            } else {
                cout << "Veterinario não encontrado." << endl;
            }
        }   
    }

    return true;    
}


/*O método de apagar funcionário solicita o cpf do funcionario e baseando-se no
 tipo recebido, remove o objeto do vetor de PetFera.*/

bool Interface::apagarFuncionario(int tipo){

    string cpf="";

    if(tipo==1){

        cout << "Informe CPF do Tratador que deseja remover." << endl;
        cin >> cpf;

        if(pet->removerTratador(cpf)){
            cout << "Tratador removido." << endl;
        } else{
            cout << "Tratador não encontrado." << endl;
            return false; 
        }  

    } else {

        cout << "Informe CPF do Veterinario que deseja remover." << endl;
        cin >> cpf;

        if(pet->removerVeterinario(cpf)){
            cout << "Veterinário removido." << endl;
        } else {
            cout << "Veterinário não encontrado." << endl; 
            return false;
        } 

    }

    return true;
}


/* O método consultarFuncionario oferece duas opções, consultar por cpf, na qual 
 é solicitado o cpf do funcionário e caso ele exista é imprimido em tela; ou 
 listar todos, que mostra todos os funcionários de um determinado tipo */

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
                cout << "Veterinário não encontrado." << endl;
            }
        }

    } else if(escolha=="2"){

        if(tipo==1){
            pet->listarTratadores();

        } else {
            pet->listarVeterinarios();

        }

    } else{
        cout << "Opção Inválida, tente outra." << endl;
        consultarFuncionario(tipo);
    }
    return true;
}

/*Os dois métodos seguintes cadastram os animais do petFera, além deles são
 usados quatro métodos auxiliares para o caso de animais silvestres. O método
 cadastroAnimal solicita os dados comuns a todos os animais e a classe do animal
 que será cadastrado. A partir dessas informações o proxímo metodo conluirá o
 cadastro solicitando os dados específicos por classe.*/

bool Interface::cadastroAnimal(){

    string codigo="";
    string peso="";
    string altura="";
    short idade=0;
    string especie="";
    bool perigoso = false;
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
    idade = validaInt(idade);
   
    cout << "Espécie (ex.: tartaruga, águia, etc.):" << endl;
    cin >> especie;

    cout << "O animal é perigoso ou venenoso? 0-NÃO | 1-SIM" << endl;
    perigoso = validaBool(perigoso);
    
    codigo = especie + to_string(pet->getAnimais().size()); /*Neste ponto é gerado o código
                                                             do animal, que é composto da 
                                                             espécie informada junto com a
                                                             posição do animal no vetor. */
    
    cout << "Informe a classificação do animal: 1-Anfíbio | 2-Réptil | 3-Ave | 4-Mamifero " << endl;

    while (true){

        if (cin >> classe && (classe == 1 || classe == 2 || classe == 3 || classe == 4)){
            break;

        } else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
        }

    }

    cout << "Informe o tipo do animal: 1-Doméstico | 2-Silvestre Nativo | 3-Silvestre Exótico" << endl;

    while (true){

        if (cin >> manejo && (manejo == 1 || manejo == 2 || manejo == 3)){
            break;

        } else {
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
        }

    }

    /*Aqui serão válidados o tratador e o veterinário do animal, 
     de forma que será possível prosseguir a operação apenas se
     ambos estiverem cadastrados e o tratador tiver o nível de
     segurança correto */

    cout << "Informe o CPF do veterinário desse animal:" << endl;
  
    while (true){

        cin >> cpfveterinario;

        if (pet->getVeterinario(cpfveterinario)){
            break;

        } else {
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

            } else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Azul && perigoso == false && (classe == 2 || classe == 3 || classe == 4)){
                break;

            } else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Verde && perigoso == false && classe == 3){
                break;

            } else{
                cout << "Tratador inválido para o animal! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
                cin >> sair;
            
                if (sair == "1"){
                    return false;
            
                }

                cin.clear();
                cin.ignore(1000,'\n');
                cout << "CPF: ";
            }

        } else {
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

    /*Aqui os dados comuns, juntamente com a classe e com a classsificação de manejo,
     são enviados para o próximo metódo que concluíra o cadastro de acordo com a divisão.*/
    cadastroClasseAnimal(classe, manejo, codigo, peso, altura, idade, especie, perigoso, cpfveterinario, cpftratador); 

    return true;
}

/* O método cadastroClasseAnimal solicita os dados restantes e então finaliza o cadastro
 do animal na classe específica. Por fim, cada animal é adicionado ao vetor da classe 
 PetFera.*/

bool Interface::cadastroClasseAnimal(short classe, short manejo, string codigo, string peso, string altura, short idade, string especie, bool perigoso, string cpfveterinario, string cpftratador){
    

    switch (classe){
    
        case 1: { //Anfíbio

            string periodoDeMudaDePele="";
            int temperaturaDoAmbiente=0;

            cout << "Informe o período de muda de pele do animal" << endl;
            cin >> periodoDeMudaDePele;
            cout << "Informe a temperatura média do ambiente para o animal." << endl;
            temperaturaDoAmbiente = validaInt(temperaturaDoAmbiente);
            
            //Aqui o anfíbio será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Anfibio> anfibio = make_shared<Anfibio>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, temperaturaDoAmbiente, perigoso);
                pet->cadastrarAnimal(anfibio, cpftratador, cpfveterinario);
                cout << "Anfíbio doméstico cadastrado: " << codigo << endl;

            } else if (manejo ==2) { //Nativo

                shared_ptr<AnfibioNativo> anfibio = make_shared<AnfibioNativo>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, temperaturaDoAmbiente, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(anfibio, cpftratador, cpfveterinario);
                cout << "Anfíbio Silvestre Nativo cadastrado: " << codigo << endl;

            } else { //Exótico

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

                } else if (tipo== "2"){
                    tipoDePele = CARAPACA;
                    break;

                } else if (tipo == "3"){
                    tipoDePele = PLACADERMICA;
                    break;

                } else {
                    cout << "Opção inválida, tente outra." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n'); 

                }
            }

             //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Doméstico

                shared_ptr<Reptil> reptil = make_shared<Reptil>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Réptil doméstico cadastrado: " << codigo << endl;

            } else if (manejo ==2) { //Nativo

                shared_ptr<ReptilNativo> reptil = make_shared<ReptilNativo>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Réptil Silvestre Nativo cadastrado: " << codigo << endl;

            } else { //Exótico

                shared_ptr<ReptilExotico> reptil = make_shared<ReptilExotico>(codigo, peso, altura, idade, especie, periodoDeMudaDePele, tipoDePele, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(reptil, cpftratador, cpfveterinario);
                cout << "Rétpil Silvestre Exótico cadastrado: " << codigo << endl;
            }

            break;
        }

        case 3:{ //Ave

            bool aquatica = false;
            bool podeVoar = false;

            cout << "A ave é aquática? 0-NÃO | 1-SIM" << endl;
            aquatica = validaBool(aquatica);
            cout << "A ave voa? 0-NÃO | 1-SIM " << endl;
            podeVoar = validaBool(podeVoar);

             //Aqui o animal será cadastrado como Doméstico, Nativo ou Exótico

            if (manejo == 1){ //Domético

                shared_ptr<Ave> ave = make_shared<Ave>(codigo, peso, altura, idade, especie, aquatica, podeVoar, perigoso);
                pet->cadastrarAnimal(ave, cpftratador, cpfveterinario);
                cout << "Ave doméstico cadastrado: " << codigo << endl;

            } else if(manejo ==2) { //Nativo

                shared_ptr<AveNativo> ave = make_shared<AveNativo>(codigo, peso, altura, idade, especie, aquatica, podeVoar, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(ave, cpftratador, cpfveterinario);
                cout << "Ave Silvestre Nativo cadastrado: "  << codigo << endl;

            } else{ //Exótico

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

                } else if (escolha== "2"){
                    gestacao = MARSUPIAL;
                    break;

                } else if (escolha == "3"){
                    gestacao = PLACENTARIO;
                    break;

                } else{
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

            } else if (manejo ==2) { //Nativo

                shared_ptr<MamiferoNativo> mamifero = make_shared<MamiferoNativo>(codigo, peso, altura, idade, especie,  gestacao, solicitaMarcacao(), solicitaExtincao(), solicitaBioma(), perigoso);
                pet->cadastrarAnimal(mamifero, cpftratador, cpfveterinario);
                cout << "Mamífero Silvestre Nativo cadastrado: " << codigo << endl;

            } else{ //Exótico

                shared_ptr<MamiferoExotico> mamifero = make_shared<MamiferoExotico>(codigo, peso, altura, idade, especie,  gestacao, solicitaMarcacao(), solicitaExtincao(), solicitaTerritorio(), perigoso);
                pet->cadastrarAnimal(mamifero, cpftratador, cpfveterinario);
                cout << "Mamífero Silvestre Exótico cadastrado: " << codigo << endl;
            }

            break;
        }
    }


    return true;
}

/* A classe alteraAnimal solicita o código do animal e se ele existir verifica a classe do mesmo.
 Após verificar a classe são geradas duas etapas de menu. Na primeira etapa é possível alterar 
 tratador ou veterinário do animal, na segunda é possível alterar outros dados de acordo com a
 classe. O metódo de alterção conta com outros 4 métodos auxiliares para casos de animais 
 silvestres, como ocorreu no cadastro de animal.*/


bool Interface::alteracaoAnimal(){

    cout << "=================ALTERAR ANIMAL================" << endl;
    cout << "Informe o código do animal que deseja alterar:" << endl;
    string codigo = animalExiste();

    if (codigo == ""){
        return false;
    }

    cout << "O que deseja alterar: 1-Veterinario | 2-Tratador | Qualquer tecla pra outros" << endl;
    string alterar;
    cin >> alterar;
    string sair;
    string classe = pet->getAnimal(codigo)->getClasse();
    int classes =0;
    string alteracaoClasse="";

    if(classe == "ave" || classe == "avenativo" || classe == "aveexotico" ){
            alteracaoClasse = "5-Aquatica | 6-Pode Voar";
            classes = 3;

    } else if(classe == "anfibio" || classe== "anfibionativo" || classe == "anfibioexotico" ){
            alteracaoClasse = "5-Periodo Muda de Pele | 6-Temperatura do ambiente";

    } else if(classe == "reptil" || classe=="reptilnativo" ||  classe == "reptilexotico"){
            alteracaoClasse = "5-Periodo Muda de Pele | 6-Tipo de Pele";
            classes = 2;

    } else if(classe == "mamifero" ||  classe=="mamiferonativo" || classe == "mamiferoexotico"){
            alteracaoClasse = "5-Tipo de Gestação";
            classes = 4;
    }


    if(alterar=="1"){ /*Esse caso ocorre quando o usuário quer alterar o veterinário 
                       do animal. É feita a validação do veterinário.*/
            cout << "CPF do novo veterinário:" << endl;
            string cpfveterinario;

            while (true){
                cin >> cpfveterinario;
                if (pet->getVeterinario(cpfveterinario)){
                    break;

                } else {
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
    
        cout << "Veterinário Alterado" << endl;


    } else if(alterar=="2"){/*Esse caso ocorre quando o usuário quer alterar o tratador 
                           do animal. É feita a validação tanto da existência do
                           tratador, quanto do tipo do nível de segurança.*/

         cout << "CPF do novo tratador:" << endl;
           string cpftratador;
            while (true){
                cin >> cpftratador ;

                if (pet->getTratador(cpftratador)){
               
                    if (pet->getTratador(cpftratador)->getNivelSeguranca() == Vermelho){
                        break;

                    } else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Azul && (pet->getAnimal(codigo))->getPerigoso() == false && (classes == 2 || classes == 3 || classes == 4)){
                        break;

                    } else if (pet->getTratador(cpftratador)->getNivelSeguranca() == Verde && (pet->getAnimal(codigo))->getPerigoso() == false && classes == 3){
                        break;

                    } else{
                        cout << "Tratador inválido para o animal! Digite 1 para SAIR ou outra tecla para tentar outro" << endl;
                        cin >> sair;
                    
                        if (sair == "1"){
                            return false;
                        }

                        cin.clear();
                        cin.ignore(1000,'\n');
                        cout << "CPF: ";

                    }

                } else{
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

    } else {/*Esse ultimo e mais extenço caso serve para as demais alterações.
           Ele exibe o novo menu baseado na classe do animal e então solicita
           a uma nova escolha do usuário. Temos então os demais casos baseados
           escolha do usuário.*/

        string alteracaoManejo="";

        if(classe == "avenativo" || classe== "anfibionativo" || classe=="reptilnativo" || classe=="mamiferonativo"){
                        alteracaoManejo= "7- Marcacao | 8-Extincao | 9-Bioma";

        } else if(classe == "aveexotico" || classe == "anfibioexotico" || classe == "reptilexotico" || classe == "mamiferoexotico"){
                        alteracaoManejo= "7- Marcacao | 8-Extincao | 9-Territorio";
        }

        int escolha;
        cout << "Informe o que deseja alterar para o animal:" << endl;
        cout << "1-Peso | 2-Altura | 3-Idade | 4-Especie | " << alteracaoClasse << " | " << alteracaoManejo << endl;
        while (true){

            if (cin >> escolha && (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6 || escolha ==8|| escolha == 7 || escolha == 9)){
                break;

            } else{
                cout << "Opção inválida, tente um inteiro." << endl;
                cin.clear();
                cin.ignore(1000,'\n'); 
            }

        }

        switch (escolha){

            case 1:{

                string newPeso;
                cout << "Novo Peso:" << endl;
                cin >> newPeso;
                pet->getAnimal(codigo)->setPeso(newPeso);
                cout << "Peso Alterado!" << endl;
                break;

            }

            case 2:{

                string newAltura;
                cout << "Novo altura:" << endl;
                cin >> newAltura;
                pet->getAnimal(codigo)->setAltura(newAltura);
                cout << "Altura Alterada!" << endl;
                break;
            }

            case 3:{
                 short idade;
                 cout << "Idade do animal:" << endl;

                 while (true){
                    if (!(cin >> idade)){
                    cout << "Idade inválida, tente novamente." << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                    } else{
                        break;
                    }
                 }
                pet->getAnimal(codigo)->setIdade(idade);
                break;
            }

            case 4:{
                string newEspecie;
                cout << "Nova espécie:" << endl;
                cin >> newEspecie;
                pet->getAnimal(codigo)->setEspecie(newEspecie);
                break;
            }

            case 5:{
                if(classe == "ave"){
                    bool aquatica = false;
                    cout << "Ave aquática? 0-NÃO | 1-SIM" << endl;
                    aquatica = validaBool(aquatica);
                    shared_ptr<Ave> ave = static_pointer_cast<Ave>(pet->getAnimal(codigo));
                    ave->setAquatica(aquatica);

                } else if(classe == "anfibio"){
                    string periodo = "";
                    cout << "Novo período de muda de pele:" << endl;
                    cin >> periodo;
                    shared_ptr<Anfibio> anfibio = static_pointer_cast<Anfibio>(pet->getAnimal(codigo));
                    anfibio->setPeriodoDeMudadepele(periodo);

                } else if(classe == "reptil"){
                    string periodo = "";
                    cout << "Novo período de muda de pele:" << endl;
                    cin >> periodo;
                    shared_ptr<Reptil> reptil = static_pointer_cast<Reptil>(pet->getAnimal(codigo));
                    reptil->setPeriodoDeMudadepele(periodo);

                } else if(classe == "mamifero"){
                    Gestacao gestacao;
                    string escolha = ""; 
                    cout << "Informe o tipo de gestação do animal: 1-MONOTREMADO | 2-MARSUPIAL | 3-PLACENTARIO" << endl;

                    while (true){
                    
                        cin >> escolha;
                        if (escolha == "1"){
                            gestacao= MONOTREMADO;
                            break;

                        } else if (escolha== "2"){
                            gestacao = MARSUPIAL;
                            break;

                        } else if (escolha == "3"){
                            gestacao = PLACENTARIO;
                            break;

                        } else{
                            cout << "Opção inválida, tente outra." << endl;
                            cin.clear();
                            cin.ignore(1000,'\n'); 

                        }

                    }
                    shared_ptr<Mamifero> mamifero = static_pointer_cast<Mamifero>(pet->getAnimal(codigo));
                    mamifero->setGestacao(gestacao);
                }
                break;
            }

            case 6:{

                if(classe == "ave"){
                    bool podeVoar = false;
                    cout << "A ave voa? 0-NÃO | 1-SIM " << endl;
                    podeVoar = validaBool(podeVoar);       
                    shared_ptr<Ave> ave = static_pointer_cast<Ave>(pet->getAnimal(codigo));
                    ave->setPodeVoar(podeVoar);

                } else if(classe == "anfibio"){
                    int temp=0;
                    cout << "Nova temperatuda:" << endl;
                    temp = validaInt(temp);
                    shared_ptr<Anfibio> anfibio = static_pointer_cast<Anfibio>(pet->getAnimal(codigo));
                    anfibio->setTemperaturaDoAmbiente(temp);

                } else if(classe == "reptil"){
                    string tipo ="";
                    TipoDePele tipoDePele;
                    cout << "Novo Tipo: 1- ESCAMAS | 2-CARAPACA | 3-PLACADERMICA" << endl;

                    while (true){
                    
                        cin >> tipo;
                        if (tipo == "1"){
                            tipoDePele = ESCAMAS;
                            break;

                        } else if (tipo== "2"){
                            tipoDePele = CARAPACA;
                            break;

                        } else if (tipo == "3"){
                            tipoDePele = PLACADERMICA;
                            break;

                         }else {
                            cout << "Opção inválida, tente outra." << endl;
                            cin.clear();
                            cin.ignore(1000,'\n'); 
                        }
                    }
            
                    shared_ptr<Reptil> reptil = static_pointer_cast<Reptil>(pet->getAnimal(codigo));
                    reptil->setTipoDePele(tipoDePele);

                } else if(classe == "mamifero"){
                    cout << "Escolha inválida!"<< endl;
                }
                break;
            }

            case 7:{
                
                if(alteraMarcacao(classe, codigo)){
                    cout << "Marcação Alterada" << endl;
                }
                break;
            }

            case 8:{
               
                if(alteraExtincao(classe, codigo)){
                    cout << "Extinção Alterada" << endl;
                }

                break;
            }

            case 9:{
               
                if(classe == "avenativo" || classe== "anfibionativo" || classe=="reptilnativo" || classe=="mamiferonativo"){
                    if(alteraBioma(classe, codigo)){
                        cout << "Bioma Alterado" << endl;
                    }

                } else if(classe == "aveexotico" || classe == "anfibioexotico" || classe == "reptilexotico" || classe == "mamiferoexotico"){
                    if(alteraTerritorio(classe, codigo)){
                        cout << "Territorio Alterado" << endl;
                    }

                } else{
                    cout << "Escolha Inválida" << endl;
                }

                break;
            }
        }
    }
    return true;
}

/*Os métodos solicitaMarcacao, solicitaExtincao, solicitaTerritorio e solicitaBioma,
 são chamados apenas quando necessários a depender do tipo de manejo do animal.
 */


int Interface::solicitaMarcacao(){

    int marcacao=0;
    cout << "Informe o número de marcação permanente do animal de acordo com o orgão responsável:" << endl;    

    while (true){

        if (cin >> marcacao){
            return marcacao;

        } else{
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

        } else{
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
        
        } else if(escolha == "2"){
            return CAATINGA;

        } else if(escolha == "3"){
            return PAMPA;

        } else if(escolha == "4"){
            return CERRADO;

        } else if(escolha == "5"){
            return PANTANAL;

        } else if(escolha == "6"){
            return MATAATLANTICA;

        } else {
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
  
        }
    }
} 

/*Os métodos de venda e de apagar animal solicitam o código e verificam 
 se o mesmo existe, isto é, se ele está cadastrado no petFera. Em caso que
 existe, o animal é removido do vetor.*/

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

/*Apagar Animal*/

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


/*consultarAnimal oferece 6 diferentes tipos de consulta ao usuário. 
A depender da escolhida a busca é realizada e os animais exibidos em tela*/

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

        case 1:{ /*No caso 1, é solicitado cpf do veterinário e então
                  são exibidos os animais que se encontram no vetor de
                  animais tratados desse veterinário*/

            string cpf = "";
            string sair = "";
            cout << "Informe o CPF do veterinário:" << endl;
  
            while (true){ 

                cin >> cpf;
                if (pet->getVeterinario(cpf)){
                    break;

                } else {

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
                    cout << ((pet->getVeterinario(cpf))->getAnimaisTratados()).at(i)->imprimir()<< endl;
                }
            }  

            break;

        }

        case 2:{/*No caso 2, é solicitado cpf do tratador e então
                  são exibidos os animais que se encontram no vetor de
                  animais tratados desse tratador*/

            string cpf = "";
            string sair = "";
            cout << "Informe o CPF do tratador:" << endl;
  
            while (true){

                cin >> cpf;
                if (pet->getTratador(cpf)){
                    break;

                } else {

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

            int tamanho = pet->getTratador(cpf)->getAnimaisTratados().size();
            if (tamanho == 0){
                cout << "Esse tratador ainda não tratou nenhum animal!" << endl;

            } else {
                for (int i = 0; i < tamanho; i++){
                    cout << ((pet->getTratador(cpf))->getAnimaisTratados()).at(i)->imprimir() << endl;
                }
            }  

            break;
        }

        case 3: {/*No caso 3, é solicitada a escolha de uma das classes 
                  dentre as disponíveis. De acordo com a escolha do usuário
                  são exibidos os animais que se encontram no vetor da petFera
                  e que possuem o atributo classe igual o informado.*/

             string classe;
             string escolha;
             cout << "Informe a classe que deseja buscar:" << endl;
             cout << "Doméstico: 1-Ave | 2-Anfibio | 3-Reptil | 4-Mamifero "  << endl;
             cout << "Nativos: 5-Ave | 6-Anfibio | 7-Reptil | 8-Mamifero"  << endl;
             cout << "Exóticos: 9-Ave | 10-Anfibio | 11-Reptil | 12-Mamifero "  << endl;

             while (true){

                cin >> escolha;

                if(escolha=="1"){
                    classe = "ave";
                    break;

                } else if(escolha == "2"){
                    classe = "anfibio";
                    break;

                }else if(escolha == "3"){
                    classe = "reptil";
                    break;

                } else if(escolha == "4"){
                    classe = "mamifero";
                    break;

                }else if(escolha == "5"){
                    classe = "avenativo";
                    break;

                } else if(escolha == "6"){
                    classe = "anfibionativo";
                    break;

                } else if(escolha == "7"){
                    classe = "reptilnativo";
                    break;

                } else if(escolha == "8"){
                    classe = "mamiferonativo";
                    break;

                } else if(escolha == "9"){
                    classe = "aveexotico";
                    break;

                } else if(escolha == "10"){
                    classe = "anfibioexotico";
                    break;

                } else if(escolha == "11"){
                    classe = "reptilexotico";
                    break;

                } else if(escolha == "12"){
                    classe = "mamiferoexotico";
                    break;

                } else {
                    cout << "Opção inválida, tente outra" << endl;
                }
            }

            int tamanho = pet->getAnimais().size();

            cout << "------------------Animais Encontrados-----------------" << endl;
            for (int i = 0; i < tamanho; i++){
                
                if (pet->getAnimais()[i]->getClasse() == classe){
                    cout << "----------------------" << endl;
                    cout << pet->getAnimais().at(i)->imprimir() << endl;
                }
             }
             break;
        }

        case 4:{ /*No caso 4, chamado o método listarAnimais do
                  petFera, que lista todos os animais do vetor.*/
             pet->listarAnimais();
             break;

        }

        case 5:{ /*No caso 5, é solicitado o código do animal.
                  Se ele existir no sistema, os dados serão
                  exibidos em tela..*/

             string codigo;
             cout << "Informe o código do animal:" << endl;
             codigo = animalExiste();

             if (codigo==""){
                return false;

             } else {
                cout << pet->getAnimal(codigo)->imprimir() << endl;
             } 

             break;

        }

        case 6:{/*No caso 6, é solicitada uma espécie de animal. 
                 São exibidos, então, todos os animais no vetor
                 petFera que possuem espécie igual a informada.*/

            string especie;
            cout << "Informe a espécie que deseja buscar:" << endl;
            cin >> especie;
               
            int tamanho = pet->getAnimais().size();

            cout << "------------------Animais Encontrados-----------------" << endl;
            for (int i = 0; i < tamanho; i++){
                
                if (pet->getAnimais()[i]->getEspecie() == especie){
                    cout << "----------------------" << endl;
                    cout << pet->getAnimais().at(i)->imprimir() << endl;
                }

            }

            break;
        }
    }
    return true;
}

/*Os métodos a seguir são auxialires e servem para fazer as validações
 básicas dos dados informados pelo usuário.*/

string Interface::animalExiste(){
    string sair;
    string codigo="";
    while (true){

        cin >> codigo;
                
        if(pet->getAnimal(codigo)){
            return codigo;

        } else {

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

            } else if(!isdigit(data[i])){

                return false;
            }
        }
        return true;
  
    } else {

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

            } else if(i == 11){

                if(cpf[i]!='-'){
                    return false;
                } 

            } else if(!isdigit(cpf[i])){

                return false;
            }
        }
        return true;
  
    } else { 

    return false;

    }
}

int Interface::validaInt(int num){
    while (true){
        if (cin >> num){
            return num;
        } else{
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
        }
    }
}

bool Interface::validaBool(bool boleano){
    while (true){
        if (cin >> boleano){
            return boleano;

        } else {
            cout << "Opção inválida, tente outra." << endl;
            cin.clear();
            cin.ignore(1000,'\n'); 
        }
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

    } else {
        return false;

    }
    
    return true;
}


/*Os métodos a seguir são auxiliares para a alteração do animal. Eles fazem a mudança do animal
 para a classe derivada e então fazem a alteração necessária.*/

bool Interface::alteraMarcacao(string classe, string codigo){

    if(classe == "avenativo"){
        shared_ptr<AveNativo> animal = static_pointer_cast<AveNativo>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe== "anfibionativo"){
        shared_ptr<AnfibioNativo> animal = static_pointer_cast<AnfibioNativo>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe=="reptilnativo"){
        shared_ptr<ReptilNativo> animal = static_pointer_cast<ReptilNativo>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe=="mamiferonativo"){
        shared_ptr<MamiferoNativo> animal = static_pointer_cast<MamiferoNativo>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true; 

    } else if (classe == "aveexotico"){
        shared_ptr<AveExotico> animal = static_pointer_cast<AveExotico>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe == "anfibioexotico"){
        shared_ptr<AnfibioExotico> animal = static_pointer_cast<AnfibioExotico>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe == "reptilexotico"){
        shared_ptr<ReptilExotico> animal = static_pointer_cast<ReptilExotico>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else if (classe == "mamiferoexotico"){
        shared_ptr<MamiferoExotico> animal = static_pointer_cast<MamiferoExotico>(pet->getAnimal(codigo));
        animal->setMarcacaoPermanente(solicitaMarcacao());
        return true;

    } else {
        cout << "Escolha Inválida";
        return false;
    }
}

bool Interface::alteraExtincao(string classe, string codigo){

    if(classe == "avenativo"){
        shared_ptr<AveNativo> animal = static_pointer_cast<AveNativo>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe== "anfibionativo"){
        shared_ptr<AnfibioNativo> animal = static_pointer_cast<AnfibioNativo>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe=="reptilnativo"){
        shared_ptr<ReptilNativo> animal = static_pointer_cast<ReptilNativo>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe=="mamiferonativo"){
        shared_ptr<MamiferoNativo> animal = static_pointer_cast<MamiferoNativo>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true; 

    } else if (classe == "aveexotico"){
        shared_ptr<AveExotico> animal = static_pointer_cast<AveExotico>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe == "anfibioexotico"){
        shared_ptr<AnfibioExotico> animal = static_pointer_cast<AnfibioExotico>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe == "reptilexotico"){
        shared_ptr<ReptilExotico> animal = static_pointer_cast<ReptilExotico>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else if (classe == "mamiferoexotico"){
        shared_ptr<MamiferoExotico> animal = static_pointer_cast<MamiferoExotico>(pet->getAnimal(codigo));
        animal->setEmExtincao(solicitaExtincao());
        return true;

    } else{
        cout << "Escolha Inválida";
        return false;
    }
}

bool Interface::alteraBioma(string classe, string codigo){

    if(classe == "avenativo"){
        shared_ptr<AveNativo> animal = static_pointer_cast<AveNativo>(pet->getAnimal(codigo));
        animal->setBiomaOrigem(solicitaBioma());
        return true;

    } else if (classe== "anfibionativo"){
        shared_ptr<AnfibioNativo> animal = static_pointer_cast<AnfibioNativo>(pet->getAnimal(codigo));
        animal->setBiomaOrigem(solicitaBioma());
        return true;

    } else if (classe=="reptilnativo"){
        shared_ptr<ReptilNativo> animal = static_pointer_cast<ReptilNativo>(pet->getAnimal(codigo));
        animal->setBiomaOrigem(solicitaBioma());
        return true;

    } else if (classe=="mamiferonativo"){
        shared_ptr<MamiferoNativo> animal = static_pointer_cast<MamiferoNativo>(pet->getAnimal(codigo));
        animal->setBiomaOrigem(solicitaBioma());
        return true;   

    } else{
        cout << "Escolha inválida" << endl;
        return false;
    }
}

bool Interface::alteraTerritorio(string classe, string codigo){

    if (classe == "aveexotico"){
        shared_ptr<AveExotico> animal = static_pointer_cast<AveExotico>(pet->getAnimal(codigo));
        animal->setTerritorioDeOrigem(solicitaTerritorio());
        return true;

    }else if (classe == "anfibioexotico"){
        shared_ptr<AnfibioExotico> animal = static_pointer_cast<AnfibioExotico>(pet->getAnimal(codigo));
        animal->setTerritorioDeOrigem(solicitaTerritorio());
        return true;

    } else if (classe == "reptilexotico"){
        shared_ptr<ReptilExotico> animal = static_pointer_cast<ReptilExotico>(pet->getAnimal(codigo));
        animal->setTerritorioDeOrigem(solicitaTerritorio());
        return true;

    } else if (classe == "mamiferoexotico"){
        shared_ptr<MamiferoExotico> animal = static_pointer_cast<MamiferoExotico>(pet->getAnimal(codigo));
        animal->setTerritorioDeOrigem(solicitaTerritorio());
        return true;

    } else {
        cout << "Escolha Inválida";
        return false;
    }
}
