/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:29:40 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/18 19:31:48 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	j = ft_strlen(dst);
	while (i + j + 1 < dstsize && src[i])
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
