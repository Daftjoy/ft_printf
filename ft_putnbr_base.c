/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:29:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/19 16:20:45 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_self_strstr(const char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j])
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_change_base(int nbr, int n, const char *base)
{
	int i;

	i = 0;
	i++;
	if (nbr >= n)
	{
		ft_change_base(nbr / n, n, base);
	}
	write(1, &base[(nbr % n)], 1);
	return (i);
}

int		ft_correct(const char *base)
{
	int i;

	i = 0;
	if (!base[0] || ft_strlen(base) == 1)
		return (0);
	if (ft_self_strstr(base) == 0)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, const char *base)
{
	if (ft_correct(base))
		return (ft_change_base(nbr, ft_strlen(base), base));
	return (0);
}

int main()
{
	printf("%d", ft_putnbr_base(420, "0123456789abcdef"));
}
