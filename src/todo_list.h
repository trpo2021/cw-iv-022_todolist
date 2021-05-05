#pragma once

#include <stdio.h>
#include <locale.h>

void add(FILE *file[10]);

int find_id(FILE *file);

void read_tasks(FILE *file);

void indent();