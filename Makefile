all: todo
todo: main_menu.o main.o todo_list.o
	gcc -Wall -Werror -o todo main.o main_menu.o todo_list.o
main_menu.o: main_menu.c
	gcc -Wall -c -Werror -o main_menu.o main_menu.c
main.o: main.c
	gcc -Wall -c -Werror -o main.o main.c
todo_list.o: todo_list.c
	gcc -Wall -c -Werror -o todo_list.o todo_list.c