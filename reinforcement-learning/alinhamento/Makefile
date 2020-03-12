# USO
# make test_train.exe
# make test._play.exe
# ...etc

CXX = g++
# FLAGS do compilador .cpp -> .o
CXXFLAGS = -std=c++11 -g
# FLAGS do linker
LDFLAGS = 

# Comando default: adicione os testes aqui
all: test_train.exe test_play.exe State.exe Agent.exe Global.exe

# Comando generico de .o
%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

test_train.exe: test_train.o Agent.o State.o Global.o
	$(CXX) $^ -o $@ $(LDFLAGS)

test_play.exe: test_play.o Agent.o State.o Global.o
	$(CXX) $^ -o $@ $(LDFLAGS)

# Limpa os arquivos construidos
clean:
	$(RM) *.o *.exe
