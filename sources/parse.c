/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:24:03 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/21 17:53:59 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(t_pipex *pipex)
{
	char	**paths;
	int		i;

	i = 0;
	while (pipex->envp[i] && ft_strncmp(pipex->envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(pipex->envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

char	*get_cmd_path(char *cmd, t_pipex *pipex)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	paths = get_paths(pipex);
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_cmd(t_pipex *pipex)
{
	char	**cmd_array;
	char	*cmd_path;

	cmd_array = ft_split(pipex->cmd, ' ');
	cmd_path = get_cmd_path(cmd_array[0], pipex);
	if (execve(cmd_path, cmd_array, pipex->envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd_array[0], 2);
		exit(127);
	}
}
