CC=g++

all: vde node tree

vde: VDE.cpp
	$(CC) --std=c++11 VDE.cpp -o VDE

node: node.cpp
	$(CC) --std=c++11 node.cpp -o node

tree: tree.cpp
	$(CC) --std=c++11 tree.cpp node.cpp -o tree

clean:
	rm -rf *.o VDE node tree

