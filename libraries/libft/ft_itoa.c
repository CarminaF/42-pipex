/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:41:24 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/18 15:39:34 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_numlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{		
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	num;

	i = ft_numlen(n);
	str = (char *)malloc(sizeof (char) * (i + 1));
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[i] = '\0';
	while (num != 0)
	{
		str[i - 1] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}
