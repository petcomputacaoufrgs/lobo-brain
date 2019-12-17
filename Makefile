# USO
# make TESTE=decision
# make TESTE=tree
# ...etc

# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11
# FLAGS do linker
LDFLAGS = 
# OBJ files obrigatorios pra todo teste
OBJ_FILES = tree.o node.o tabuleiro.o vde.o decision.o
# Especifica o teste
TESTE=decision

# Comando default: adicione os testes aqui
all: $(TESTE)_teste.exe

# Comando generico de .o
%.o: %.cpp
	g++ -c $^ -o $@ $(CXXFLAGS)

# Comando generico de exe
$(TESTE)_teste.exe: $(TESTE)_teste.o $(OBJ_FILES)
	g++ $^ -o $@ $(LDFLAGS)

# Limpa os arquivos construidos
clean:
	rm -rf *.o *.exe
