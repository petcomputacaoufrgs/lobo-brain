CC=g++

all: vde node tree decision

vde: VDE.cpp
	$(CC) --std=c++11 VDE.cpp -o VDE

node: node.cpp
	$(CC) --std=c++11 node.cpp -o node

tree: tree.cpp
	$(CC) --std=c++11 tree.cpp node.cpp -o tree

tree: decision.cpp
	$(CC) --std=c++11 decision.cpp node.cpp -o decision

clean:
	rm -rf *.o VDE node tree

