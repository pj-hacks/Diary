SCR = masterAi.o user_creation.o user_existance.o utility.o compliment.o file_creation.o file_management.o 

CC = gcc

CFLAGS = -g -Wall -Werror -Wpedantic 

all: final

final: masterAi.o user_creation.o user_existance.o utility.o compliment.o file_creation.o file_management.o
	$(CC) $(CFLAGS) $(SCR) -o final

masterAi.o: masterAi.c
	$(CC) $(CFLAGS) -c masterAi.c

user_creation.o: user_creation.c
	$(CC) $(CFLAGS) -c user_creation.c

user_existence.o: user_existence.c
	$(CC) $(CFLAGS) -c user_existence.c

utility.o: utility.c
	$(CC) $(CFLAGS) -c utility.c

compliment.o: compliment.c
	$(CC) $(CFLAGS) -c compliment.c

file_creation.o: file_creation.c
	$(CC) $(CFLAGS) -c file_creation.c

file_management.o: file_management.c
	$(CC) $(CFLAGS) -c file_management.c

clean:
	 rm masterAi.o user_creation.o user_existance.o utility.o compliment.o file_creation.o file_management.o




	
