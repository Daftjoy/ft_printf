/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:02:36 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/14 19:15:31 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list list;
	char	*str;
	
	va_start(list, format);
	write(1, format, ft_strlen(format));
	while (format)
	{
		str = va_arg(list, char *);
		write(1, str, ft_strlen(str));	
	}
	return (0);
}

int		main(void)
{
	ft_printf("Hola qué tal estamos", "what", NULL);
}
