/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaresp <amaresp@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:04:25 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/25 21:06:46 by amaresp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (((char*)s) + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (((char*)s) + i);
	return (NULL);
}
