/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:10:01 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/06 17:10:04 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void 	p_conv2(struct s_stru *s, char *value, char *s1)
{
	value = s->conv;
	s->conv = s1;
	ft_strdel(&value);
	if (s->width < 0)
		s->width = 0;
	s->conv = o_width(&(*s), s->conv);
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(s->format, s->end, ft_strlen(s->format));
	ft_strdel(&value);
	value = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&value);
}

void 	p_conv3(struct s_stru *s, char *value, char *s1)
{
	value = s->conv;
	s->conv = ft_strjoin(s1,value);
	ft_strdel(&value);
	if (s->width < 0)
		s->width = 0;
	s->conv = o_width(&(*s), s->conv);
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(s->format, s->end, ft_strlen(s->format));
	ft_strdel(&value);
	value = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&value);
}

void 	p_conv4(struct s_stru *s, char *value, char *s1)
{
	value = s->conv;
	s->conv = ft_strjoin(s1,value);
	ft_strdel(&value);
	if (s->width < 0)
		s->width = 0;
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
}

int 				p_conv(struct s_stru *s, va_list ap)
{
	char *s1;
	char *value;
 
	value = NULL; 
	intptr_t ptr = (intptr_t)va_arg(ap, void *);
	s->conv = ft_itoa_base_p(&ptr, 16);
	s1 = "0x";
	s->conv = x_preci(s, s->conv);
	ft_putstr(s->print);
	if (s->conv[1] == '\0')
	{
		if (s->conv[0] != '0')
			p_conv2(&(*s), &(*value), &(*s1));
		else
			p_conv3(&(*s), &(*value), &(*s1));
	}
	else
		p_conv4(&(*s), &(*value), &(*s1));
	s->beg = 0;
	s->q = 0;
	initparcer(&(*s));
	return (0);
}