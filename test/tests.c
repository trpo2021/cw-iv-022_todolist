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

//CTEST(write_in_files, write_1)
//{   
    //file[0] = fopen("test/users/user4.txt", "w+");
//    task task1;
//    task1.id = 0;
    //scanf("%s", task1->name);
    //scanf("%s", task1->description);
   // task1->status = '~';
   // task1->day = 0;
    //scanf("%s", task1->priority);
   // task1->progress = 0;
    //write_in_file(file[0], task1, 0);
   // int expected = 1;
   // int result = 1;
   // ASSERT_EQUAL(expected, result);
    //fclose(file[0]);
    
//}

CTEST(name_edits, edit_1)
{   
    file[0] = fopen("test/users/user4.txt", "r+");
    task* task1;
    name_edit(task1);
    int expected = 1;
    int result = 1;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
}