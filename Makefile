# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11
# FLAGS do linker
LDFLAGS = 
# OBJ files obrigatorios pra todo teste
OBJ_FILES = tree.o node.o tabuleiro.o vde.o decision.o

# Comando default: adicione os testes aqui
all: decision_teste.exe

# Comando generico de exe
%_teste.exe: %_teste.o $(OBJ_FILES)
	g++ $^ -o $@ $(LDFLAGS)

# Comando generico de .o
%.o: %.cpp
	g++ -c $^ -o $@ $(CXXFLAGS)

# Limpa os arquivos construidos
clean:
	rm -rf *.o *.exe
