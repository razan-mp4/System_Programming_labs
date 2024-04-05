CC = g++
CFLAGS = -Wall -std=c++11
LIBNAME = libAutoFleet.a

all: libAutoFleet.a UserInterfaceStatic

libAutoFleet.a: Database.o Car.o
	ar rcs $(LIBNAME) $^

Database.o: Database.cpp Database.h Car.h
	$(CC) $(CFLAGS) -c Database.cpp -o Database.o

Car.o: Car.cpp Car.h
	$(CC) $(CFLAGS) -c Car.cpp -o Car.o

UserInterfaceStatic: UserInterface.cpp
	$(CC) $(CFLAGS) -L. -lAutoFleet -o UserInterfaceStatic UserInterface.cpp

clean:
	rm -f *.o *.a UserInterfaceStatic
