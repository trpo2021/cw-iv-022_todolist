#include "ctest.h"
#include <archive.h>
#include <bin.h>
#include <todo_list.h>

FILE* file[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

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
    int expected = 100;
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
    int expected = 2;
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

CTEST(move_to_archive_checks, mtacheck_7)
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

CTEST(move_to_archive_checks, mtacheck_8)
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

CTEST(move_to_archive_checks, mtacheck_9)
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
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
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
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
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
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
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
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    int bin = tasks[1].progress;
    ASSERT_EQUAL(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_5)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[30];
    strcpy(user, tasks[1].name);
    move_to_bin(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    char bin[30];
    strcpy(bin, tasks[1].name);
    ASSERT_STR(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_6)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[80];
    strcpy(user, tasks[1].description);
    move_to_bin(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    char bin[80];
    strcpy(bin, tasks[1].description);
    ASSERT_STR(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_7)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[20];
    strcpy(user, tasks[1].category);
    move_to_bin(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    char bin[20];
    strcpy(bin, tasks[1].category);
    ASSERT_STR(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_8)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user[4];
    strcpy(user, tasks[1].priority);
    move_to_bin(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    char bin[20];
    strcpy(bin, tasks[1].priority);
    ASSERT_STR(user, bin);
    fclose(file[0]);
    fclose(file[1]);
}

CTEST(move_to_bin_checks, mtbcheck_9)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    file[1] = fopen("test/users/user1bin.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char user = tasks[1].status;
    move_to_bin(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[1]) - 1);
    char bin = tasks[1].status;
    int expected = 1;
    int result = -1;
    if (user == bin)
        result = 1;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
    fclose(file[2]);
}

CTEST(duplication_checks, duplcheck_1)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int original = tasks[1].day;
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    int duplicated = tasks[1].day;
    ASSERT_EQUAL(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_2)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int original = tasks[1].month;
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    int duplicated = tasks[1].month;
    ASSERT_EQUAL(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_3)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int original = tasks[1].year;
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    int duplicated = tasks[1].year;
    ASSERT_EQUAL(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_4)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    int original = tasks[1].progress;
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    int duplicated = tasks[1].progress;
    ASSERT_EQUAL(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_5)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char original[30];
    strcpy(original, tasks[1].name);
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    char duplicated[30];
    strcpy(duplicated, tasks[1].name);
    ASSERT_STR(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_6)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char original[80];
    strcpy(original, tasks[1].description);
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    char duplicated[80];
    strcpy(duplicated, tasks[1].description);
    ASSERT_STR(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_7)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char original[20];
    strcpy(original, tasks[1].category);
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    char duplicated[20];
    strcpy(duplicated, tasks[1].category);
    ASSERT_STR(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_8)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char original[4];
    strcpy(original, tasks[1].priority);
    duplication(file, 1);
    task_scan(file[1], &tasks[1], find_id(file[0]) - 1);
    char duplicated[4];
    strcpy(duplicated, tasks[1].priority);
    ASSERT_STR(original, duplicated);
    fclose(file[0]);
}

CTEST(duplication_checks, duplcheck_9)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");
    task_scan(file[0], &tasks[1], 1);
    char original = tasks[1].status;
    duplication(file, 1);
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    char duplicated = tasks[1].status;
    int expected = 1;
    int result = -1;
    if (original == duplicated)
        result = 1;
    ASSERT_EQUAL(expected, result);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_1)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    char expected[30];
    strcpy(expected, tasks[1].name);
    for (int i = 4; i < 29; ++i)
        expected[i] = ' ';
    expected[29] = '\0';
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_STR(tasks[1].name, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_2)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    char expected[80];
    strcpy(expected, tasks[1].description);
    for (int i = 11; i < 79; ++i)
        expected[i] = ' ';
    expected[79] = '\0';
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_STR(tasks[1].description, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_3)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    char expected[20];
    strcpy(expected, tasks[1].category);
    for (int i = 8; i < 19; ++i)
        expected[i] = ' ';
    expected[19] = '\0';
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_STR(tasks[1].category, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_4)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    char expected[4];
    strcpy(expected, tasks[1].priority);
    expected[4] = '\0';
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_STR(tasks[1].priority, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_5)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    char read = '~';
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    int result = -1;
    int expected = 1;
    if (read == tasks[1].status)
        result = 1;
    ASSERT_EQUAL(result, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_6)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    int expected = 1;
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_EQUAL(tasks[1].day, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_7)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    int expected = 1;
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_EQUAL(tasks[1].month, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_8)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    int expected = 2020;
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_EQUAL(tasks[1].year, expected);
    fclose(file[0]);
}

