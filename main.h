#ifndef main_h
#define main_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void loop(char *);
void execute(char *, char **);

#endif /* main_h */
