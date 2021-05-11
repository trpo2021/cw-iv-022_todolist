#pragma once

#include <locale.h>
#include <stdio.h>

typedef struct {
    char description[80];
    char name[30];
    char category[20];
    char priority[4];
    char status;
    int id;
    int day;
    int month;
    int year;
    int progress;
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
