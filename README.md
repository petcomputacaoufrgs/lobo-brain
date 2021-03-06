## LoBo Brain - Minimax vs Reinforcement Learning

Este projeto contém o código fonte escrito em C++, apenas com as bibliotecas nativas da linguagem. Além disso, foram utilizados métodos de inteligência artificial, como _Reinforcement Learning_ e _Minimax Algorithm With Alpha-Beta Pruning_, a fim de gerar o centro de tomada de decisões dos jogos do projeto LoBo Games.

### Motivação
Diversos jogos de tabuleiro e métodos de aprendizado por reforço são treinados via Q-Learning. O agente pode ser treinado através de episódios, podendo, portanto, jogar contra outra máquina ou contra um ser humano. 

### Contruído através de
 * C++
 * Python
### Intruções para execução
Para replicar o resultado dos experimentos, é necessário:
* Compilar o código em C++ (necessário gcc) - Preferencialmente Linux
  - Para treino do algoritmo (150000 rounds):
   
    ```
    make test_train.exe
    ```
  - Para jogar contra a máquina:
    ```
    make test_play.exe
    ```
* Executar os arquivos .exe
  - Para treino do algoritmo (150000 rounds):
    
    ```
    ./test_train.exe
    ```
    
  - Para jogar contra a máquina
   
    ```
    ./test_play.exe
    ```
    
### Estrutura computacional

Para implementar uma versão digital do jogo de tabuleiro, é preciso modelar sua estrutura e comportamento para que sejam representadas computacionalmente.
A estrutura dos jogos de tabuleiro pode ser modelada a partir dos seguintes elementos básicos:

    * O estado atual do tabuleiro: configuração das peças no momento;
    * Informação de quem irá se mover: jogador 1 ou jogador 2, peças azuis ou vermelhas, etc.
    
O comportamento do jogo é definido sob as regras do jogo em questão, e consiste em:

    * conjunto de regras de movimentação: oque pode e oque não pode ser feito
    * conjunto de regras de posicionamento:  determina se uma configuração de peças é válida
    * condições de término do jogo: característica dos tabuleiros onde o jogo encerra
    
Tendo em vista que tabuleiros são formados por "casas" e "caminhos", podemos representá-los por meio de um grafo (que pode ser generalizado para tabuleiros NxN) ou uma matriz de caracteres (de tamanho 3x3 no caso do Tapatan), onde os possíveis caminhos são harcoded, isto é, definidos dentro do código.
Cada "casa" representa uma posição que pode ser ocupada pelo jogador 1 (representado em preto), 2 (representado em vermelho), ou que pode estar vazia (representada em cinza).
Tais estruturas são denotadas nas Figuras abaixo, ambas descrevendo o jogo Tapatan em seu estado inicial:

<img src="/img/tapatan-grafo.png">

<img src="/img/tapatan-matriz.png">

Para a implementação do algoritmo MiniMax foram utilizadas duas formas diferentes de estruturação dos dados do tabuleiro, já apresentados anteriormente. São elas: grafo  e matriz . Para o algoritmo <i>Q-Learing</i>, optou-se por utilizar apenas esta última. Podemos implementar, portanto um tabuleiro através da seguinte linha de código:

 ```
    Board initial_state ({
                          {'2', '1', '2'},
                          {'0', '0', '0'},
                          {'1', '2', '1'}
                         }
                        );
 ```

Dessa forma, para definições de diferentes formas de tabuleiros, devem ser previamente estruturados de modo que o tabuleiro possa ser representado através de uma matriz de caracteres.

### Definições de funções (método de Reinforcement Learning)
#### test_train.cpp

