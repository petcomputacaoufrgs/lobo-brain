//talvez nao deva ser uma main
// mas sim uma parada do tipo joga_ai{}
int main() {
    
        // tab.posicoesuleiro na posicao inicial
        // 0 = vazio
        // 1/2 = jogador
    
        Tabuleiro start ({	{'1', '2', '1'},
                            {'0', '0', '0'},
                            {'2', '1', '2'}		});
    
        // gera arvore do inicio
        Tree* test_tree = new Tree(start);
        // repeticoes inicias
        int rep = 0;
        // escolha de jogada
        Node *choice = decision(test_tree, test_tree->root, &rep);
    
    
    }
