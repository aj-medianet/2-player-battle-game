
output: main.o Node.o LinkedListContainers.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Menu.o Vampire.o
	g++ main.o Node.o LinkedListContainers.o Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Menu.o Vampire.o -o output

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp Node.hpp
	g++ -c Node.cpp

LinkedListContainers.o: LinkedListContainers.cpp LinkedListContainers.hpp
	g++ -c LinkedListContainers.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp	

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

clean:
	rm *.o output
