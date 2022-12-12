test_random: xor
	./testcpp.sh random

test: xor
	./testcpp.sh

xor: xor.o
	g++ xor.o -o xor

xor.o: xor.cpp
	g++ -c xor.cpp

clean:
	rm *.o