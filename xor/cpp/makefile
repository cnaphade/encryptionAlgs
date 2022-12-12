test: xor
	./testcpp.sh $(random) $(og_file) $(en_file) $(de_file)

xor: xor.o
	g++ xor.o -o xor

xor.o: xor.cpp
	g++ -c xor.cpp

clean:
	rm *.o