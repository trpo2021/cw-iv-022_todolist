all: bin/todo
bin/todo: obj/main_menu.o obj/main.o obj/todo_list.o
	gcc -Wall -Werror -o bin/todo obj/main.o obj/main_menu.o obj/todo_list.o
obj/main_menu.o: src/main_menu.c
	gcc -Wall -c -Werror -o obj/main_menu.o src/main_menu.c
obj/main.o: src/main.c
	gcc -Wall -c -Werror -o obj/main.o src/main.c
obj/todo_list.o: src/todo_list.c
	gcc -Wall -c -Werror -o obj/todo_list.o src/todo_list.c

.PHONY : clean
clean:
	rm -rf obj/*.o obj/*.a bin/todo