/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:11:00 by agianico          #+#    #+#             */
/*   Updated: 2020/01/17 16:25:06 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_rep(t_print *print, int n, char c)
{
	while (n-- > 0)
	{
		write(1, &c, 1);
		print->len++;
	}
}

void		ft_width(t_print *print, char *d, int i, int dif)
{
	if (d[0] == '0' && print->flags->dot == 1)
		dif += 1;
	if (print->flags->zero == 1)
	{
		if (d[0] == '-' && i++)
			ft_rep(print, 1, '-');
		if (print->flags->dot == 0)
			ft_rep(print, dif, '0');
		else
			ft_rep(print, dif, ' ');
	}
	else if (print->flags->minus == 0)
		ft_rep(print, dif, ' ');
	if (print->type == 'p')
	{
		ft_rep(print, 1, '0');
		ft_rep(print, 1, 'x');
	}
	while (d[++i])
		if (d[0] != '0' || print->flags->dot == 0)
			ft_rep(print, 1, d[i]);
	if (print->flags->minus == 1)
		ft_rep(print, dif, ' ');
}

void		ft_precision(t_print *print, char *d, int i, int dif)
{
	if (print->type == 'p')
	{
		ft_rep(print, 1, '0');
		ft_rep(print, 1, 'x');
	}
	if (d[0] == '0' && print->flags->precision == 0)
		return ;
	if (d[0] == '-')
	{
		ft_rep(print, 1, '-');
		i++;
		ft_rep(print, dif + 1, '0');
	}
	else
		ft_rep(print, dif, '0');
	while (d[++i])
		ft_rep(print, 1, d[i]);
}

void		ft_both(t_print *print, char *d, int i)
{
	int		dif;

	dif = print->flags->width - print->flags->precision;
	if (dif > 0 && print->flags->minus == 0)
	{
		if (d[0] == '-')
			dif -= 1;
		if (print->flags->precision < (int)ft_strlen(d))
			dif = print->flags->width - ft_strlen(d);
		ft_rep(print, dif, ' ');
	}
	ft_precision(print, d, i, print->flags->precision - ft_strlen(d));
	if (dif > 0 && print->flags->minus == 1)
	{
		if (d[0] == '-')
			dif -= 1;
		if (print->flags->precision < (int)ft_strlen(d))
			dif = print->flags->width - ft_strlen(d);
		ft_rep(print, dif, ' ');
	}
}

void		ft_type_d(t_print *print, void *arg)
{
	char	*d;
	int		i;

	i = -1;
	if (print->type == 'u')
		d = ft_itoa((long int)arg, "0123456789", 10);
	else
		d = ft_itoa((int)arg, "0123456789", 10);
	print->pos++;
	if (print->flags->width != 0 && print->flags->precision == 0)
		return (ft_width(print, d, i, (print->flags->width - ft_strlen(d))));
	else if (print->flags->width == 0 && print->flags->dot != 0)
		return (ft_precision(print, d, i,
		print->flags->precision - ft_strlen(d)));
	else if (print->flags->width != 0 && print->flags->precision != 0)
		ft_both(print, d, i);
	else
	{
		while (d[++i])
			if (d[0] != '0' || print->flags->dot == 0)
				ft_rep(print, 1, d[i]);
	}
	free(d);
}
