#include "todo_list.h"
#include "main_menu.h"

void add(FILE* file[10])
{
    task task1;
    int id = find_id(file[0]);
    fseek(file[0], 0, SEEK_END);
    setlocale(LC_ALL, "Russian");

    printf("'*' помечены обязательные пункты\n");
    name_edit(&task1);

    description_edit(&task1);

    status_edit(&task1);

    deadline_edit(&task1);

    priority_edit(&task1);

    category_edit(&task1);

    progress_edit(&task1);

    write_in_file(file[0], &task1, id);
}

void write_in_file(FILE* file, task* task1, int id)
{
    char progress_bar[11] = "__________";
    int progress_counter = 0;
    int progress = task1->progress;
    while (progress > 0) {
        progress -= 10;
        progress_counter++;
    }

    for (int i = 0; i < progress_counter; ++i) {
        progress_bar[i] = '*';
    }
    fprintf(file, "%2d|", id++);
    fprintf(file, "%-30s|", task1->name);
    fprintf(file, "%-80s|", task1->description);
    fprintf(file, "  %-c  |", task1->status);
    if (task1->day == 0)
        fprintf(file, "----------|");
    else
        fprintf(file, "%2d.%2d.%4d|", task1->day, task1->month, task1->year);
    fprintf(file, "   %-3s   |", task1->priority);
    fprintf(file, "%-20s|", task1->category);
    fprintf(file, "%-s (%d%%)|\n", progress_bar, task1->progress);
}

void read_tasks(FILE* file)
{
    char string[250];

    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        if (fgets(string, 250, file) != NULL)
            printf("%s", string);
    }
}

int find_id(FILE* file) // Поиск id для нового дела
{
    char string[250];
    int id = 0;

    fseek(file, 0, SEEK_SET);
    while (feof(file) == 0) {
        fgets(string, 250, file);
        id++;
    }
    return id;
}

void name_edit(task* task1)
{
    int count = 0;
    printf("Введите название дела*: ");
    fgetc(stdin);
    fgets(task1->name, 30, stdin);

    for (int i = 0; i < 30; i++) {
        if (task1->name[i] == 10)
            task1->name[i] = 32;
        if (task1->name[i] == 32)
            count++;
    }
    if (count == 0)
        while (getchar() != '\n')
            ;
}

void description_edit(task* task1)
{
    int count = 0;
    printf("Введите описание дела: ");
    fgets(task1->description, 80, stdin);
    for (int i = 0; i < 80; i++) {
        if (task1->description[i] == 10)
            task1->description[i] = 32;
        if (task1->description[i] == 32)
            count++;
    }
    if (count == 0)
        while (getchar() != '\n')
            ;
}

void status_edit(task* task1)
{
    printf("Введите статус выполнения('-' не начал, '~' в процессе)*: ");
    task1->status = getchar();
    while ((task1->status != '~') && (task1->status != '-'))
    {
        while (getchar() != '\n');
        printf("Введите корректный статус: ");
        task1->status = getchar();
    }
    while (getchar() != '\n')
        ;
}

void deadline_edit(task* task1)
{
    printf("Введите крайний срок(через пробел: день месяц год, 0 - если "
           "бессрочное): ");
    scanf("%d", &task1->day);
    while (day_check(task1->day) == -1) {
        printf("Введите корректную дату(день): ");
        printf("%d\n", task1->day);
        scanf("%d", &task1->day);
    }
    if (task1->day == 0) {
        task1->month = 0;
        task1->year = 0;
    } else {
        printf("Введите месяц: ");
        scanf("%d", &task1->month);
        while (month_check(task1->month) == -1) {
            printf("Введите корректную дату(месяц): ");
            scanf("%d", &task1->month);
        }
        printf("Введите год: ");
        scanf("%d", &task1->year);
        while (year_check(task1->year) == -1) {
            printf("Введите корректную дату(год): ");
            scanf("%d", &task1->year);
        }
    }
}

