/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:41:44 by arowe             #+#    #+#             */
/*   Updated: 2022/05/02 14:41:48 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strarray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*check_access(char **paths, char *cmd[])
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free_strarray(paths);
			return (path);
		}
		free(path);
	}
	free_strarray(paths);
	return (NULL);
}

char	*find_path(char *cmd[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (environ[i])
	{
		if (ft_strncmp("PATH=", environ[i], 5) == 0)
		{
			paths = ft_split(environ[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (check_access(paths, cmd));
}

void	first_cmd(char *file, int p[2], char **cmd)
{
	int		fd;
	char	*command;

	if (access(cmd[0], X_OK) != 0)
		command = find_path(cmd);
	else
		command = cmd[0];
	if (!command)
	{
		ft_printf("%s: command not found\n", cmd[0]);
	}
	fd = open(file, O_RDONLY);
	dup2(fd, 0);
	close(fd);
	close(p[0]);
	dup2(p[1], 1);
	close(p[1]);
	execve(command, cmd, environ);
}

void	second_cmd(char *file, int p[2], char **cmd, int pid)
{
	int		fd;
	int		new_pid;
	char	*command;

	if (access(cmd[0], X_OK) != 0)
		command = find_path(cmd);
	else
		command = ft_strdup(cmd[0]);
	if (!command)
		ft_printf("%s: command not found\n", cmd[0]);
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	waitpid(pid, NULL, WNOHANG);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
	if (command)
	{
		new_pid = fork();
		if (new_pid == 0)
			execve(command, cmd, environ);
		else
			free(command);
	}
}
