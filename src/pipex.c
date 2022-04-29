#include "pipex.h"

char    *find_path(char *cmd[])
{
    int     i;
    int     k;
    char    *path_var;
    char    **paths;
    char    *path;
    char    *temp;

    i = 0;
    while (__environ[i])
    {
        if (ft_strncmp("PATH=", __environ[i], 5) == 0)
        {
            path_var = __environ[i];
            break ;
        }
        i++;
    }
    paths = ft_split(path_var + 5, ':');
    i = 0;
    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(temp, cmd[0]);
        free(temp);
        if (access(path, X_OK) == 0)
        {
            k = 0;
            while (paths[k])
                free(paths[k++]);
            free(paths);
            return (path);
        }
        free(path);
        i++;
    }
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return (NULL);
}

void first_cmd(char *file, int p[2], char **cmd)
{
    int fd;
    char *command;

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
    execve(command, cmd, __environ);
    perror("execve");
    exit(1);
}

void second_cmd(char *file, int p[2], char **cmd, int pid)
{
    int fd;
    int new_pid;
    char *command;

    if (access(cmd[0], X_OK) != 0)
        command = find_path(cmd);
    else
        command = ft_strdup(cmd[0]);
    if (!command)
    {
        ft_printf("%s: command not found\n", cmd[0]);
    }
    close(p[1]);
    dup2(p[0], 0);
    close(p[0]);
    waitpid(pid, NULL, WNOHANG);
    fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
        perror(file);
    dup2(fd, 1);
    close(fd);
    if (command)
    {
        new_pid = fork();
        if (new_pid == 0)
        {
            execve(command, cmd, __environ);
            perror("execve");
            exit(1);
        }
        else
        {
            free(command);
        } 
    }
}

int main(int argc, char *argv[])
{
    int     i;
    char    **cmd1;
    char    **cmd2;
    int     pid;
    int     pipex[2];

    if (argc != 5)
       {
    ft_printf("bad args\n");
        return (1);
    }
    cmd1 = ft_split(argv[2], ' ');
    cmd2 = ft_split(argv[3], ' ');
    if (pipe(pipex) < 0)
    {
        perror("bad pipe");
        return (1);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("bad fork\n");
        return (1);
    }
    else if (pid == 0)
        first_cmd(argv[1], pipex, cmd1);
    else
        second_cmd(argv[4], pipex, cmd2, pid);
    i = 0;
    while (cmd1[i])
        free(cmd1[i++]);
    free(cmd1);
    i = 0;
    while (cmd2[i])
        free(cmd2[i++]);
    free(cmd2);
    return (0);
}