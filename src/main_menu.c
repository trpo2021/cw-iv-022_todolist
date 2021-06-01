#include "todo_list.h"

void todolist(FILE* file[10])
{
    int number, id;

    do {
        printf("id            Task name                                      "
               "      Description                                    Status "
               "   Date    Priority       Category            Progress\n");
        read_tasks(file[0]);
        printf("\n");
        printf("1. Add task\n");
        printf("2. Move to bin\n");
        printf("3. Edit task\n");
        printf("4. Move to archive\n");
        printf("5. Sort\n");
        printf("6. Duplicate task\n");
        printf("7. Exit in main menu\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            add(file);
            break;
        case 2:
            printf("Input the task id: ");
            scanf("%d", &id);
            move_to_bin(file, id);
            break;
        case 3:
            printf("Input the task id: ");
            scanf("%d", &id);
            edit(file[0], id);
            break;
        case 4:
            printf("Input the task id: ");
            scanf("%d", &id);
            move_to_archive(file, id);
            break;
        case 5:
            sort(file[0], id);
            break;
        case 6:
            printf("Input the task id: ");
            scanf("%d", &id);
            duplication(file, id);
            break;
        case 7:
            break;
        }
    } while (number != 7);
}

void authors()
{
    printf("1. Машкалев Роман\n");
    printf("2. Конышев Архип\n");
    printf("3. Барашков Павел\n");
}
