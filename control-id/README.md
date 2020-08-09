## Programming Challenge
#### Control-Id: <https://www.controlid.com.br/en/>

1. Desenvolver um aplicativo em *C++* que pode receber 1 parâmetro (um número) ou 
nenhum parâmetro
    1. Se não receber nenhum parâmetro, baixa a partir do site 
       <https://jsonplaceholder.typicode.com/> os *users* (/users) e imprime todos 
       de maneira formatada no *shell*
    2. Se receber um parâmetro, carregar do mesmo site os *posts* do usuário cujo 
       *id* é o argumento fornecido e, em seguida, imprimir os *posts* de maneira 
       formatada no *shell*
2. Por fim, criar um *recipe* de *Yocto* que compile o aplicativo para qualquer 
   plataforma (ou quase hehehe)
3. Disponibilizar um README.md documentando o que foi feito e como compilar 
   o código
4. A ideia é que o código seja disponibilizado em um repositório *Git*, pode até 
   ser um repositório público no *Github*.

#### Solução:

A solução foi baseada em duas bibliotecas: *curl* para *download* dos dados 
da página em *HTML* e nlohmann::json (<https://github.com/nlohmann/json>)

1. Ferramentas utilizadas:
    1. Linux estopa 5.7.11-200.fc32.x86_64 GNU/Linux
    2. gcc version 10.2.1 20200723 (Red Hat 10.2.1-1) (GCC)
    3. curl 7.69.1 (x86_64-redhat-linux-gnu) libcurl/7.69.1

2. A biblioteca *libcurl* pode ser instalada a partir da ferramenta da sua 
   *distro* *GNU/Linux* preferida (geralmente sob o nome de *libcurl* ou 
   *libcurl-dev*)

3. Compilação em linha de comando para testes iniciais:

    ``g++ -std=c++14 -Wall -Wextra control-id_jsonp.cpp -lcurl -o control-id_jsonp``

4. Para testes:
    1. ``$ ./control-id_jsonp`` para impressão dos dados dos usuários de forma 
       não formatada na saída padrão,
    2. ``$ ./control-id_jsonp <num>`` para impressão de todas as mensagens 
       (título e corpo da mensagem) do usuário de userId passado sob forma 
       numérica (não negativo) como argumento da entrada padrão (num).

5. Informações sobre o código fonte:

    Inicialmente, os dois endereços são descritos de forma estática: um 
    referenciando os usuários e o outro, referenciando os *posts* dos 
    usuários. A biblioteca *curl* é então inicializada e conforme argumento 
    passado ou não na entrada padrão, é informado o endereço do site a ser 
    "baixado" (através da *URL* passada como argumento da função). Na 
    configuração seguinte, é realizado sob forma de função anônima *(lambda)*
    o tamanho correspondente a *string* da página lida, e então uma outra 
    função é chamada para inserção dos dados lidos em um *buffer* do tipo 
    *string*.

    A página *HTML* então é lida e os dados armazenados em uma *string*. Após 
    isso, a função *curl* é finalizada através de uma função específica. 
    Utilizando uma biblioteca nlohmann::json (<https://github.com/nlohmann/json>) 
    que faz o *parser* de dados em formato *JSON* (em outras palavras a 
    deserialização), conforme opção da linha de comando passada quando na 
    invocação para execução, os dados são então deserializados e exibidos na 
    saída padrão. Para cada uma das opções de deserialização, foi montada uma 
    estrutura para avaliação de excessão, de maneira que campos ausentes na 
    estrutura do *JSON* lido não levasse a execução do programa ao término 
    abruptamente. Ao contrário, a verificação da inicialização correta da 
    função *curl* é realizada e caso haja problemas, o programa é abortado 
    após exibição de uma mensagem de erro na saída padrão de erros e um código 
    de falhas é retornado. Caso não haja nenhuma anormalidade, ao término da 
    execução do programa, um código de sucesso de execução é retornado e o 
    programa finalizado.

6. Abaixo, exemplos de dados lidos e deserializados:

```$ ./control-id_jsonp```

<table>
<tr>
<th> Dados dos usuários JSON </th>
<th> Dados dos usuários deserializados </th>
</tr>
<tr>
<td>

```
[
  {
    "id": 1,
    "name": "Leanne Graham",
    "username": "Bret",
    "email": "Sincere@april.biz",
    "address": {
      "street": "Kulas Light",
      "suite": "Apt. 556",
      "city": "Gwenborough",
      "zipcode": "92998-3874",
      "geo": {
        "lat": "-37.3159",
        "lng": "81.1496"
      }
    },
    "phone": "1-770-736-8031 x56442",
    "website": "hildegard.org",
    "company": {
      "name": "Romaguera-Crona",
      "catchPhrase": "Multi-layered client-server neural-net",
      "bs": "harness real-time e-markets"
    }
  },
  {
    "id": 2,
    "name": "Ervin Howell",
    "username": "Antonette",
    "email": "Shanna@melissa.tv",
    "address": {
      "street": "Victor Plains",
      "suite": "Suite 879",
      "city": "Wisokyburgh",
      "zipcode": "90566-7771",
      "geo": {
        "lat": "-43.9509",
        "lng": "-34.4618"
      }
    },
    "phone": "010-692-6593 x09125",
    "website": "anastasia.net",
    "company": {
      "name": "Deckow-Crist",
      "catchPhrase": "Proactive didactic contingency",
      "bs": "synergize scalable supply-chains"
    }
  }
]
```

</td>
<td>


```
$ ./control-id_jsonp 
name: "Leanne Graham"
username: "Bret"
email: "Sincere@april.biz"
address: 
  street: "Kulas Light"
  suite: "Apt. 556"
  city: "Gwenborough"
  zipcode: "92998-3874"
  geo: 
    lat: "-37.3159"
    long: "81.1496"
phone: "1-770-736-8031 x56442"
website: "hildegard.org"
company: 
  name: "Romaguera-Crona"
  catchPhrase: "Multi-layered client-server neural-net"
  bs: "harness real-time e-markets"

name: "Ervin Howell"
username: "Antonette"
email: "Shanna@melissa.tv"
address: 
  street: "Victor Plains"
  suite: "Suite 879"
  city: "Wisokyburgh"
  zipcode: "90566-7771"
  geo: 
    lat: "-43.9509"
    long: "-34.4618"
phone: "010-692-6593 x09125"
website: "anastasia.net"
company: 
  name: "Deckow-Crist"
  catchPhrase: "Proactive didactic contingency"
  bs: "synergize scalable supply-chains"

```

</td>
</tr>
</table


```$ ./control-id_jsonp 10``` (todos os posts do usuário 10)

<table>
<tr>
<th> Posts dos usuários JSON </th>
<th> Posts do usuário 10 deserializados </th>
</tr>
<tr>
<td>

```
[
  {
    "userId": 10,
    "id": 91,
    "title": "aut amet sed",
    "body": "libero voluptate eveniet aperiam sed\nsunt 
    placeat suscipit molestias\nsimilique fugit nam 
    natus\nexpedita consequatur consequatur dolores 
    quia eos et placeat"
  },
  {
    "userId": 10,
    "id": 92,
    "title": "ratione ex tenetur perferendis",
    "body": "aut et excepturi dicta laudantium sint 
    rerum nihil\nlaudantium et at\na neque minima 
    officia et similique libero et\ncommodi voluptate 
    qui"
  },
  {
    "userId": 10,
    "id": 93,
    "title": "beatae soluta recusandae",
    "body": "dolorem quibusdam ducimus consequuntur 
    dicta aut quo laboriosam\nvoluptatem quis enim 
    recusandae ut sed sunt\nnostrum est odit 
    totam\nsit error sed sunt eveniet provident qui 
    nulla"
  },
]
```

</td>
<td>


```
title: "aut amet sed"
body: "libero voluptate eveniet aperiam sed\nsunt 
       placeat suscipit molestias\nsimilique fugit 
       nam natus\nexpedita consequatur consequatur 
       dolores quia eos et placeat"

title: "ratione ex tenetur perferendis"
body: "aut et excepturi dicta laudantium sint 
      rerum nihil\nlaudantium et at\na neque minima 
      officia et similique libero et\ncommodi 
      voluptate qui"

title: "beatae soluta recusandae"
body: "dolorem quibusdam ducimus consequuntur dicta 
      aut quo laboriosam\nvoluptatem quis enim 
      recusandae ut sed sunt\nnostrum est odit 
      totam\nsit error sed sunt eveniet provident 
      qui nulla"

```

</td>
</tr>
</table

