/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaresp <amaresp@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:02:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/25 20:43:02 by amaresp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_print		*print;
	void		*arg;

	if (!(print = malloc(sizeof(t_print))))
		return (-1);
	if (format)
	{
		va_start(print->list, format);
		ft_init(print, format);
		while (print->format[print->pos])
		{
			if (print->format[print->pos] == '%')
			{
				print->pos++;
				ft_flags(print);
				arg = va_arg(print->list, void *);
				if (print->flags->ast != 0)
					arg = ft_ast(print, arg);
				ft_converse(print, arg);
			}
			else
			{
				write(1, &((const void *)print->format)[print->pos], 1);
				print->len++;
				print->pos++;
			}
		}
	}
	return (print->len);
}

int		main(void)
{
	//int a = 3;
	char b = 'a';

	printf("%d\n", ft_printf("%.16p hh %s\n", &b, "hola"));
	printf("%d\n", printf("%.16p hh %s\n", &b, "hola"));
}
