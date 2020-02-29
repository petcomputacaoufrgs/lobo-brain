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
all: State.exe Agent.exe Global.exe

# Comando generico de .o
%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

teste.exe: Agent.o State.o Global.o
	$(CXX) $^ -o $@ $(LDFLAGS)

# Limpa os arquivos construidos
clean:
	$(RM) *.o *.exe
