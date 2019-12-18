/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:02:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/18 21:30:46 by antmarti         ###   ########.fr       */
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
			if (print->format[print->pos] == '%' && print->pos++)
			{
				ft_flags(print);
				printf("%d\n", (int)print->flags->);
				arg = va_arg(print->list, void *);
				if (print->flags->ast == 1)
				{
					ft_ast(print, arg);
					arg = va_arg(print->list, void *);
				}
				//ft_converse(print, arg);
			}
			write(1, &((const void *)print->format)[print->pos], 1);
			print->len++;
			print->pos++;
		}
	}
	return (print->len);
}

int		main(void)
{
	ft_printf("axjaa   %012412421.*d",43,  23);
}
