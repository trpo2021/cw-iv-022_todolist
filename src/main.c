#include "main_menu.h"

int main()
{
    int number, i;
    

    FILE* file[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    file[0] = fopen("users/user1.txt", "r+");
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