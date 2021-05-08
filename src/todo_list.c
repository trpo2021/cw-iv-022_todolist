#include "main_menu.h"
#include "todo_list.h"

void add(FILE *file[10])
{
    task task1;
    int id = find_id(file[0]);
    fseek(file[0], 0, SEEK_END);

    // indent();
    setlocale(LC_ALL, "Russian");
    printf("'*' помечены обязательные пункты\n");
    printf("Введите название дела*: ");
    fgetc(stdin);
    fgets(task1.name, 30, stdin);
    for(int i = 0; i < 30; i++)
        if(task1.name[i] == 10)
            task1.name[i] = 0;
    printf("Введите описание дела: ");
    fgets(task1.description, 80, stdin);
    for(int i = 0; i < 80; i++)
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
    fgets(task1.category, 20, stdin);
    for(int i = 0; i < 20; i++)
        if(task1.category[i] == 10)
            task1.category[i] = 0;
    if(task1.status != 45)
    {
        printf("Введите прогресс выполнения: ");
        scanf("%d", &task1.progress);
    }
    else
        task1.progress = 0;

    char progress_bar[11] = "__________";
    int progress_counter = 0;
    int progress = task1.progress;
    while(progress > 0)
    {
        progress -= 10;
        progress_counter++;
    }

    for (int i = 0; i < progress_counter; ++i)
    {
        progress_bar[i] = '*';
    }

    fprintf(file[0], "%2d|", id++);
    fprintf(file[0], "%-30s|", task1.name);
    fprintf(file[0], "%-80s|", task1.description);
    fprintf(file[0], "  %-c  |", task1.status);
    if(task1.day == 0)
    	fprintf(file[0], "----------|");
    else
    	fprintf(file[0], "%2d.%2d.%4d|", task1.day, task1.month, task1.year);
    fprintf(file[0], "   %-3s   |", task1.priority);
    fprintf(file[0], "%-20s|", task1.category);
    fprintf(file[0], "%-s (%d%%)|\n", progress_bar, task1.progress);
}

