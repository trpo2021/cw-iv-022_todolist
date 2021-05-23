OFLAGS=gcc -Wall -c -Werror -o
BINFLAGS=gcc -Wall -Werror -o

all: bin/todo
bin/todo: obj/src/main_menu.o obj/src/main.o obj/src/todo_list.o obj/src/bin.o obj/src/archive.o obj/src/libtodo.a
	$(BINFLAGS) $@ $^
obj/src/libtodo.a: obj/src/main_menu.o obj/src/main.o obj/src/todo_list.o obj/src/bin.o obj/src/archive.o
		ar rcs obj/src/libtodo.a obj/src/libtodo.a obj/src/main_menu.o obj/src/main.o obj/src/todo_list.o obj/src/bin.o obj/src/archive.o
obj/src/main_menu.o: src/main_menu.c
	$(OFLAGS) $@ $^
obj/src/main.o: src/main.c
	$(OFLAGS) $@ $^
obj/src/todo_list.o: src/todo_list.c
	$(OFLAGS) $@ $^
obj/src/bin.o: src/bin.c
	$(OFLAGS) $@ $^
obj/src/archive.o: src/archive.c
	$(OFLAGS) $@ $^

test: bin/test

bin/test: obj/test/tests.o obj/test/main.o obj/src/libtodo.a
	gcc -Wall -I thirdparty -I src -Werror -o bin/test obj/test/tests.o obj/test/main.o obj/src/libtodo.a

obj/test/main.o: test/main.c
	gcc -Wall -I thirdparty -I src -Werror -c -o obj/test/main.o test/main.c

obj/test/tests.o: test/tests.c
	gcc -Wall -I thirdparty -I src -Werror -c -o obj/test/tests.o test/tests.c

.PHONY : clean
clean:
	rm -rf obj/src/*.o obj/src/*.a obj/test/*.o obj/test/*.a bin/todo bin/test
