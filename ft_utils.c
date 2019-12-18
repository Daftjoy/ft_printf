/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:24:55 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/18 21:30:45 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_print *print, const char *format)
{
	print->format = format;
	print->len = 0;
	print->type = '0';
	print->pos = 0;
}

void	ft_init_flags(t_print *print)
{
	print->flags = malloc(sizeof(t_flags));
	print->flags->ancho = 0;
	print->flags->ast = 0;
	print->flags->dot = 0;
	print->flags->precision = 0;
	print->flags->minus = 0;
	print->flags->zero = 0;
}

void	ft_flags(t_print *print)
{
	ft_init_flags(print);
	if (print->format[print->pos] == '-' && print->pos++)
		print->flags->minus = 1;
	else if (print->format[print->pos] == '0' && print->pos++)
		print->flags->zero = 1;
	if (ft_isdigit(print->format[print->pos]))
	{
		print->flags->ancho = ft_atoi(&print->format[print->pos]);
		while (ft_isdigit(print->format[print->pos]))
			print->pos++;
	}
	if (print->format[print->pos] == '.' && print->pos++)
	{
		print->flags->dot = 1;
		if (ft_isdigit(print->format[print->pos]))
		{
			print->flags->precision = ft_atoi(&print->format[print->pos]);
			while (ft_isdigit(print->format[print->pos]))
				print->pos++;
		}
	}
	if (print->format[print->pos] == '*' && print->pos++)
		print->flags->ast = 1;
}

void		ft_converse(t_print *print, void *arg)
{
	//if(print->format[print->pos] == 'c')
	//if(print->format[print->pos] == 's')
	//if(print->format[print->pos] == 'p')
	if(print->format[print->pos] == 'd' || (print->format[print->pos] == 'i'))
		ft_type_d(print, arg)
	//if(print->format[print->pos] == 'u')
	//if(print->format[print->pos] == 'x' || (print->format[print->pos] == 'X'))
	//if(print->format[print->pos] == 'f')
	

}