void read_tasks(FILE *file)
{
    char string[250];

    fseek(file, 0, SEEK_SET);
    while(!feof(file))
    {
        if(fgets(string, 250, file) != NULL)
            printf("%s", string);
    }
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

void indent()
{
    for(int i = 0; i < 20; i++)
        printf("\n");
}

void name_edit(task *task1)
{
	printf("Введите название дела*: ");
	fgetc(stdin);
	fgets(task1->name, 30, stdin);
	for(int i = 0; i < 30; i++)
		if(task1->name[i] == 10)
			task1->name[i] = 0;
}

void description_edit(task *task1)
{
	printf("Введите описание дела*: ");
	fgetc(stdin);
	fgets(task1->description, 80, stdin);
	for(int i = 0; i < 80; i++)
		if(task1->description[i] == 10)
			task1->description[i] = 0;
}

void status_edit(task *task1)
{
	printf("Введите статус выполнения('-' не начал, '~' в процессе)*: ");
	fgetc(stdin);
	scanf("%c", &task1->status);
}

void deadline_edit(task *task1)
{
	printf("Введите крайний срок(через пробел: день месяц год, 0 - если бессрочное): ");
	fgetc(stdin);
	scanf("%d", &task1->day);
	if(task1->day == 0)
	{
		task1->month = 0;
		task1->year = 0;
	} else
		scanf("%d %d", &task1->month, &task1->year);
}

void priority_edit(task *task1)
{
	printf("Введите приоритет дела(* - низкий, ** - средний, *** - высокий)*: ");
	fgetc(stdin);
	scanf("%s", task1->priority);
}

void category_edit(task *task1)
{
	printf("Введите категорию дела: ");
	fgetc(stdin);
	fgets(task1->category, 20, stdin);
	for(int i = 0; i < 20; i++)
		if(task1->category[i] == 10)
			task1->category[i] = 0;	
}

void progress_edit(task *task1)
{
	if(task1->status != 45)
	{
		printf("Введите прогресс выполнения: ");
		fgetc(stdin);
		scanf("%d", &task1->progress);
	}
	else
		task1->progress = 0;
}

void replacement(FILE *file, task *task1, int id)
{
	char string[250];
	int i = 0;
	
	fseek(file, 0, SEEK_SET);
	if(id > 1)
		for (i = 0; i < id - 1; i++)
			fgets(string, 250, file);
	char progress_bar[11] = "__________";
	int progress_counter = 0;
	int progress = task1->progress;
	while(progress > 0)
	{
		progress -= 10;
		progress_counter++;
	}

	for (int i = 0; i < progress_counter; ++i)
	{
		progress_bar[i] = '*';
	}
	fprintf(file, "%2d|", id++);
	fprintf(file, "%-30s|", task1->name);
	fprintf(file, "%-80s|", task1->description);
	fprintf(file, "  %-c  |", task1->status);
	if(task1->day == 0)
		fprintf(file, "----------|");
	else
		fprintf(file, "%2d.%2d.%4d|", task1->day, task1->month, task1->year);
	fprintf(file, "   %3s   |", task1->priority);
	fprintf(file, "%-20s|", task1->category);
	fprintf(file, "%-s (%d%%)|\n", progress_bar, task1->progress);
}

void edit(FILE *file, int id)
{
    setlocale(LC_ALL, "Russian");
    task task1;
    char c = 0, v = 0, b = 0;
    char string[250];
    int i = 0, j = 0;

    fseek(file, 0, SEEK_SET);
    if(id > 1)
        for (i = 0; i < id - 1; i++)
            fgets(string, 250, file);

    task1.id = 0;
    
    c = fgetc(file);
    if(c != 32)
        task1.id = (c - 48) * 10;
    c = fgetc(file);
    task1.id += (c - 48);

    for(i = 0; i < 29; i++)
        task1.name[i] = 32;
    
    fseek(file, 1, SEEK_CUR);
    j = 0;
    c = fgetc(file);
    while(c != 124)
    {
        task1.name[j] = c;
        j++;
        c = fgetc(file);
    } 

    task1.name[29] = '\0';

    for(i = 0; i < 79; i++)
        task1.description[i] = 32;
    
    c = fgetc(file);
    j = 0;
    while(c != 124)
    {
        task1.description[j] = c;
        j++;
        c = fgetc(file);
    } 
    task1.description[79] = '\0';
    
    fseek(file, 2, SEEK_CUR);
    c = fgetc(file);
    task1.status = c;

    fseek(file, 3, SEEK_CUR);
    task1.day = 0;
    task1.month = 0;
    task1.year = 0;
    c = fgetc(file);
    if(c != 45)
    {
        if(c != 32)
            task1.day = (c - 48) * 10;
        c = fgetc(file);
        task1.day += (c - 48);
        c = fgetc(file);
        c = fgetc(file);
        if(c != 32)
            task1.month = (c - 48) * 10;
        c = fgetc(file);
        task1.month += (c - 48);
        c = fgetc(file);
        c = fgetc(file);
        task1.year += (c - 48) * 1000;
        c = fgetc(file);
        task1.year += (c - 48) * 100;
        c = fgetc(file);
        task1.year += (c - 48) * 10;
        c = fgetc(file);
        task1.year += (c - 48);
    	fseek(file, 4, SEEK_CUR);
    }
    else
    {
    	fseek(file, 13, SEEK_CUR);
    	task1.month = 0;
    	task1.day = 0;
    	task1.year = 0;
    }


    c = fgetc(file);
    task1.priority[0] = c;
    c = fgetc(file);
    task1.priority[1] = c;
    if (task1.priority[1] != 42)
    	task1.priority[1] = 32; 
    c = fgetc(file);
    task1.priority[2] = c;
    if (task1.priority[2] != 42)
    	task1.priority[2] = 32; 
    task1.priority[3] = '\0';

    fseek(file, 4, SEEK_CUR);
    
    c = fgetc(file);
    j = 0;
    while(c != 124)
    {
        task1.category[j] = c;
        j++;
        c = fgetc(file);
    } 
    task1.category[19] = '\0';

    fseek(file, 12, SEEK_CUR);

    c = fgetc(file);
    v = fgetc(file);
    b = fgetc(file);

    task1.progress = 0;

    if(c == 48)
        task1.progress = 0;
    else if(b == 37)
        task1.progress = (c - 48) * 10 + (v - 48);
    else
        task1.progress = ((c - 48) * 100) + ((v - 48) * 10) + (b - 48);
    
    int number;
    do
    {
    	printf("1. Изменить название\n");
    	printf("2. Изменить описание\n");
    	printf("3. Изменить статус выполнения\n");
    	printf("4. Изменить крайний срок\n");
    	printf("5. Изменить приоритет\n");
    	printf("6. Изменить категорию\n");
    	printf("7. Изменить прогресс\n");
    	printf("8. Выход в главное меню\n");
    	scanf("%d", &number);
    	switch(number)
    	{
		case 1:
			name_edit(&task1);
			break;
		case 2:
			description_edit(&task1);
			break;
		case 3:
			status_edit(&task1);
			break;
		case 4:
			deadline_edit(&task1);
			break;
		case 5:
			priority_edit(&task1);
			break;
		case 6:
			category_edit(&task1);
			break;
		case 7:
			progress_edit(&task1);
			break;
		case 8:
			break;
        }
    } while (number != 8);
    replacement(file, &task1, id);

}
