#ifndef main_h
#define main_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void loop(char *);
void execute(char *prog_name, char **av);

#endif /* main_h */
