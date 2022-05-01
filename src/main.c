#include "pipex.h"

int	main(int argc, char *argv[])
{
	char	**cmd1;
	char	**cmd2;
	int		pid;
	int		pipex[2];

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
	if (pid == 0)
		first_cmd(argv[1], pipex, cmd1);
	else
		second_cmd(argv[4], pipex, cmd2, pid);
	free_strarray(cmd1);
	free_strarray(cmd2);
	return (0);
}
