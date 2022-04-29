#ifndef PIPEX_H
#define PIPEX_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define LINE_MAX 100
#define CHAR_MAX 256

char	**strsplit(const char *s, char c);
int	get_commands(char *commands[]);

#endif