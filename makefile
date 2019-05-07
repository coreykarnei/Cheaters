final: plagiarismCatcher.o node.o hash.o
	g++ -std=c++0x -o plagiarismCatcher  plagiarismCatcher.o node.o hash.o
driver: plagiarismCatcher.cpp node.h
	g++ -std=c++0x -c plagiarismCatcher.cpp
node.o: node.cpp node.h
	g++ -std=c++0x -c node.cpp
hash.o: hash.cpp hash.h
	g++ -std=c++0x -c hash.cpp
