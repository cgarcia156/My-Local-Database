# Makefile for My Local Database

# ********************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ********************************************

run: main.o stokenizer.o sTable.o token.o record.o parser.o table.o sql.o rpn.o shunting_yard.o
	$(CC) $(CFLAGS) -o run main.o stokenizer.o st_table.o token.o record.o parser.o table.o sql.o rpn.o shunting_yard.o

main.o: src/main.cpp sql.o
	$(CC) $(CFLAGS) -c -std=c++11 src/main.cpp

stokenizer.o: src/stokenizer.cpp includes/stokenizer.h st_table.o
	$(CC) $(CFLAGS) -c -std=c++11 src/stokenizer.cpp

st_table.o: src/st_table.cpp includes/st_table.h
	$(CC) $(CFLAGS) -c -std=c++11 src/st_table.cpp

token.o: src/token.cpp includes/data_structures/token.h
	$(CC) $(CFLAGS) -c -std=c++11 src/token.cpp

record.o: src/record.cpp includes/record.h
	$(CC) $(CFLAGS) -c -std=c++11 src/record.cpp

parser.o: src/parser.cpp includes/parser.h
	$(CC) $(CFLAGS) -c -std=c++11 src/parser.cpp

table.o: src/table.cpp includes/table.h includes/shunting_yard.h
	$(CC) $(CFLAGS) -c -std=c++11 src/table.cpp

sql.o: src/sql.cpp includes/sql.h table.o parser.o
	$(CC) $(CFLAGS) -c -std=c++11 src/sql.cpp

rpn.o: src/rpn.cpp includes/rpn.h
	$(CC) $(CFLAGS) -c -std=c++11 src/rpn.cpp

shunting_yard.o: src/shunting_yard.cpp includes/shunting_yard.h
	$(CC) $(CFLAGS) -c -std=c++11 src/shunting_yard.cpp
	
clean:
	rm *.o run