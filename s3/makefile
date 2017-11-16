CC= g++ -std=c++11
CPPFLAGS= -g

main: main.o pais.o comarca.o municipi.o EMD.o
	$(CC) -o main *.o

%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) -c $<

