all : nodetest

nodetest : nodetest.o
	clang++ nodetest.cpp -o nodetest

nodetest.o : nodetest.cpp
	clang++ -c nodetest.cpp

clean : 
	rm -f *.o nodetest