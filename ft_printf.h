/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaresp <amaresp@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:24:55 by antmarti          #+#    #+#             */
/*   Updated: 2019/12/25 00:22:37 by amaresp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			ast;
	int			precision;
}				t_flags;


typedef struct	s_print
{
	const char		*format;
	va_list			list;
	int				len;
	char			type;
	t_flags			*flags;
	int				pos;
}				t_print;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_printf(const char *format, ...);
void			ft_flags(t_print *print);
void 			ft_init(t_print *print, const char *format);
void			ft_init_flags(t_print *print);
void			ft_converse(t_print *print, void *arg);
void			ft_type_s(t_print *print, void *arg);
void			ft_type_c(t_print *print, void *arg);
void			ft_type_d(t_print *print, void *arg);
void			ft_type_x(t_print *print, void *arg); 
void			ft_rep(t_print *print, int n, char c);
void			ft_width(t_print *print, char *d, int i, int dif);
void			ft_precision(t_print *print, char *d, int i, int dif);
void			ft_both(t_print *print, char *d, int i);
int				ft_counter(t_print *print);
void			*ft_ast(t_print *print, void *arg);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_type_p(t_print *print, void *arg);
int				ft_putnbr_base(int nbr, int n, const char *base, t_print *print);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *nptr);
char			*ft_itoa(long long int n, char *base, int blen);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
