## Projeto de LP1

## PETFERA ##

#### Membros da Equipe:

    Débora Tayná
    João Paulo Siqueira
    Rodrigo Gomes da Rocha

#### Descrição:

    Esse projeto é voltado para o gerencialmento de Animais, Tratadores e Veterinários da PetFera (Loja de comercialização de animais silvestres autorizados pelo IBAMA).

#### Descrição da Implementação:
    O projeto implementa as seguintes classes: PetFera, Interface, Funcionario, 
    Tratador, Veterinário, Animal, Ave, Anfibio, Reptil, Mamifero, Silvestre, 
    Nativo, Exotico, além das especificas AveNativo, Ave Exotico etc.
    As classes Tratador e Veterinário herdam de funcionário. Já as classes de animais
    herdam de Animal e as Nativo, Exotico herdam de Silvestre.
    As classes mais especícas, AveNativo por exemplo, possui herança multipla,
    que no caso de AveNativo do exemplo, configura-se uma herança tanto de Ave, quanto
    de Nativo.

    A classe PetFera possui três vetores, um para animais, outro pra tratadores e
    um terceiro pra veterinario. Nela são implementados também os métodos de 
    cadastro, remoção, venda e consulta na sua forma mais básica.

    A classe interface, por sua vez, usar dos métodos dispostos na classe PetFera
    e implementa a interface com o usuário.

#### Executar o programa:
    
    Para executar o programa, é necessário ter g++ instalado.

    Baixando o programa pelo git:

    `git clone https://github.com/jopak19/Projeto-LP1.git`

    Para compilar:

    ```
    cd Projeto-LP1
    make
    
    ```

    Para executar:

    `./bin/programa`

#### Orientação para Testes:
    Para realizar os testes basta executar o código, escolher uma das opções
    do menu e então fornecer os dados solicitados.

    O programa dispões das seguintes funcionalidade:

        Cadastrar, Alterar, Remover e Consultar Tratador.
        Cadastrar, Alterar, Remover e Consultar Veterinário.
        Cadastrar, Remover, Vender e Consultar animal.

    Para cadastrar um animal é necessário ter cadastrado anteriormente pelo
    menos 1 tratador e 1 veterinário no PetFera. Além disso, o tratador precisa
    ter o nível de segurança adequado para tratar o animal, isto é:
    
        Nível Vermelho: pode tratar qualquer animal.
        Nível Verde: Trata apenas Aves não perigosas.
        Nível Azul: Trata Aves, réptios e mamíferos não perigosos.

    Ao efetivar o cadastro é gerado um código para o animal, composto da
    espécie e do "número de entrada" do animal no petFera. O código é exibido
    assim que o cadastro estiver efetivado.
 
    A consulta de um animal pode ser feita de diversas formas, entre elas:
    
        Buscar animal pelo código
        Listar todos os animais do PetFera
        Listar os animais associados a um tratador
        Listar os animais associados a um veterinário
        Listar os animais por espécie
        Listar os animais por classe

    As consultas podem ser realizadas clicando no menu 3-Gerenciar Animal > 4-Consultar 

#### Endereço do repositório: 
    https://github.com/jopak19/Projeto-LP1
