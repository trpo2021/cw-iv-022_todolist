#pragma once

#include <stdio.h>
#include <locale.h>

void add(FILE *file[10]);

int find_id(FILE *file);

void read_tasks(FILE *file);

void indent();

void edit(FILE *file, int id);

void name_edit(task *task1);

void description_edit(task *task1);

void status_edit(task *task1);

void deadline_edit(task *task1);

void priority_edit(task *task1);

void category_edit(task *task1);

void progress_edit(task *task1);

void replacement(FILE *file, task *task1, int id);
