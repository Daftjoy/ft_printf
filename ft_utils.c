/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:24:55 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/22 02:38:38 by antmarti         ###   ########.fr       */
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
	print->flags->width = 0;
	print->flags->ast = 0;
	print->flags->dot = 0;
	print->flags->minus = 0;
	print->flags->zero = 0;
	print->flags->precision = 0;
}

void	ft_flags(t_print *print)
{
	ft_init_flags(print);
	if (print->format[print->pos] == '-' && print->pos++)
		print->flags->minus = 1;
	else if (print->format[print->pos] == '0' && print->pos++)
		print->flags->zero = 1;
	print->flags->width = ft_counter(print);
	if (print->format[print->pos] == '*' && print->pos++)
		print->flags->ast = 1;
	if (print->format[print->pos] == '.' && print->pos++)
	{
		print->flags->dot = 1;
		print->flags->precision = ft_counter(print);
	}
	if (print->format[print->pos] == '*' && print->pos++)
	{
		if (print->flags->ast == 0)
			print->flags->ast = 2;
		if (print->flags->ast == 1)
			print->flags->ast = 3;
	}
}

int		ft_counter(t_print *print)
{
	int numb;

	numb = 0;
	if (ft_isdigit(print->format[print->pos]))
	{
		numb = ft_atoi(&print->format[print->pos]);
		while (ft_isdigit(print->format[print->pos]))
			print->pos++;
	}
	return (numb);
}

void		*ft_ast(t_print *print, void *arg)
{
	if (print->flags->ast == 1 || print->flags->ast == 3)
	{
		print->flags->width = (int)arg;
		arg = va_arg(print->list, void *);
	}
	if (print->flags->ast == 2 || print->flags->ast == 3)
	{
		print->flags->precision = (int)arg;
		arg = va_arg(print->list, void *);
	}
	return ((void *)arg);
}

void		ft_converse(t_print *print, void *arg)
{
	if (print->format[print->pos] == 'c')
		ft_type_c(print, arg);
	if (print->format[print->pos] == 's')
		ft_type_s(print, arg);
	//if(print->format[print->pos] == 'p')
	if (print->format[print->pos] == 'd' || (print->format[print->pos] == 'i'))
		ft_type_d(print, arg);
	if (print->format[print->pos] == 'u')
	{
		print->type = 'u';
		ft_type_d(print, arg);
	}
	//if(print->format[print->pos] == 'x' || (print->format[print->pos] == 'X'))
}

void		ft_type_s(t_print *print, void *arg)
{
	int		i;
	char	*str;
	int		dif;

	i = -1;
	str = (char *)arg;
	dif = print->flags->width - ft_strlen(str);
	if (print->flags->minus == 0)
		ft_rep(print, dif, ' ');
	if (print->flags->dot != 0)
	{
		while (str[++i] && (i < print->flags->precision))
			write(1, &str[i], 1);
		print->len += print->flags->precision;
	}
	else
	{
		while (str[++i])
			write(1, &str[i], 1);
		print->len += ft_strlen(str);
	}
	if (print->flags->minus == 1)
		ft_rep(print, dif, ' ');
	print->pos++;
}

void		ft_type_c(t_print *print, void *arg)
{
	write(1, (const void *)arg, 1);
	print->len++;
	print->pos++;
}

/*void		ft_type_x(print, arg)
{
	char 	*hexbase;
	char 	*Hexbase;
	int		n;

	hexbase = "0123456789abcdef";
	Hexbase = "0123456789abcdef";

	while (n > 16)
	
}*/
