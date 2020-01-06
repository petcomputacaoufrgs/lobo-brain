# USO
# make tree_teste.exe
# make decision_teste.exe
# ...etc

CXX = g++
# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11 -g
# FLAGS do linker
LDFLAGS = 

# Comando default: adicione os testes aqui
all: tree_teste.exe decision_teste.exe

# Comando generico de .o
%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

tree_teste.exe: tree_teste.o tree.o node.o tabuleiro.o VDE.o move.o
	$(CXX) $^ -o $@ $(LDFLAGS)

decision_teste.exe: decision_teste.o tree.o node.o tabuleiro.o VDE.o decision.o move.o
	$(CXX) $^ -o $@ $(LDFLAGS)	

move_teste.exe: move_teste.o move.o
	$(CXX) $^ -o $@ $(LDFLAGS)	

# Limpa os arquivos construidos
clean:
	$(RM) *.o *.exe
