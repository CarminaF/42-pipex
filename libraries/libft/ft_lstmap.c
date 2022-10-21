/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:30:26 by cfamilar          #+#    #+#             */
/*   Updated: 2022/07/18 19:37:04 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlst;

	if (!lst || !f)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}
