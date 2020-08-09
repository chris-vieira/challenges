## Programming Challenge
#### Control-Id: https://www.controlid.com.br/en/

1. Desenvolver um aplicativo em C++ que pode receber 1 parâmetro (um número) ou 
nenhum parâmetro
    1. Se não receber nenhum parâmetro, baixa a partir do site 
       https://jsonplaceholder.typicode.com/ os users (/users) e imprime todos 
       de maneira formatada no shell
    2. Se receber um parâmetro, carregar do mesmo site os posts do usuário cujo 
       id é o argumento fornecido e, em seguida, imprimir os posts de maneira 
       formatada no shell
2. Por fim, criar um recipe de Yocto que compile o aplicativo para qualquer 
   plataforma (ou quase hehehe)
3. Disponibilizar um README.md documentando o que foi feito e como compilar 
   o código
4. A ideia é que o código seja disponibilizado em um repositório Git, pode até 
   ser um repositório público no Github.

#### Solução:

A solução foi baseada em duas bibliotecas: curl para download dos dados da página
em HTML e nlohmann::json (https://github.com/nlohmann/json)

1. Ferramentas utilizadas:
    1. Linux estopa 5.7.11-200.fc32.x86_64 GNU/Linux
    2. gcc version 10.2.1 20200723 (Red Hat 10.2.1-1) (GCC)
    3. curl 7.69.1 (x86_64-redhat-linux-gnu) libcurl/7.69.1

2. A biblioteca libcurl pode ser instalada a partir da ferramenta da sua distro
   GNU/Linux preferida (geralmente sob o nome de libcurl ou libcurl-dev)

3. Compilação em linha de comando para testes iniciais:
``g++ -std=c++14 -Wall -Wextra control-id_jsonp.cpp -lcurl -o control-id_jsonp``

4. Para testes:
    1. ``$ ./control-id_jsonp`` para impressão dos dados dos usuários de forma 
       não formatada na saída padrão,
    2. ``$ ./control-id_jsonp <num>`` para impressão de todas as mensagens 
       (título e corpo da mensagem) do usuário de userId passado sob forma 
       numérica (não negativo) como argumento da entrada padrão (num).

5. Informações sobre o código fonte:
    Inicialmente, os dois endereços são descritos de forma estática: um referenciando 
    os usuários e o outro, referenciando os posts dos usuários. A biblioteca curl é
    então inicializada e conforme argumento passado ou não na entrada padrão,
    é informado o endereço do site a ser "baixado" (através da URL passada 
    como argumento da função). Na configuração seguinte, é realizado sob forma
    de função anônima (lambda) o tamanho correspondente a string da página lida,
    e então uma outra função é chamada para inserção dos dados lidos em um
    buffer do tipo string.

    A página HTML então é lida e os dados armazenados em uma string. Após isso,
    curl é finalizada através de uma função específica. Utilizando uma biblioteca
    nlohmann::json (https://github.com/nlohmann/json) que faz o parser de dados 
    em formato JSON (em outras palavras a deserialização), conforme opção da
    linha de comando passada quando na invocação para execução, os dados são
    então deserializados e exibidos na saída padrão. Para cada uma das
    opções de deserialização, foi montada uma estrutura para avaliação de
    excessão, de maneira que campos ausentes na estrutura do JSON lido não
    levasse a execução do programa ao término abruptamente. Ao contrário, a 
    verificação da inicialização correta da função curl é realizada e caso haja 
    problemas, o programa é abortado após exibição de uma mensagem de erro na
    saída padrão de erros e um código de falhas é retornado. Caso não haja 
    nenhuma anormalidade, ao término da execução do programa, um código de
    sucesso de execução é retornado e o programa finalizado.


