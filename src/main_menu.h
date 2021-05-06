#pragma once

#include <stdio.h>
#include <locale.h>

typedef struct
{
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

void todolist(FILE *file[10]);

int archive();

int bin();

int settings();

void authors();