CTEST(write_in_file_tests, write_check_9)
{
    task tasks[10];
    file[0] = fopen("test/users/user4.txt", "r+");

    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    int expected = 10;
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    task_scan(file[0], &tasks[1], find_id(file[0]) - 1);
    ASSERT_EQUAL(tasks[1].progress, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_1)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    char expected[30] = "Name";
    task_scan(file[0], &tasks[1], 1);
    tasks[1].name[4] = '\0';
    ASSERT_STR(tasks[1].name, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_2)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    char expected[20] = "Category";
    task_scan(file[0], &tasks[1], 1);
    tasks[1].category[8] = '\0';
    ASSERT_STR(tasks[1].category, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_3)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    char expected[80] = "Description";
    task_scan(file[0], &tasks[1], 1);
    tasks[1].description[11] = '\0';
    ASSERT_STR(tasks[1].description, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_4)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    char expected[4] = "***";
    task_scan(file[0], &tasks[1], 1);
    ASSERT_STR(tasks[1].priority, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_5)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    char status = '~';
    task_scan(file[0], &tasks[1], 1);
    int expected = 1;
    int result = -1;
    if (status == tasks[1].status)
        result = 1;
    ASSERT_EQUAL(result, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_6)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    int expected = 1;
    task_scan(file[0], &tasks[1], 1);
    ASSERT_EQUAL(tasks[1].day, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_7)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    int expected = 1;
    task_scan(file[0], &tasks[1], 1);
    ASSERT_EQUAL(tasks[1].month, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_8)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    int expected = 2020;
    task_scan(file[0], &tasks[1], 1);
    ASSERT_EQUAL(tasks[1].year, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_9)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    int expected = 10;
    task_scan(file[0], &tasks[1], 1);
    ASSERT_EQUAL(tasks[1].progress, expected);
    fclose(file[0]);
}

CTEST(task_scans, scan_check_10)
{
    task tasks[10];
    file[0] = fopen("test/users/user1.txt", "r+");
    int expected = 1;
    task_scan(file[0], &tasks[1], 1);
    ASSERT_EQUAL(tasks[1].id, expected);
    fclose(file[0]);
}

CTEST(cleans, clean_archive)
{
    clean_archive(file);
    int result = find_id(file[2]);
    int expected = 1;
    ASSERT_EQUAL(result, expected);
    fclose(file[2]);
}

CTEST(cleans, clean_bin)
{
    clean_bin(file);
    int result = find_id(file[1]);
    int expected = 1;
    ASSERT_EQUAL(result, expected);
    fclose(file[1]);
}

// CTEST(edits, name_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    name_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    char tmp[30];
//    strcpy(tmp, tasks[0].name);
//    task_scan(file[0], &tasks[0], 1);
//    for (int i = 0; i < 30; ++i)
//       if (tmp[i] == ' ')
//        tmp[i] = '\0';
//    for (int i = 0; i < 30; ++i)
//        if (tasks[0].name[i] == ' ')
//            tasks[0].name[i] = '\0';
//    ASSERT_STR(tasks[0].name, tmp);
//    fclose(file[0]);
//}

