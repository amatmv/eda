CC= g++ 
CPPFLAGS= -std=c++0x

main: main.o Ordinador.o Vehicle.o Cotxe.o Moto.o
		$(CC) -o main *.o

Ordinador.o: Ordinador.cpp Ordinador.h
		$(CC) $(CPPFLAGS) -c $<

Vehicle.o: Vehicle.cpp Vehicle.h
		$(CC) $(CPPFLAGS) -c $<

Cotxe.o: Cotxe.cpp Cotxe.h
		$(CC) $(CPPFLAGS) -c $<

Moto.o: Moto.cpp Moto.h
		$(CC) $(CPPFLAGS) -c $<

clean:
		rm *.o
