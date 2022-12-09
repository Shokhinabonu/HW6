all: 
	g++ -Wall -g RedBlackTree.cpp SpeedTest.cpp -std=c++14 -o rbt
run: 
	./rbt
 
try: all run

val:
	valgrind ./rbt