void priority_edit(task* task1)
{
    int i, count = 0;
    printf("Введите приоритет дела(* - низкий, ** - средний, *** - "
           "высокий)*: ");
    fgetc(stdin);
    fgets(task1->priority, 4, stdin);
    task1->priority[3] = '\0';
    for(i = 0; i < 3; i++)
    {
        if(task1->priority[i] == '\n')
            task1->priority[i] = ' ';
        if(task1->priority[i] == 0)
            task1->priority[i] = ' ';
    }
    while (((task1->priority[0] != '*') && (task1->priority[0] != ' '))
        || ((task1->priority[1] != '*') && (task1->priority[1] != ' '))
        || ((task1->priority[2] != '*') && (task1->priority[2] != ' ')))
    {
        printf("Введите корректный приоритет: ");
        count = 0;
        for (i = 0; i < 3; i++) {
            if (task1->priority[i] == 10)
                task1->priority[i] = 32;
            if (task1->priority[i] == 32)
                count++;
        }
        if (count == 0)
            while (getchar() != '\n');
        fgets(task1->priority, 4, stdin);
        for (i = 0; i < 4; i++) {
            if(task1->priority[i] == '\n')
                task1->priority[i] = ' ';
            if(task1->priority[i] == 0)
                task1->priority[i] = ' ';
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++) {
    if (task1->priority[i] == 10)
        task1->priority[i] = 32;
    if (task1->priority[i] == 32)
        count++;
    }
    if (count == 0)
    while (getchar() != '\n')
        ;
    task1->priority[3] = '\0';
}

void category_edit(task* task1)
{
    int count = 0;
    printf("Введите категорию дела: ");
    fgets(task1->category, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (task1->category[i] == 10)
            task1->category[i] = 32;
        if (task1->category[i] == 32)
            count++;
    }
    if (count == 0)
        while (getchar() != '\n')
            ;
}

void progress_edit(task* task1)
{
    if (task1->status != 45) {
        printf("Введите прогресс выполнения(в процентах): ");
        scanf("%d", &task1->progress);
        while (task1->progress > 100) {
            printf("Введите корректный прогресс выполнения(в процентах): ");
            scanf("%d", &task1->progress);
        }
    } else
        task1->progress = 0;
}

void replacement(FILE* file, task* task1, int id)
{
    char string[250];
    int i = 0;

    fseek(file, 0, SEEK_SET);
    if (id > 1)
        for (i = 0; i < id - 1; i++)
            fgets(string, 250, file);

    write_in_file(file, task1, id);
}

void task_scan(FILE* file, task* task1, int id)
{
    setlocale(LC_ALL, "Russian");
    char c = 0, v = 0, b = 0;
    char string[250];
    int i = 0, j = 0;

    fseek(file, 0, SEEK_SET);
    if (id > 1)
        for (i = 0; i < id - 1; i++)
            fgets(string, 250, file);

    task1->id = 0;

    c = fgetc(file);
    if (c != 32)
        task1->id = (c - 48) * 10;
    c = fgetc(file);
    task1->id += (c - 48);

    for (i = 0; i < 29; i++)
        task1->name[i] = 32;

    fseek(file, 1, SEEK_CUR);
    j = 0;
    c = fgetc(file);
    while (c != 124) {
        task1->name[j] = c;
        j++;
        c = fgetc(file);
    }

    task1->name[29] = '\0';

    for (i = 0; i < 79; i++)
        task1->description[i] = 32;

    c = fgetc(file);
    j = 0;
    while (c != 124) {
        task1->description[j] = c;
        j++;
        c = fgetc(file);
    }
    task1->description[79] = '\0';

    fseek(file, 2, SEEK_CUR);
    c = fgetc(file);
    task1->status = c;

    fseek(file, 3, SEEK_CUR);
    task1->day = 0;
    task1->month = 0;
    task1->year = 0;
    c = fgetc(file);
    if (c != 45) {
        if (c != 32)
            task1->day = (c - 48) * 10;
        c = fgetc(file);
        task1->day += (c - 48);
        c = fgetc(file);
        c = fgetc(file);
        if (c != 32)
            task1->month = (c - 48) * 10;
        c = fgetc(file);
        task1->month += (c - 48);
        c = fgetc(file);
        c = fgetc(file);
        task1->year += (c - 48) * 1000;
        c = fgetc(file);
        task1->year += (c - 48) * 100;
        c = fgetc(file);
        task1->year += (c - 48) * 10;
        c = fgetc(file);
        task1->year += (c - 48);
        fseek(file, 4, SEEK_CUR);
    } else {
        fseek(file, 13, SEEK_CUR);
        task1->month = 0;
        task1->day = 0;
        task1->year = 0;
    }

    c = fgetc(file);
    task1->priority[0] = c;
    c = fgetc(file);
    task1->priority[1] = c;
    if (task1->priority[1] != 42)
        task1->priority[1] = 32;
    c = fgetc(file);
    task1->priority[2] = c;
    if (task1->priority[2] != 42)
        task1->priority[2] = 32;
    task1->priority[3] = '\0';

    fseek(file, 4, SEEK_CUR);

    c = fgetc(file);
    j = 0;
    while (c != 124) {
        task1->category[j] = c;
        j++;
        c = fgetc(file);
    }
    task1->category[19] = '\0';

    fseek(file, 12, SEEK_CUR);

    c = fgetc(file);
    v = fgetc(file);
    b = fgetc(file);

    task1->progress = 0;

    if (c == 48)
        task1->progress = 0;
    else if (b == 37)
        task1->progress = (c - 48) * 10 + (v - 48);
    else
        task1->progress = ((c - 48) * 100) + ((v - 48) * 10) + (b - 48);
}

void edit(FILE* file, int id)
{
    task task1;

    task_scan(file, &task1, id);

    int number;
    do {
        printf("1. Изменить название\n");
        printf("2. Изменить описание\n");
        printf("3. Изменить статус выполнения\n");
        printf("4. Изменить крайний срок\n");
        printf("5. Изменить приоритет\n");
        printf("6. Изменить категорию\n");
        printf("7. Изменить прогресс\n");
        printf("8. Выход в главное меню\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            getchar();
            name_edit(&task1);
            break;
        case 2:
            getchar();
            description_edit(&task1);
            break;
        case 3:
            getchar();
            status_edit(&task1);
            break;
        case 4:
            getchar();
            deadline_edit(&task1);
            break;
        case 5:
            priority_edit(&task1);
            break;
        case 6:
            getchar();
            category_edit(&task1);
            break;
        case 7:
            getchar();
            progress_edit(&task1);
            break;
        case 8:
            break;
        }
    } while (number != 8);
    replacement(file, &task1, id);
}

void move_to_bin(FILE* file[10], int id)
{
    const int number = find_id(file[0]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[0], &tasks[i], (i + 1));

    int bin_id = find_id(file[1]);
    write_in_file(file[1], &tasks[id - 1], bin_id);

    file[0] = fopen("users/user1.txt", "w+");

    for (int i = 0; i < number; i++) {
        bin_id = find_id(file[0]);
        if (i != (id - 1))
            write_in_file(file[0], &tasks[i], bin_id);
    }
}

void move_to_archive(FILE* file[10], int id)
{
    const int number = find_id(file[0]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[0], &tasks[i], (i + 1));

    int archive_id = find_id(file[2]);
    write_in_file(file[2], &tasks[id - 1], archive_id);

    file[0] = fopen("users/user1.txt", "w+");

    for (int i = 0; i < number; i++) {
        archive_id = find_id(file[0]);
        if (i != (id - 1))
            write_in_file(file[0], &tasks[i], archive_id);
    }
}

void duplication(FILE* file[10], int id)
{
    const int number = find_id(file[0]) - 1;
    task tasks[number];

    for (int i = 0; i < number; i++)
        task_scan(file[0], &tasks[i], (i + 1));

    int duplication_id = find_id(file[0]);
    write_in_file(file[0], &tasks[id - 1], duplication_id);
}

int day_check(int day)
{
    if (day == 0)
        return 2;
    if (day > 0 && day < 32)
        return 1;
    return -1;
}

int month_check(int month)
{
    if (month > 0 && month < 13)
        return 1;
    return -1;
}

int year_check(int year)
{
    if (year > 1000 && year < 3000)
        return 1;
    return -1;
}

void swap(task* task1, task* task2)
{
    char temp_string[250] = " ";
    char temp_char = ' ';
    unsigned int temp = 0;
    strcpy(temp_string, task1->name);
    strcpy(task1->name, task2->name);
    strcpy(task2->name, temp_string);
    memset(temp_string, '\0', strlen(temp_string));
    strcpy(temp_string, task1->description);
    strcpy(task1->description, task2->description);
    strcpy(task2->description, temp_string);
    memset(temp_string, '\0', strlen(temp_string));
    temp_char = task1->status;
    task1->status = task2->status;
    task2->status = temp_char;
    temp_char = ' ';
    temp = task1->day;
    task1->day = task2->day;
    task2->day = temp;
    temp = 0;
    temp = task1->month;
    task1->month = task2->month;
    task2->month = temp;
    temp = 0;
    temp = task1->year;
    task1->year = task2->year;
    task2->year = temp;
    temp = 0;
    strcpy(temp_string, task1->priority);
    strcpy(task1->priority, task2->priority);
    strcpy(task2->priority, temp_string);
    memset(temp_string, '\0', strlen(temp_string));
    strcpy(temp_string, task1->category);
    strcpy(task1->category, task2->category);
    strcpy(task2->category, temp_string);
    memset(temp_string, '\0', strlen(temp_string));
    temp = task1->progress;
    task1->progress = task2->progress;
    task2->progress = temp;
    temp = 0;
}

void sort_name(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (strcmp(tasks[i].name, tasks[j].name) > 0) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_description(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (strcmp(tasks[i].description, tasks[j].description) > 0) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_status(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (tasks[i].status > tasks[j].status) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_deadline(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (tasks[i].year > tasks[j].year) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            } else if (
                    (tasks[i].year == tasks[j].year)
                    && (tasks[i].month > tasks[j].month)) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            } else if (
                    (tasks[i].year == tasks[j].year)
                    && (tasks[i].month == tasks[j].month)
                    && (tasks[i].day > tasks[j].day)) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_priority(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (strcmp(tasks[i].priority, tasks[j].priority) > 0) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_category(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (strcmp(tasks[i].category, tasks[j].category) > 0) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort_progress(FILE* file, int id)
{
    const int number = find_id(file) - 1;
    task tasks[number];
    for (int i = 0; i < number; i++)
        task_scan(file, &tasks[i], (i + 1));

    for (int i = 0; i < (number - 1); i++) {
        for (int j = (number - 1); j > i; j--) {
            if (tasks[i].progress > tasks[j].progress) {
                swap(&tasks[i], &tasks[j]);
                file = fopen("users/user1.txt", "w+");
                for (int i = 0; i < number; i++) {
                    int sort_id = find_id(file);
                    write_in_file(file, &tasks[i], sort_id);
                }
            }
        }
    }
    fclose(file);
}

void sort(FILE* file, int id)
{
    int number;
    do {
        fclose(file);
        file = fopen("users/user1.txt", "r+");
        read_tasks(file);
        printf("1. Отсортировать по названию\n");
        printf("2. Отсортировать по описанию\n");
        printf("3. Отсортировать по статусу\n");
        printf("4. Отсортировать по крайнему сроку\n");
        printf("5. Отсортировать по приоритету\n");
        printf("6. Отсортировать по категории\n");
        printf("7. Отсортировать по прогрессу\n");
        printf("8. Выход в главное меню\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            sort_name(file, id);
            break;
        case 2:
            sort_description(file, id);
            break;
        case 3:
            sort_status(file, id);
            break;
        case 4:
            sort_deadline(file, id);
            break;
        case 5:
            sort_priority(file, id);
            break;
        case 6:
            sort_category(file, id);
            break;
        case 7:
            sort_progress(file, id);
            break;
        case 8:
            break;
        }
    } while (number != 8);
}
