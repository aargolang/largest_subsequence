OBJS = test_driver_data.o 
CC = g++
CPPFLAGS = -Wall -c -g -std=c++11
LFLAGS = -Wall -g

a: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o a

test_driver_data.o: test_driver_data.cpp
	$(CC) $(CPPFLAGS) test_driver_data.cpp

# Person.o: Person.cpp Person.h
#	$(CC) $(CPPFLAGS) Person.cpp
#
#ListMyJosephus.o: ListMyJosephus.cpp ListMyJosephus.h
#	$(CC) $(CPPFLAGS) ListMyJosephus.cpp
#
#VectorMyJosephus.o: VectorMyJosephus.cpp VectorMyJosephus.h
#	$(CC) $(CPPFLAGS) VectorMyJosephus.cpp

clean: 
	rm -f *.o 
	rm -f a
