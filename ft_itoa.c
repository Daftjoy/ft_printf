/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:36:12 by antmarti          #+#    #+#             */
/*   Updated: 2019/11/27 12:11:45 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char			*ft_append(char *str, int sign, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (sign != 0)
	{
		str[i] = '-';
		i++;
	}
	str[ft_count(n) + i] = '\0';
	while (n > 0)
	{
		i++;
		str[ft_count(n) - 1 + sign] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				sign;
	unsigned int	nb;

	sign = 0;
	str = 0;
	if (n < 0)
	{
		sign++;
		nb = n * (-1);
	}
	else
		nb = n;
	if (!(str = (char *)malloc((ft_count(nb) + sign + 1) * sizeof(char))))
		return (0);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (ft_append(str, sign, nb));
}
