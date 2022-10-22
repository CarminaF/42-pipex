/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:49:13 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/22 12:28:32 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	close_files(t_pipex *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	return (0);
}

int	open_files(t_pipex *pipex)
{
	pipex->infile_fd = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile_fd == -1)
		display_error(pipex->argv[1], EXIT_FAILURE);
	pipex->outfile_fd = open(pipex->argv[pipex->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
		display_error(pipex->argv[pipex->argc - 1], EXIT_FAILURE);
	return (0);
}
