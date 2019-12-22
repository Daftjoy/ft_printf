/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:29:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/22 14:08:36 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base(int nbr, int n, const char *base, t_print *print)
{
	int i;

	i = nbr;
	while ((i /= 16) >= 1)
		print->len++;
	if (nbr >= n)
	{
		ft_putnbr_base(nbr / n, n, base, print);
	}
	write(1, &base[(nbr % n)], 1);
	return (i);
}
