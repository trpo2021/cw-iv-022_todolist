#include <stdio.h>
#include <locale.h>

typedef struct
{
    char description[100];
    char name[50];
    char category[25];
    char priority[4];
    char status[2];
    int day;
    int month;
    int year;
    int progress;
} task;

void add(FILE *file[10])
{
    task task1;

    setlocale(LC_ALL, "Russian");
    printf("'*' помечены обязательные пункты\n");
    printf("Введите название дела*: ");
    fgetc(stdin);
    fgets(task1.name, 50, stdin);
    printf("Введите описание дела: ");
    fgets(task1.description, 100, stdin);
    printf("Введите статус выполнения('-' не начал, '~' в процессе)*: ");
    scanf("%s", task1.status);
    printf("Введите крайний срок(через пробел: день месяц год): ");
    scanf("%d %d %d", &task1.day, &task1.month, &task1.year);
    printf("Введите приоритет дела(* - низкий, ** - средний, *** - высокий)*: ");
    scanf("%s", task1.priority);
    printf("Введите категорию дела: ");
    fgetc(stdin);
    fgets(task1.category, 25, stdin);
    printf("Введите прогресс выполнения: ");
    scanf("%d", &task1.progress);

    fprintf(file[0], "%s|", task1.name);
    fprintf(file[0], "%s|", task1.description);
    fprintf(file[0], "%s|", task1.status);
    fprintf(file[0], "%d|", task1.day);
    fprintf(file[0], "%d|", task1.month);
    fprintf(file[0], "%d|", task1.year);
    fprintf(file[0], "%s|", task1.priority);
    fprintf(file[0], "%s|", task1.category);
    fprintf(file[0], "%d|", task1.progress);
}

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

int main()
{
    int number, i;
    

    FILE* file[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    file[0] = fopen("user1.txt", "w+");
    do
    {
        printf("1. Список дел\n");
        printf("2. Архив\n");
        printf("3. Корзина\n");
        printf("4. Настройки\n");
        printf("5. Авторы\n");
        printf("6. Сохранить и выйти\n");
        scanf("%d", &number);
        switch(number)
        {
            case 1:
                todolist(file);
                break;
            case 2:
                archive();
                break;
            case 3:
                bin();
                break;
            case 4:
                settings();
                break;
            case 5:
                authors();
                break;
            case 6:
                for(i = 0; i < 10; i++)
                {
                    if((file[i] != NULL) && (file[i] != 0))
                        fclose(file[i]);
                }
                break;
        }
    } while (number != 6);

    return 0;
}