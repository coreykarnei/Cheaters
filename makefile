final: plagiarismCatcher.o dir.o hash.o
	g++ -std=c++0x -o plagiarismCatcher  plagiarismCatcher.o dir.o hash.o
driver: plagiarismCatcher.cpp dir.h
	g++ -std=c++0x -c plagiarismCatcher.cpp
dir.o: dir.cpp dir.h
	g++ -std=c++0x -c dir.cpp
hash.o: hash.cpp hash.h
	g++ -std=c++0x -c hash.cpp