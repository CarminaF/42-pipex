/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:14:43 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/21 14:41:28 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*ft_stralloc(char const *s, size_t start, size_t finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof (char) * (finish - start + 1));
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**arr;

	arr = malloc((ft_wordcount(s, c) + 1) * sizeof (char *));
	if (!s || !arr)
		return (0);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			arr[j++] = ft_stralloc(s, start, i);
			start = -1;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}
/*
int main(void)
{
    char const  *s = "abcabcabcabc";
    char c = 'c';

    char **arr = ft_split(s, c);

    for (int i = 0; i < ft_wordcount(s, c); i++)
    {
        printf("%s\n", arr[i]);
    }
}*/
