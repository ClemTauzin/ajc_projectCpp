all: test

test: main.o Drink.o Food.o Pub.o Restaurant.o
	g++ -o test main.o Drink.o Food.o Pub.o Restaurant.o

Food.o: Food.cpp Food.h 
	g++ -c Food.cpp

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp
		
Pub.o: Pub.cpp Pub.h
	g++ -c Pub.cpp

Restaurant.o: Restaurant.cpp Restaurant.h
	g++ -c Restaurant.cpp

main.o: main.cpp
	g++ -c main.cpp
