/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 03:13:42 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/23 03:13:44 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_stru
{
	int			retour;
	int			mark;
	int			q;
	intmax_t	numconv;
	uintmax_t	numconv2;
	char		*conv;
	char		*format;
	char		*print;
	char		charpourc;
	int			beg;
	int			end;
	int			bs0;
	int			valid;
	int			diese;
	int			zero;
	int			less;
	int			plus;
	int			width;
	int			preci;
	int			space;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			s;
	int			ups;
	int			p;
	int			d;
	int			upd;
	int			i;
	int			o;
	int			upo;
	int			u;
	int			upu;
	int			x;
	int			upx;
	int			c;
	int			upc;
	int			pourc;
	int			ppp;
	int			counter;
}				t_stru;

struct s_stru	initstru(const char *format);
void			initparcer(struct s_stru *s);
char			*addchar(struct s_stru *s, char c);
int				before_pourc(struct s_stru *s, va_list ap);
void			after_pourc(struct s_stru *s, va_list ap);
void			valid_larg(struct s_stru *s);
void			valid_preci(struct s_stru *s);
void			valid_flag(struct s_stru *s);
void			parcerflag1(struct s_stru *s);
void			parcerlarg(struct s_stru *s);
void			parcerpreci(struct s_stru *s);
void			parcerflag2(struct s_stru *s);
void			parcerconv(struct s_stru *s);
void			parcerconv2(struct s_stru *s);
int				begin(struct s_stru *s, va_list ap);
char			*s_preci(struct s_stru *s, char *s1);
char			*s_width(struct s_stru *s, char *s1);
char			*changeformat(struct s_stru *s);
int				ft_printf(const char *format, ...);
int				s_conv(struct s_stru *s, va_list ap);
int				pourc_conv(struct s_stru *s, va_list ap);
char			*pourc_preci(struct s_stru *s, char *s1);
char			*pourc_width(struct s_stru *s, char *s1);
char			*pourc_changeformat(struct s_stru *s);
char			*d_preci(struct s_stru *s, char *s1);
char			*d_changeformat(struct s_stru *s);
int				d_conv(struct s_stru *s, va_list ap);
char			*modif(struct s_stru *s, va_list ap);
void			modif2(struct s_stru *s, va_list ap);
char			*x_modif(struct s_stru *s, va_list ap, int *z);
int				x_conv(struct s_stru *s, va_list ap);
char			*x_diese(struct s_stru *s, char *s1);
char			*x_preci(struct s_stru *s, char *s1);
char			*x_width(struct s_stru *s, char *s1, int z);
char			*x_changeformat(struct s_stru *s);
char			*u_modif(struct s_stru *s, va_list ap);
int				u_conv(struct s_stru *s, va_list ap);
void			initmodif(struct s_stru *s);
char			*o_modif(struct s_stru *s, va_list ap);
int				o_conv(struct s_stru *s, va_list ap);
int				c_conv(struct s_stru *s, va_list ap);
int				p_conv(struct s_stru *s, va_list ap);
char			*ft_itoa_base(uintmax_t n, uintmax_t base);
static int		conv_hex(uintmax_t nb);
char			*u_width(struct s_stru *s, char *s1);
char			*void_width(struct s_stru *s, char *s1);
char			*void_width2(struct s_stru *s, char *s1, char *s2, int k);
char			*void_width3(struct s_stru *s, char *s1, char *s2, int k);
void			d_width5(struct s_stru *s, char *s1, char *s2);
void			d_width6(struct s_stru *s, char *s1, char *s2);
char			*d_space(struct s_stru *s);
char			*negactif(struct s_stru *s);
char			*d_changeformat(struct s_stru *s);
char			*plus_d(struct s_stru *s, int neg, int *plus);
char			*negdesac(struct s_stru *s);
void			d_preci_cond(struct s_stru *s, char *s2);
char			*d_preci(struct s_stru *s, char *s1);
void			d_width2(struct s_stru *s, char *s1, char *s2, int *neg);
void			d_width3(struct s_stru *s, char *s1, char *s2);
void			d_width4(struct s_stru *s, char **s1, int *neg);
static int		conv_hex(uintmax_t nb);
char			*modif(struct s_stru *s, va_list ap);
char			*x_modif(struct s_stru *s, va_list ap, int *z);
char			*u_modif(struct s_stru *s, va_list ap);
char			*o_modif(struct s_stru *s, va_list ap);
static void		ft_neg_n_count2(intmax_t *i, intmax_t *n, intmax_t *y);
char			*ft_itoa2(intmax_t n);
char			*ft_itoa_base(uintmax_t n, uintmax_t base);
void			modif2(struct s_stru *s, va_list ap);
void			modifunsigned(struct s_stru *s, va_list ap);
char			*o_diese(struct s_stru *s, char *s1);
void			o_width2(struct s_stru *s, char *s1, char *s2);
void			o_width3(struct s_stru *s, char *s1, char *s2);
void			o_width4(struct s_stru *s, char *s1, char *s2);
char			*o_width(struct s_stru *s, char *s1);
static int		conv_hex_p(intptr_t nb);
char			*ft_itoa_base_p(intptr_t *n, intptr_t base);
char			*pourc_preci(struct s_stru *s, char *s1);
void			x_preci2(struct s_stru *s, char *s1, char *s2);
char			*x_preci(struct s_stru *s, char *s1);
void			x_width2(struct s_stru *s, char *s1, char *s2, int z);
void			x_width3(struct s_stru *s, char *s1, char *s2, int z);
void			x_width4(struct s_stru *s, char *s1, char *s2, int z);
void			x_width5(struct s_stru *s, char *s1, char *s2, int z);
char			*x_width(struct s_stru *s, char *s1, int z);

#endif
