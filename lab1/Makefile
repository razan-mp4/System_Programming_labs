CC = g++
CFLAGS = -std=c++11 -Wall
SRCS = Database.cpp Car.cpp UserInterface.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = CarDatabase

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

Database.o: Database.cpp Database.h Car.h
	$(CC) $(CFLAGS) -c Database.cpp -o Database.o

Car.o: Car.cpp Car.h
	$(CC) $(CFLAGS) -c Car.cpp -o Car.o

UserInterface.o: UserInterface.cpp Database.h
	$(CC) $(CFLAGS) -c UserInterface.cpp -o UserInterface.o

clean:
	rm -f $(OBJS) $(TARGET)
