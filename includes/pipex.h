/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:42:17 by arowe             #+#    #+#             */
/*   Updated: 2022/05/02 14:42:18 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

extern char	**environ;

void	free_strarray(char **arr);
void	first_cmd(char *file, int p[2], char **cmd);
void	second_cmd(char *file, int p[2], char **cmd, int pid);

#endif
