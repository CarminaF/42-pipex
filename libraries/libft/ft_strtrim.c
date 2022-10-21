/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:49:05 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/11 20:16:29 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	if (!set)
		return (0);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}
