#include "todo_list.h"

void todolist(FILE* file[10])
{
    int number, id;

    do {
        printf("id            Название                                         "
               "         Описание                                  Статус    "
               "Дата    Приоритет       Категория          Прогресс\n");
        read_tasks(file[0]);
        printf("\n");
        printf("1. Добавление\n");
        printf("2. Перемещение в корзину\n");
        printf("3. Редактирование\n");
        printf("4. Архивирование\n");
        printf("5. Сортировка\n");
        printf("6. Закрепление\n");
        printf("7. Дублирование\n");
        printf("8. Выход в главное меню\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            add(file);
            break;
        case 2:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            move_to_bin(file, id);
            break;
        case 3:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            edit(file[0], id);
            break;
        case 4:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            move_to_archive(file, id);
            break;
        case 5:
            sort(file[0], id);
            break;
        case 6:
            break;
        case 7:
            printf("Введите номер дела: ");
            scanf("%d", &id);
            duplication(file, id);
            break;
        case 8:
            break;
        }
    } while (number != 8);
}

int settings()
{
    return 0;
}

void authors()
{
    printf("1. Машкалев Роман\n");
    printf("2. Конышев Архип\n");
    printf("3. Барашков Павел\n");
}
