
CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS = -shared
LIBNAME = libAutoFleet

all: libAutoFleet.so UserInterfaceDynamic

libAutoFleet.so: Database.o Car.o
	$(CC) $(LDFLAGS) -o $(LIBNAME).so $^

Database.o: Database.cpp Database.h Car.h
	$(CC) $(CFLAGS) -fPIC -c Database.cpp -o Database.o

Car.o: Car.cpp Car.h
	$(CC) $(CFLAGS) -fPIC -c Car.cpp -o Car.o

UserInterfaceDynamic: UserInterface.cpp
	$(CC) $(CFLAGS) -L. -lAutoFleet -o UserInterfaceDynamic UserInterface.cpp

clean:
	rm -f *.o *.so UserInterfaceDynamic
