all: test

test: main.o Drink.o Food.o Bar.o Restaurant.o
        g++ -o test main.o Drink.o Food.o Bar.o Restaurant.o

Food.o: Food.cpp Food.h 
        g++ -c Food.cpp

Drink.o: Drink.cpp Drink.h
        g++ -c Drink.cpp
		
Bar.o: Bar.cpp Bar.h
        g++ -c Bar.cpp

Restaurant.o: Restaurant.cpp Restaurant.h
        g++ -c Restaurant.cpp

main.o: main.cpp
        g++ -c main.cpp
