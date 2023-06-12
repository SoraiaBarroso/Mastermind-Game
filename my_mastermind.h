#ifndef MY_MASTERMIND_H
#define MY_MASTERMIND_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int check_input(char* input);
int len_input(char* input);
int check_secretcode(char* secret_code, char* input);
int main(int ac, char** av);

#endif