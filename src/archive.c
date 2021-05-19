#include "archive.h"
#include "todo_list.h"

void archive(FILE* file[10])
{
    int id, number;

    do {
        printf("id            Название                                         "
               "         Описание                                  Статус    "
               "Дата    Приоритет       Категория          Прогресс\n");
        read_tasks(file[2]);
        printf("\n");
        printf("1. Удаление дела\n");
        printf("2. Очистка архива\n");
        printf("3. Разархивирование дела\n");
        printf("4. Сортировка\n");
        printf("5. Выход в главное меню\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            delete_task_from_the_archive(file, id);
            break;
        case 2:
            clean_archive(file);
            break;
        case 3:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            unarchive(file, id);
            break;
        case 4:
            break;
        case 5:
            break;
        }
    } while (number != 5);
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
