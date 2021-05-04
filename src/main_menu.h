#pragma once

#include <stdio.h>
#include <locale.h>

typedef struct
{
    char description[100];
    char name[50];
    char category[25];
    char priority[4];
    char status;
    int day;
    int month;
    int year;
    int progress;
} task;

void todolist(FILE *file[10]);

int archive();

int bin();

int settings();

void authors();

int find_id(FILE *file);