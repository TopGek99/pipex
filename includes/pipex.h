#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

void	free_strarray(char **arr);
void	first_cmd(char *file, int p[2], char **cmd);
void	second_cmd(char *file, int p[2], char **cmd, int pid);

#endif