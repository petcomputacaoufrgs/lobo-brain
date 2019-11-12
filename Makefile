CC=g++

all: vde node move tree

vde: VDE.cpp
	$(CC) --std=c++11 VDE.cpp -o VDE

node: node.cpp
	$(CC) --std=c++11 node.cpp -o node

move: move.cpp
	$(CC) --std=c++11 move.cpp -o move

tree: tree.cpp
	$(CC) --std=c++11 tree.cpp node.cpp -o tree

clean:
	rm -rf *.o VDE node move  tree

