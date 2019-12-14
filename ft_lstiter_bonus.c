/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:50:31 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/20 12:34:49 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	aux = NULL;
	while (lst)
	{
		if (lst->next)
			aux = lst->next;
		else
			aux = NULL;
		f(lst->content);
		lst = aux;
	}
	lst = 0;
}
