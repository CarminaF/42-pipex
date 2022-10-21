/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:46:29 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/11 18:08:14 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	op;
	int	res;

	i = 0;
	op = 1;
	res = 0;
	if (*str == 0)
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			op = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * op);
}
