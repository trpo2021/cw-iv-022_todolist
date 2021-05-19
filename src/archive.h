#pragma once

#include <stdio.h>

void delete_task_from_the_archive(FILE* file[10], int id);

void clean_archive(FILE* file[10]);

void unarchive(FILE* file[10], int id);
