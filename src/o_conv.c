/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 08:43:59 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/26 08:44:00 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	o_conv2(struct s_stru *s, va_list ap)
{
	int z;

	z = 0;
	ft_putstr(s->print);
	s->conv = o_modif(s, ap);
	s->conv = x_preci(s, s->conv);
	if (s->conv[0] == '0')
		z = 1;
	if (s->diese != 0 && z != 1)
		s->conv = o_diese(&(*s), s->conv);
}

int		o_conv(struct s_stru *s, va_list ap)
{
	char	*value;

	value = NULL;
	o_conv2(&(*s), ap);
	s->conv = o_width(&(*s), s->conv);
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	ft_strdel(&s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(s->format, s->end, ft_strlen(s->format));
	ft_strdel(&value);
	value = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&value);
	s->beg = 0;
	s->q = 0;
	initparcer(&(*s));
	return (0);
}
