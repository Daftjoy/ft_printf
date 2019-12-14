/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:18:06 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/21 18:42:34 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst)
		return (0);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen((char*)src));
	while (i < dstsize - 1 && src[i])
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	((char*)dst)[i] = '\0';
	return (ft_strlen((char*)src));
}
