CC := gcc

CFLAGS := -std=c99 -Wall -Werror -I inc/ -g3

OBJS := print.o map_create.o create_matr.o dijkstra.o

.PHONY : clean

app.exe : $(OBJS) main.o
	$(CC) $^ -o $@

%.o : src/%.c inc/*.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm *.o *.exe
