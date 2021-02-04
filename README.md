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
  - Para treino do algoritmo (50000 rounds):
    
    ```
    ./test_train.exe
    ```
    
  - Para jogar contra a máquina
   
    ```
    ./test_play.exe
    ```
    
### Definições de funções
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
### Tipos de tabuleiros suportados
* Tapatan;
 <img src="https://www.yourkidsot.com/uploads/2/4/0/3/24030117/s780171065908427913_p57_i1_w1654.png" height="200" width="150">
 
* Pong Hau K'i (apenas pelo algoritmo mimimax - jogo de bloqueio);

 <img src="https://i.pinimg.com/736x/ab/f2/41/abf241ae7a831cfc3e0cbf8033f64fea.jpg" height="200" width="150">
 
 

 
