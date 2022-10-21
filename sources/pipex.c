/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:06:15 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/21 17:39:14 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	cmd1(t_pipex *pipex)
{
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[0]);
	close (pipex->fd[1]);
	pipex->cmd = pipex->argv[2];
	execute_cmd(pipex);
}

void	cmd2(t_pipex *pipex)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	pipex->cmd = pipex->argv[3];
	execute_cmd(pipex);
}

void	pipe_function(t_pipex *pipex)
{
	pid_t	pid;
	pid_t	pid2;

	if (pipe(pipex->fd) == -1)
		display_error("pipe", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		display_error("fork", EXIT_FAILURE);
	if (pid == 0)
		cmd1(pipex);
	pid2 = fork();
	if (pid2 < 0)
		display_error("fork", EXIT_FAILURE);
	if (pid2 == 0)
		cmd2(pipex);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pid, NULL, WNOHANG);
	waitpid(pid2, NULL, 0);
	//cmd2(pipex);
}

int	populate_t_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int	fd[2];

	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->fd = fd;
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
