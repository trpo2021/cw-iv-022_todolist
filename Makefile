OFLAGS=gcc -Wall -c -Werror -o
BINFLAGS=gcc -Wall -Werror -o

all: bin/todo
bin/todo: obj/main_menu.o obj/main.o obj/todo_list.o obj/bin.o
	$(BINFLAGS) $@ $^
obj/main_menu.o: src/main_menu.c
	$(OFLAGS) $@ $^
obj/main.o: src/main.c
	$(OFLAGS) $@ $^
obj/todo_list.o: src/todo_list.c
	$(OFLAGS) $@ $^
obj/bin.o: src/bin.c
	$(OFLAGS) $@ $^

.PHONY : clean
clean:
	rm -rf obj/*.o obj/*.a bin/todo