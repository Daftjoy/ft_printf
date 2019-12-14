/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:19:17 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/19 19:35:51 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cont;

	if (!(cont = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	cont->next = 0;
	cont->content = 0;
	if (content)
		cont->content = content;
	return (cont);
}
