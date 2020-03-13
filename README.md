## LoBo Brain - Reinforcement Learning

Este projeto contém o código fonte escrito em C++, apenas com as bibliotecas nativas da linguagem. Além disso, foram utilizados métodos de inteligência artificial, como Reinforcement Learning, a fim de gerar o centro de tomada de decisões dos jogos do projeto LoBo Games.

### Motivação
Diversos jogos de tabuleiro e métodos de aprendizado por reforço são treinados via Q-Learning. O agente pode ser treinado através de episódios, podendo, portanto, jogar contra outra máquina ou contra um ser humano. 

Este projeto foin realizado a fim de realizar alguns levantamentos sobre os métodos de aprendizagem abordados.

### Contruído através de
 * C++
 * Python

Para replicar o resultado dos experimentos, é necessário:
* Compilar o código em C++ (necessário gcc) - Preferencialmente Linux
  - Para treino do algoritmo (50000 rounds):
   
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
### Tipos de tabuleiros suportados
* Tapatan;
 <img src="https://www.yourkidsot.com/uploads/2/4/0/3/24030117/s780171065908427913_p57_i1_w1654.png" height="400" width="300">
 

 
