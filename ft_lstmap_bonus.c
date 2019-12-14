/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:05:05 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/20 16:46:56 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*newlst;

	if (!lst)
		return (0);
	newlst = ft_lstnew((f)(lst->content));
	p = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = ft_lstnew((*f)(lst->content))))
			ft_lstdelone(lst, del);
		newlst = newlst->next;
	}
	return (p);
}
