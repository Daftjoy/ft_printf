/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaresp <amaresp@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:58:13 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/26 13:33:20 by amaresp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
