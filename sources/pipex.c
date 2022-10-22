/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:06:15 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/22 12:27:54 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(t_pipex *pipex, int *fd)
{
	close(fd[0]);
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]);
	pipex->cmd = pipex->argv[2];
	execute_cmd(pipex);
}

void	cmd2(t_pipex *pipex, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(fd[0]);
	pipex->cmd = pipex->argv[3];
	execute_cmd(pipex);
}
void	pipe_function(t_pipex *pipex)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		display_error("pipe", EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		display_error("fork", EXIT_FAILURE);
	if (pid1 == 0)
		cmd1(pipex, fd);
	pid2 = fork();
	if (pid2 < 0)
		display_error("fork", EXIT_FAILURE);
	if (pid2 == 0)
		cmd2(pipex, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	populate_t_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	open_files(pipex);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		populate_t_pipex(argc, argv, envp, &pipex);
		pipe_function(&pipex);
		close_files(&pipex);
	}
	else
		show_usage();
	return (0);
}