// CTEST(edits, description_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    description_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    char tmp[80];
//    strcpy(tmp, tasks[0].description);
//    task_scan(file[0], &tasks[0], 1);
//    for (int i = 0; i < 80; ++i)
//        if (tmp[i] == ' ')
//            tmp[i] = '\0';
//    for (int i = 0; i < 80; ++i)
//        if (tasks[0].description[i] == ' ')
//            tasks[0].description[i] = '\0';
//    ASSERT_STR(tasks[0].description, tmp);
//    fclose(file[0]);
//}

// CTEST(edits, category_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    category_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    char tmp[20];
//    strcpy(tmp, tasks[0].category);
//    task_scan(file[0], &tasks[0], 1);
//    for (int i = 0; i < 20; ++i)
//        if (tmp[i] == ' ')
//            tmp[i] = '\0';
//    for (int i = 0; i < 20; ++i)
//        if (tasks[0].category[i] == ' ')
//            tasks[0].category[i] = '\0';
//    ASSERT_STR(tasks[0].category, tmp);
//    fclose(file[0]);
//}

// CTEST(edits, priority_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    priority_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    char tmp[4];
//    strcpy(tmp, tasks[0].priority);
//    task_scan(file[0], &tasks[0], 1);
//    for (int i = 0; i < 4; ++i)
//        if (tmp[i] == ' ')
//            tmp[i] = '\0';
//    for (int i = 0; i < 4; ++i)
//        if (tasks[0].priority[i] == ' ')
//            tasks[0].priority[i] = '\0';
//    ASSERT_STR(tasks[0].priority, tmp);
//    fclose(file[0]);
//}

// CTEST(edits, status_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    status_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    char tmp = tasks[0].status;
//    task_scan(file[0], &tasks[0], 1);
//    int result = -1;
//    int expected = 1;
//    if (tasks[0].status == tmp)
//        result = 1;
//    ASSERT_EQUAL(expected, result);
//    fclose(file[0]);
//}

// CTEST(edits, deadline_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    deadline_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    int expected = 3;
//    int result = 0;
//    int tmp1 = tasks[0].day;
//    int tmp2 = tasks[0].month;
//    int tmp3 = tasks[0].year;
//    task_scan(file[0], &tasks[0], 1);
//    if (tasks[0].day == tmp1)
//    result++;
//    if (tasks[0].month == tmp2)
//        result++;
//    if (tasks[0].year == tmp3)
//        result++;
//    ASSERT_EQUAL(expected, result);
//    fclose(file[0]);
//}

// CTEST(edits, progress_edit)
//{
//    task tasks[10];
//    file[0] = fopen("test/users/test.txt", "w+");
//    strcpy(tasks[0].name, "Name");
//    strcpy(tasks[0].description, "Description");
//    strcpy(tasks[0].category, "Category");
//    strcpy(tasks[0].priority, "***");
//    tasks[0].status = '~';
//    tasks[0].day = 1;
//    tasks[0].month = 1;
//    tasks[0].year = 2020;
//    tasks[0].progress = 10;
//    progress_edit(&tasks[0]);
//    write_in_file(file[0], &tasks[0], 1);
//    int expected = tasks[0].progress;
//    task_scan(file[0], &tasks[0], 1);
//    ASSERT_EQUAL(expected, tasks[0].progress);
//    fclose(file[0]);
//}

CTEST(reset_test_user_files, reset_test_user_files)
{
    file[0] = fopen("test/users/user1archive.txt", "w+");
    file[0] = fopen("test/users/user1bin.txt", "w+");
    file[0] = fopen("test/users/user4.txt", "w+");
    task tasks[10];
    strcpy(tasks[1].name, "Name");
    strcpy(tasks[1].description, "Description");
    strcpy(tasks[1].category, "Category");
    strcpy(tasks[1].priority, "***");
    tasks[1].status = '~';
    tasks[1].day = 1;
    tasks[1].month = 1;
    tasks[1].year = 2020;
    tasks[1].progress = 10;
    write_in_file(file[0], &tasks[1], find_id(file[0]));
    // file[0] = fopen("test/users/test.txt", "w+");
    fclose(file[0]);
}