A partir da definição de dois agentes (jogadores um e dois) podemos definir os parâmetros de treino dos agentes através dos valores de <i>alpha</i>, <i>gamma</i> e <i>epsilon</i>. Através dessa definição, podemos treinar um dos agentes através de jogos sucessivos contra uma máquina com decisões aleatórias. Dessa forma, podemos deifnir a quantidade de trino atrvés da seguinte linha:

 ```
    setup.train(x, y);
  ```
  
 Realizamos a chamada da função train através de dois parâmetros os quais <i>x</i> = quantidade de rounds de treino (do tipo inteiro) e <i>y</i> = agente a ser treinado (do tipo char '1' ou '2').
 
 No fim no treino são gerados dois arquivos contendo dados que serão usados na execução da inteligência do jogo, q-table.csv e reward.csv. O arquivo q-table.csv guarda os valores da <i>Q-Table</i> os quais serão usados nas tomadas de decisões durante o jogo e o arquivo reward.csv guarda dados das recompensas do agente a cada rodado, esses dados serão usados somente para extração de dados, sem, necessariamente impacto na execução do programa.
 
 Através da quantidade de treino passada como parâmetro <i>x</i> para a função <i>train</i> conseguimos definir a dificuldade do jogo, baseando-se nos seguintes dados:
 
  <img src="/img/winrate.jpg">
  
 Podemos concluir que teremos três graus de dificuldade baseando-se nos dados de taxa de vitória:
 
  * Fácil: 2000 <= treinos < 5000
  * Médio: 5000 <= treinos < 10000
  * Dificíl: 10000 <= treinos <= 25000
  
  Para maiores quantidade de treino, o nível de dificuldade do jogo se torna impossível, pois a máquina atinge cerca de 100% de taxa de vitória.

#### test_play.cpp

É a função da para a execução da versão demo do programa. Através dessa função, o jogador pode testar diferentes níveis de dificuldade jogando contra a máquina previamente treinada.

A função utiliza do arquivo q-table.csv para a tomada de decisões da máquina através da linha

 ```
    setup.p1->load_policy(file_name);
  ```
  
 Onde pode-se definir qual jogador receberá a quantidade de treino pré-definida e <i>file_name</i> é o nome do arquivo no qual está a <i>Q-Table</i>.
### Tipos de tabuleiros suportados
* Tapatan;
 <img src="https://www.yourkidsot.com/uploads/2/4/0/3/24030117/s780171065908427913_p57_i1_w1654.png" height="200" width="150">
 
* Pong Hau K'i (apenas pelo algoritmo mimimax - jogo de bloqueio);

 <img src="https://i.pinimg.com/736x/ab/f2/41/abf241ae7a831cfc3e0cbf8033f64fea.jpg" height="200" width="150">
 
Pode-se utilizar os algoritmos implementados em outros jogos de tabuleiro. Para isso, deve-se abstrair o novo tabuleiro e implementar suas regras. Temos duas funções que devem ser modificadas para futuras adaptações nas regras e no tabuleiro.

A função

 ```
   int State::winner()
 ```
 que define as regras do jogo e as condições de vitória, e a função
 
  ```
   vector<vector<int>> State::possible_moves(int player_position)
  ```
  que define as possíveis movimentações da máquina de acordo com o tabuleiro.

Há atualmente duas formas de abstração de tabuleiros: grafo e matriz. Para jogos onde consegue-se mapear as posições ("casas")  em uma matriz, a utilização desta é recomendada pois facilita a implementação do algoritmo Q-learning, que é mais eficiente e preferível ao MiniMax.

Já para tabuleiros de maior complexidade (muitas posições de peças, muitos caminhos, mais formas de movimentação de peças, etc.) é recomendado o uso de grafos como estrutura representativa do tabuleiro, uma vez que este tipo permite alta generalidade, facilita a busca por informações e a aplicação de métodos. Tal estrutura já encontra-se implementada sobre os jogos Tapatan e Pong Hau K'i, e portanto deve ser de fácil conversão para outros tabuleiros. 
É importante destacar, porém, que o algoritmo Q-learning <b>NÃO</b> foi implementado usando representação por grafo, apenas matriz, e por isso se faz necessária ao leitor desenvolver uma nova abstração que dê conta de todos os requisitos do jogo em questão (geralmente posições das peças, caminhos/movimentações possiveis, regras e condições de término).
 
 

 
