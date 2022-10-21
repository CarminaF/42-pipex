/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:26 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/20 21:20:15 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h> 

typedef struct pipex
{
	int		argc;
	int		infile_fd;
	int		outfile_fd;
	int		*fd;
	char	*cmd;
	char	**argv;
	char	**envp;
}	t_pipex;

void	pipe_function(t_pipex *pipex);
void	execute_cmd(t_pipex *pipex);
void	display_error(char *error, int status);
void	show_usage(void);
int		close_files(t_pipex *pipex);
int		open_files(t_pipex *pipex);

#endif 
