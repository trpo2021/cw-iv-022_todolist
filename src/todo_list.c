#include "main_menu.h"

void add(FILE *file[10])
{
    task task1;
    int id = find_id(file[0]);
    printf("%d\n", id);
    fseek(file[0], 0, SEEK_END);

    setlocale(LC_ALL, "Russian");
    printf("'*' помечены обязательные пункты\n");
    printf("Введите название дела*: ");
    fgetc(stdin);
    fgets(task1.name, 50, stdin);
    for(int i = 0; i < 50; i++)
        if(task1.name[i] == 10)
            task1.name[i] = 0;
    printf("Введите описание дела: ");
    fgets(task1.description, 100, stdin);
    for(int i = 0; i < 100; i++)
        if(task1.description[i] == 10)
            task1.description[i] = 0;
    printf("Введите статус выполнения('-' не начал, '~' в процессе)*: ");
    scanf("%c", &task1.status);
    printf("Введите крайний срок(через пробел: день месяц год, 0 - если бессрочное): ");
    scanf("%d", &task1.day);
    if(task1.day == 0)
    {
        task1.month = 0;
        task1.year = 0;
    } else
        scanf("%d %d", &task1.month, &task1.year);
    printf("Введите приоритет дела(* - низкий, ** - средний, *** - высокий)*: ");
    scanf("%s", task1.priority);
    printf("Введите категорию дела: ");
    fgetc(stdin);
    fgets(task1.category, 25, stdin);
    for(int i = 0; i < 25; i++)
        if(task1.category[i] == 10)
            task1.category[i] = 0;
    if(task1.status != 45)
    {
        printf("Введите прогресс выполнения: ");
        scanf("%d", &task1.progress);
    }
    else
        task1.progress = 0;

    fprintf(file[0], "%d|", id++);
    fprintf(file[0], "%s|", task1.name);
    fprintf(file[0], "%s|", task1.description);
    fprintf(file[0], "%d|", task1.status);
    fprintf(file[0], "%d|", task1.day);
    fprintf(file[0], "%d|", task1.month);
    fprintf(file[0], "%d|", task1.year);
    fprintf(file[0], "%s|", task1.priority);
    fprintf(file[0], "%s|", task1.category);
    fprintf(file[0], "%d|\n", task1.progress);
}

// void read_tasks(FILE *file[10])
// {
//     int id = find_id(file[0]) - 1;
//     task *tasks = NULL;
    
//     tasks = malloc(sizeof(task) * id);
// }