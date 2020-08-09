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

6. Abaixo, informações 

<table>
<tr>
<th> Dados dos usuários *(JSON)* </th>
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
  },
  {
    "id": 3,
    "name": "Clementine Bauch",
    "username": "Samantha",
    "email": "Nathan@yesenia.net",
    "address": {
      "street": "Douglas Extension",
      "suite": "Suite 847",
      "city": "McKenziehaven",
      "zipcode": "59590-4157",
      "geo": {
        "lat": "-68.6102",
        "lng": "-47.0653"
      }
    },
    "phone": "1-463-123-4447",
    "website": "ramiro.info",
    "company": {
      "name": "Romaguera-Jacobson",
      "catchPhrase": "Face to face bifurcated interface",
      "bs": "e-enable strategic applications"
    }
  },
  {
    "id": 4,
    "name": "Patricia Lebsack",
    "username": "Karianne",
    "email": "Julianne.OConner@kory.org",
    "address": {
      "street": "Hoeger Mall",
      "suite": "Apt. 692",
      "city": "South Elvis",
      "zipcode": "53919-4257",
      "geo": {
        "lat": "29.4572",
        "lng": "-164.2990"
      }
    },
    "phone": "493-170-9623 x156",
    "website": "kale.biz",
    "company": {
      "name": "Robel-Corkery",
      "catchPhrase": "Multi-tiered zero tolerance productivity",
      "bs": "transition cutting-edge web services"
    }
  },
  {
    "id": 5,
    "name": "Chelsey Dietrich",
    "username": "Kamren",
    "email": "Lucio_Hettinger@annie.ca",
    "address": {
      "street": "Skiles Walks",
      "suite": "Suite 351",
      "city": "Roscoeview",
      "zipcode": "33263",
      "geo": {
        "lat": "-31.8129",
        "lng": "62.5342"
      }
    },
    "phone": "(254)954-1289",
    "website": "demarco.info",
    "company": {
      "name": "Keebler LLC",
      "catchPhrase": "User-centric fault-tolerant solution",
      "bs": "revolutionize end-to-end systems"
    }
  },
  {
    "id": 6,
    "name": "Mrs. Dennis Schulist",
    "username": "Leopoldo_Corkery",
    "email": "Karley_Dach@jasper.info",
    "address": {
      "street": "Norberto Crossing",
      "suite": "Apt. 950",
      "city": "South Christy",
      "zipcode": "23505-1337",
      "geo": {
        "lat": "-71.4197",
        "lng": "71.7478"
      }
    },
    "phone": "1-477-935-8478 x6430",
    "website": "ola.org",
    "company": {
      "name": "Considine-Lockman",
      "catchPhrase": "Synchronised bottom-line interface",
      "bs": "e-enable innovative applications"
    }
  },
  {
    "id": 7,
    "name": "Kurtis Weissnat",
    "username": "Elwyn.Skiles",
    "email": "Telly.Hoeger@billy.biz",
    "address": {
      "street": "Rex Trail",
      "suite": "Suite 280",
      "city": "Howemouth",
      "zipcode": "58804-1099",
      "geo": {
        "lat": "24.8918",
        "lng": "21.8984"
      }
    },
    "phone": "210.067.6132",
    "website": "elvis.io",
    "company": {
      "name": "Johns Group",
      "catchPhrase": "Configurable multimedia task-force",
      "bs": "generate enterprise e-tailers"
    }
  },
  {
    "id": 8,
    "name": "Nicholas Runolfsdottir V",
    "username": "Maxime_Nienow",
    "email": "Sherwood@rosamond.me",
    "address": {
      "street": "Ellsworth Summit",
      "suite": "Suite 729",
      "city": "Aliyaview",
      "zipcode": "45169",
      "geo": {
        "lat": "-14.3990",
        "lng": "-120.7677"
      }
    },
    "phone": "586.493.6943 x140",
    "website": "jacynthe.com",
    "company": {
      "name": "Abernathy Group",
      "catchPhrase": "Implemented secondary concept",
      "bs": "e-enable extensible e-tailers"
    }
  },
  {
    "id": 9,
    "name": "Glenna Reichert",
    "username": "Delphine",
    "email": "Chaim_McDermott@dana.io",
    "address": {
      "street": "Dayna Park",
      "suite": "Suite 449",
      "city": "Bartholomebury",
      "zipcode": "76495-3109",
      "geo": {
        "lat": "24.6463",
        "lng": "-168.8889"
      }
    },
    "phone": "(775)976-6794 x41206",
    "website": "conrad.com",
    "company": {
      "name": "Yost and Sons",
      "catchPhrase": "Switchable contextually-based project",
      "bs": "aggregate real-time technologies"
    }
  },
  {
    "id": 10,
    "name": "Clementina DuBuque",
    "username": "Moriah.Stanton",
    "email": "Rey.Padberg@karina.biz",
    "address": {
      "street": "Kattie Turnpike",
      "suite": "Suite 198",
      "city": "Lebsackbury",
      "zipcode": "31428-2261",
      "geo": {
        "lat": "-38.2386",
        "lng": "57.2232"
      }
    },
    "phone": "024-648-3804",
    "website": "ambrose.net",
    "company": {
      "name": "Hoeger LLC",
      "catchPhrase": "Centralized empowering task-force",
      "bs": "target end-to-end models"
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

name: "Clementine Bauch"
username: "Samantha"
email: "Nathan@yesenia.net"
address: 
  street: "Douglas Extension"
  suite: "Suite 847"
  city: "McKenziehaven"
  zipcode: "59590-4157"
  geo: 
    lat: "-68.6102"
    long: "-47.0653"
phone: "1-463-123-4447"
website: "ramiro.info"
company: 
  name: "Romaguera-Jacobson"
  catchPhrase: "Face to face bifurcated interface"
  bs: "e-enable strategic applications"

name: "Patricia Lebsack"
username: "Karianne"
email: "Julianne.OConner@kory.org"
address: 
  street: "Hoeger Mall"
  suite: "Apt. 692"
  city: "South Elvis"
  zipcode: "53919-4257"
  geo: 
    lat: "29.4572"
    long: "-164.2990"
phone: "493-170-9623 x156"
website: "kale.biz"
company: 
  name: "Robel-Corkery"
  catchPhrase: "Multi-tiered zero tolerance productivity"
  bs: "transition cutting-edge web services"

name: "Chelsey Dietrich"
username: "Kamren"
email: "Lucio_Hettinger@annie.ca"
address: 
  street: "Skiles Walks"
  suite: "Suite 351"
  city: "Roscoeview"
  zipcode: "33263"
  geo: 
    lat: "-31.8129"
    long: "62.5342"
phone: "(254)954-1289"
website: "demarco.info"
company: 
  name: "Keebler LLC"
  catchPhrase: "User-centric fault-tolerant solution"
  bs: "revolutionize end-to-end systems"

name: "Mrs. Dennis Schulist"
username: "Leopoldo_Corkery"
email: "Karley_Dach@jasper.info"
address: 
  street: "Norberto Crossing"
  suite: "Apt. 950"
  city: "South Christy"
  zipcode: "23505-1337"
  geo: 
    lat: "-71.4197"
    long: "71.7478"
phone: "1-477-935-8478 x6430"
website: "ola.org"
company: 
  name: "Considine-Lockman"
  catchPhrase: "Synchronised bottom-line interface"
  bs: "e-enable innovative applications"

name: "Kurtis Weissnat"
username: "Elwyn.Skiles"
email: "Telly.Hoeger@billy.biz"
address: 
  street: "Rex Trail"
  suite: "Suite 280"
  city: "Howemouth"
  zipcode: "58804-1099"
  geo: 
    lat: "24.8918"
    long: "21.8984"
phone: "210.067.6132"
website: "elvis.io"
company: 
  name: "Johns Group"
  catchPhrase: "Configurable multimedia task-force"
  bs: "generate enterprise e-tailers"

name: "Nicholas Runolfsdottir V"
username: "Maxime_Nienow"
email: "Sherwood@rosamond.me"
address: 
  street: "Ellsworth Summit"
  suite: "Suite 729"
  city: "Aliyaview"
  zipcode: "45169"
  geo: 
    lat: "-14.3990"
    long: "-120.7677"
phone: "586.493.6943 x140"
website: "jacynthe.com"
company: 
  name: "Abernathy Group"
  catchPhrase: "Implemented secondary concept"
  bs: "e-enable extensible e-tailers"

name: "Glenna Reichert"
username: "Delphine"
email: "Chaim_McDermott@dana.io"
address: 
  street: "Dayna Park"
  suite: "Suite 449"
  city: "Bartholomebury"
  zipcode: "76495-3109"
  geo: 
    lat: "24.6463"
    long: "-168.8889"
phone: "(775)976-6794 x41206"
website: "conrad.com"
company: 
  name: "Yost and Sons"
  catchPhrase: "Switchable contextually-based project"
  bs: "aggregate real-time technologies"

name: "Clementina DuBuque"
username: "Moriah.Stanton"
email: "Rey.Padberg@karina.biz"
address: 
  street: "Kattie Turnpike"
  suite: "Suite 198"
  city: "Lebsackbury"
  zipcode: "31428-2261"
  geo: 
    lat: "-38.2386"
    long: "57.2232"
phone: "024-648-3804"
website: "ambrose.net"
company: 
  name: "Hoeger LLC"
  catchPhrase: "Centralized empowering task-force"
  bs: "target end-to-end models"
```

</td>
</tr>
</table




