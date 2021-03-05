Vector: funkcijos.o
	g++ -o Vector Vector.cpp funkcijos.o
funkcijos:
	g++ -c funkcijos.cpp
clean:
	rm *.o Vector
