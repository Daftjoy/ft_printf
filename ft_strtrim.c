/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:35:47 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/27 16:01:01 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_remove_char(char c, char *set)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(set);
	i = 0;
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (set && ft_remove_char(s1[i], (char*)set))
		i++;
	while (set && len > 1 && ft_remove_char(s1[len - 1], (char*)set))
		len--;
	if (i > len)
		len = i;
	if (!(str = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
