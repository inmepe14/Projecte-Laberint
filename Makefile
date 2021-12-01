#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Wno-sign-compare -std=c++11
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11
all: main.exe  #driver_maze.exe

main.exe: main.o cambra.o paret.hpp laberint.o
	g++ -o main.exe main.o cambra.o paret.hpp laberint.o -lesin

#driver_maze.exe: driver_maze.o cambra.o paret.hpp
#g++ -o main.exe driver_maze.o cambra.o paret.hpp -lesin

#	Descomenteu les següents línies si voleu executar tots
#	els jocs de proves.
	
#	./main.exe < samplemeu1.inp
#	./test.exe < sample2.inp > sample2.cor
#	./test.exe < sample3.inp > sample3.cor
#	./test.exe < sample4.inp > sample4.cor
#	./test.exe < sample5.inp > sample5.cor
		
main.o: main.cpp cambra.hpp
	g++ -c main.cpp $(OPCIONS)
	
#driver_maze.o: driver_maze.cpp 
# g++ -c driver_maze.cpp $(OPCIONS)
#paret.o: paret.hpp
#	g++ -c paret.hpp $(OPCIONS)

cambra.o: cambra.cpp cambra.hpp
	g++ -c cambra.cpp $(OPCIONS)

laberint.o: laberint.cpp laberint.hpp
	g++ -c laberint.cpp $(OPCIONS)

#Magatzem.o: Magatzem.cpp Magatzem.hpp
#	g++ -c Magatzem.cpp $(OPCIONS)


clean:
	rm *.o
	rm *.exe
