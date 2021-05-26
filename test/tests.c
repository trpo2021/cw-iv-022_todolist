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

CTEST(year_checks, ycheck_1)
{   
    int year = 2020;
    int result = year_check(year);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_2)
{   
    int year = 1000;
    int result = year_check(year);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_3)
{   
    int year = 1001;
    int result = year_check(year);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_4)
{   
    int year = 3000;
    int result = year_check(year);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_5)
{   
    int year = 2999;
    int result = year_check(year);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_6)
{   
    int year = 'y';
    int result = year_check(year);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(year_checks, ycheck_7)
{   
    int year = -2020;
    int result = year_check(year);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(move_to_archive_checks, mtacheck_1)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].day;
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int archive = tasks[1].day;
    ASSERT_EQUAL(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_2)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].month;
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int archive = tasks[1].month;
    ASSERT_EQUAL(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_3)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].year;
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int archive = tasks[1].year;
    ASSERT_EQUAL(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_4)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].progress;
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int archive = tasks[1].progress;
    ASSERT_EQUAL(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_5)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[30];
    strcpy(user, tasks[1].name);
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive[30];
    strcpy(archive, tasks[1].name);
    ASSERT_STR(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_6)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[80];
    strcpy(user, tasks[1].description);
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive[80];
    strcpy(archive, tasks[1].description);
    ASSERT_STR(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_8)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[20];
    strcpy(user, tasks[1].category);
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive[20];
    strcpy(archive, tasks[1].category);
    ASSERT_STR(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_9)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[20];
    strcpy(user, tasks[1].category);
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive[20];
    strcpy(archive, tasks[1].category);
    ASSERT_STR(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_10)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[4];
    strcpy(user, tasks[1].priority);
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive[4];
    strcpy(archive, tasks[1].priority);
    ASSERT_STR(user, archive);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(move_to_archive_checks, mtacheck_11)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[2] = fopen("test/users/user1archive.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user = tasks[1].status;
    move_to_archive(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    char archive = tasks[1].status;
    int expected = 1;
    int result = -1;
    if (user == archive)
        result = 1;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
    fclose(file[2]);
}


CTEST(move_to_bin_checks, mtbcheck_1)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].day;
    move_to_bin(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int bin = tasks[1].day;
    ASSERT_EQUAL(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_2)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].month;
    move_to_bin(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int bin = tasks[1].month;
    ASSERT_EQUAL(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_3)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].year;
    move_to_bin(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int bin = tasks[1].year;
    ASSERT_EQUAL(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_4)
{   
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int user = tasks[1].progress;
    move_to_bin(file, 1);
    task_scan(file[2], &tasks[1], find_id(file[2]) - 1);
    int bin = tasks[1].progress;
    ASSERT_EQUAL(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}