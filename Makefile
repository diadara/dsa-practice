CFLAGS	=   -std=gnu99 -Wall -Wextra -g 
LDFLAGS =  -lm
CC = clang
OBJECTS = driver.o

.c.o:
	$(CC) $(CFLAGS)  -c $<

run: $(OBJECTS)
	$(CC) $(CFLAGS) $(DEFS) -o $@ $^ -lc $(LDFLAGS) 
