/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:26:22 by cfamilar          #+#    #+#             */
/*   Updated: 2022/10/20 21:43:43 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	display_error(char *error, int status)
{
	perror(ft_strjoin("pipex: ", error));
	exit(status);
}

void	show_usage(void)
{
	ft_putstr_fd("Wrong number of arguments. (╥﹏╥) \n", 2);
	ft_putstr_fd("Example usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(EXIT_FAILURE);
}
