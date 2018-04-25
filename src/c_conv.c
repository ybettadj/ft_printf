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

void	c_conv2(struct s_stru *s, va_list ap, unsigned char c, char *value)
{
	ft_putstr(s->print);
	s->conv = ft_strdup("a");
	s->conv[0] = c;
	s->conv = s_width(s, pourc_preci(s, s->conv));
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	ft_strdel(&s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(s->format, s->end, ft_strlen(s->format));
	ft_strdel(&value);
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	s->beg = 0;
	s->q = 0;
	initparcer(&(*s));
}

void	print_0(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'a')
			write(1, "\0", 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}

void	c_conv3(struct s_stru *s, va_list ap, unsigned char c, char *value)
{
	ft_putstr(s->print);
	s->conv = ft_strdup("a");
	s->conv = s_width(s, pourc_preci(s, s->conv));
	print_0(s->conv);
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
}

int		c_conv(struct s_stru *s, va_list ap)
{
	unsigned char	c;
	char			*str;
	char			*value;

	value = NULL;
	c = (unsigned char)va_arg(ap, int);
	if (c != '\0')
		c_conv2(&(*s), ap, c, value);
	else
		c_conv3(&(*s), ap, c, value);
	return (0);
}
