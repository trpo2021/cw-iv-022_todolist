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

CTEST(day_checks, dcheck_1)
{   
    int day = 1;
    int result = day_check(day);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_2)
{   
    int day = 01;
    int result = day_check(day);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_3)
{   
    int day = -1;
    int result = day_check(day);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_4)
{   
    int day = 'a';
    int result = day_check(day);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_5)
{   
    int day = 32;
    int result = day_check(day);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_6)
{   
    int day = 0;
    int result = day_check(day);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_7)
{   
    int day = 50;
    int result = day_check(day);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(day_checks, dcheck_8)
{   
    int day = 31;
    int result = day_check(day);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_1)
{   
    int month = 1;
    int result = month_check(month);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_2)
{   
    int month = 0;
    int result = month_check(month);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_3)
{   
    int month = -1;
    int result = month_check(month);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_4)
{   
    int month = 12;
    int result = month_check(month);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_5)
{   
    int month = 13;
    int result = month_check(month);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_6)
{   
    int month = 'a';
    int result = month_check(month);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(month_checks, mcheck_7)
{   
    int month = 6;
    int result = month_check(month);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}