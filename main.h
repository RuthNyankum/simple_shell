#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
/*extern char **argv;*/
/*User defined functions*/
/*main shell functions*/
void execmd(char **argv);
char *get_location(char *command);
char **string_tokenize(char *lineptr, char **argv);
/*Helper Functions*/
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, size_t n);
size_t _strlen(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char c);
int _printstr(char *str);
void _free(char **argv);
#endif
