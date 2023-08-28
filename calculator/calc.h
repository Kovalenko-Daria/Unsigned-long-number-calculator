#ifndef CALC_H
#define CALC_H

#include <stdio.h>

#define LEN 100

int input(int *buffer, int *length);
void reverse_output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

#endif