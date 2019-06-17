CXX = clang++
LD = clang++

CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi


all : listtest nodetest

listtest : listtest.o
	$(CXX) listtest.cpp -o listtest

listtest.o : listtest.cpp
	$(CXX) $(CXXFLAGS) listtest.cpp

nodetest : nodetest.o
	$(CXX) nodetest.cpp -o nodetest

nodetest.o : nodetest.cpp
	$(CXX) $(CXXFLAGS) nodetest.cpp

clean : 
	rm -f *.o nodetest