all: adt.cpp main.cpp
		g++ -Wall -o adt $^
clean:
		rm adt