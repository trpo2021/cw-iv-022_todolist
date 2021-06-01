#include "bin.h"
#include "todo_list.h"

void bin(FILE* file[10])
{
    int id, number;

    do {
        printf("id            Task name                                      "
               "      Description                                    Status "
               "   Date    Priority       Category            Progress\n");
        read_tasks(file[1]);
        printf("\n");
        printf("1. Delete task\n");
        printf("2. Clearing the bin\n");
        printf("3. Restoring the task\n");
        printf("4. Exit in main menu\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            printf("Input the task id: ");
            scanf("%d", &id);
            if (id == 0)
                clear_stdin();
            while ((id < 1) || (id > 99)) {
                printf("Input the correct id: ");
                id = scanf("%d", &id);
                if (id == 0)
                    clear_stdin();
            }
            delete_task(file, id);
            break;
        case 2:
            clean_bin(file);
            break;
        case 3:
            printf("Input the task id: ");
            scanf("%d", &id);
            if (id == 0)
                clear_stdin();
            while ((id < 1) || (id > 99)) {
                printf("Input the correct id: ");
                id = scanf("%d", &id);
                if (id == 0)
                    clear_stdin();
            }
            restore_from_bin(file, id);
            break;
        case 4:
            break;
        }
    } while (number != 4);
}

void delete_task(FILE* file[10], int id)
{
    const int number = find_id(file[1]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[1], &tasks[i], (i + 1));

    file[1] = fopen("users/user1bin.txt", "w+");

    for (int i = 0; i < number; i++) {
        int bin_id = find_id(file[1]);
        if (i != (id - 1))
            write_in_file(file[1], &tasks[i], bin_id);
    }
}

void clean_bin(FILE* file[10])
{
    file[1] = fopen("users/user1bin.txt", "w+");
}

void restore_from_bin(FILE* file[10], int id)
{
    const int number = find_id(file[1]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[1], &tasks[i], (i + 1));

    int bin_id = find_id(file[0]);
    write_in_file(file[0], &tasks[id - 1], bin_id);

    file[1] = fopen("users/user1bin.txt", "w+");

    for (int i = 0; i < number; i++) {
        bin_id = find_id(file[1]);
        if (i != (id - 1))
            write_in_file(file[1], &tasks[i], bin_id);
    }
}
