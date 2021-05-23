#include "ctest.h"
#include <todo_list.h>

FILE* file[10]
            = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

CTEST(find_ids, id_1)
{   
    file[0] = fopen("test/users/user1.txt", "r+");
    int result = find_id(file[0]);
    int expected = 2;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
}

CTEST(find_ids, id_2)
{   
    file[0] = fopen("test/users/user2.txt", "r+");
    int result = find_id(file[0]);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
}

CTEST(find_ids, id_3)
{   
    file[0] = fopen("test/users/user3.txt", "r+");
    int result = find_id(file[0]);
    int expected = 10001;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
}
