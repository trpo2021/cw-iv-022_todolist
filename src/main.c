#include "main_menu.h"
#include "todo_list.h"

int main()
{
    int number, i;
    FILE* file[10]
            = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    file[0] = fopen("users/user1.txt", "r+");
    file[1] = fopen("users/user1bin.txt", "r+");
    file[2] = fopen("users/user1archive.txt", "r+");
    if (file[0] == NULL)
        file[0] = fopen("users/user1.txt", "w+");
    if (file[1] == NULL)
        file[1] = fopen("users/user1bin.txt", "w+");
    if (file[2] == NULL)
        file[2] = fopen("users/user1archive.txt", "w+");
    do {
        printf("1. Todo list\n");
        printf("2. Archive\n");
        printf("3. Bin\n");
        printf("4. Autors\n");
        printf("5. Save and exit\n");
        scanf("%d", &number);
        switch (number) {
        case 1:
            todolist(file);
            break;
        case 2:
            archive(file);
            break;
        case 3:
            bin(file);
            break;
        case 4:
            authors();
            break;
        case 5:
            for (i = 0; i < 10; i++) {
                if ((file[i] != NULL) && (file[i] != 0))
                    fclose(file[i]);
            }
            break;
        }
    } while (number != 5);

    return 0;
}
