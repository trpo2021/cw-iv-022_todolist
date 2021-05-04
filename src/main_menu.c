#include "todo_list.h"

void todolist(FILE *file[10])
{
    int number;
    
    do
    {
        printf("1. Добавление\n");
        printf("2. Перемещение в корзину\n");
        printf("3. Редактирование\n");
        printf("4. Архивирование\n");
        printf("5. Сортировка\n");
        printf("6. Закрепление\n");
        printf("7. Дублирование\n");
        printf("8. Выход в главное меню\n");
        scanf("%d", &number);
        switch(number)
        {
            case 1:
                add(file);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                for(int i = 0; i < 10; i++)
                {
                    if((file[i] != NULL) && (file[i] != 0))
                        fclose(file[i]);
                }
                break;
            case 7:
                break;
            case 8:
                break;
        }
    } while (number != 8);
}

int archive()
{

    return 0;
}

int bin()
{

    return 0;
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

int find_id(FILE *file)
{
    char string[250];
    int id = 0;

    fseek(file, 0, SEEK_SET);
    while(feof(file) == 0)
    {
        fgets(string, 250, file);
        id++;
    }
    return id;
}