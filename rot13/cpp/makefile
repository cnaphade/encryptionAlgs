test: rot13
	./testcpp.sh

rot13: rot13.o
	g++ rot13.o -o rot13

rot13.o: rot13.cpp
	g++ -c rot13.cpp

clean:
	rm *.o