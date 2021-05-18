#pragma once

#include <stdio.h>

void delete_task(FILE* file[10], int id);

void clean_bin(FILE* file[10]);

void restore_from_bin(FILE* file[10], int id);