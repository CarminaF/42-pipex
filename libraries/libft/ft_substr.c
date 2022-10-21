/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:41:13 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/21 15:25:28 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
	{
		p = malloc(sizeof(char));
		if (!p)
			return (NULL);
		else
			p[0] = '\0';
		return (p);
	}
	len = min(len, ft_strlen(s) - start);
	p = malloc(sizeof(char) * len + 1);
	if (!p || !s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}
