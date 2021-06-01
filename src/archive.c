#include "archive.h"
#include "todo_list.h"

void archive(FILE* file[10])
{
    int id, number;

    do {
        printf("id            Task name                                      "
               "      Description                                    Status "
               "   Date    Priority       Category            Progress\n");
        read_tasks(file[2]);
        printf("\n");
        printf("1. Move to bin\n");
        printf("2. Clearing the archive\n");
        printf("3. Unzipping task\n");
        printf("4. Exit in main menu\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            printf("Input the task id: ");
            scanf("%d", &id);
            delete_task_from_the_archive(file, id);
            break;
        case 2:
            clean_archive(file);
            break;
        case 3:
            printf("Input the task id: ");
            scanf("%d", &id);
            unarchive(file, id);
            break;
        case 4:
            break;
        }
    } while (number != 4);
}

void delete_task_from_the_archive(FILE* file[10], int id)
{
    const int number = find_id(file[2]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[2], &tasks[i], (i + 1));

    file[2] = fopen("users/user1archive.txt", "w+");

    for (int i = 0; i < number; i++) {
        int archive_id = find_id(file[2]);
        if (i != (id - 1))
            write_in_file(file[2], &tasks[i], archive_id);
    }
}

void clean_archive(FILE* file[10])
{
    file[2] = fopen("users/user1archive.txt", "w+");
}

void unarchive(FILE* file[10], int id)
{
    const int number = find_id(file[2]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[2], &tasks[i], (i + 1));

    int archive_id = find_id(file[0]);
    write_in_file(file[0], &tasks[id - 1], archive_id);

    file[2] = fopen("users/user1archive.txt", "w+");

    for (int i = 0; i < number; i++) {
        archive_id = find_id(file[2]);
        if (i != (id - 1))
            write_in_file(file[2], &tasks[i], archive_id);
    }
}
