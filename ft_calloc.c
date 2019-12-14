/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:38:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/27 15:30:24 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;

	if (count < 0 || size < 0)
		return (0);
	if (!(str = malloc(count * size)))
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}
