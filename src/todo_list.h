#pragma once

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char description[80];
    char name[30];
    char category[20];
    char priority[4];
    char status;
    unsigned int id;
    unsigned int day;
    unsigned int month;
    unsigned int year;
    unsigned int progress;
} task;

void add(FILE* file[10]);

int find_id(FILE* file);

void read_tasks(FILE* file);

void indent();

void edit(FILE* file, int id);

void name_edit(task* task1);

void description_edit(task* task1);

void status_edit(task* task1);

void deadline_edit(task* task1);

void priority_edit(task* task1);

void category_edit(task* task1);

void progress_edit(task* task1);

void replacement(FILE* file, task* task1, int id);

void write_in_file(FILE* file, task* task1, int id);

void task_scan(FILE* file, task* task1, int id);

void move_to_bin(FILE* file[10], int id);

void move_to_archive(FILE* file[10], int id);

void duplication(FILE* file[10], int id);

int day_check(int day);

int month_check(int month);

int year_check(int year);

void swap(task* task1, task* task2);

void sort_name(FILE* file, int id);

void sort_description(FILE* file, int id);

void sort_status(FILE* file, int id);

void sort_priority(FILE* file, int id);

void sort_category(FILE* file, int id);

void sort_progress(FILE* file, int id);

void sort_deadline(FILE* file, int id);

void sort(FILE* file, int id);
