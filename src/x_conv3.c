/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 08:10:47 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 08:10:49 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*x_diese(struct s_stru *s, char *s1)
{
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(s2 = ft_strnew(sizeof(s2) * s->preci + 4)))
		return (0);
	s2[0] = '0';
	s2[1] = 'x';
	return (s2);
}

void	x_conv2(struct s_stru *s, char *value)
{
	int	i;

	i = 0;
	if (s->upx != 0)
	{
		while (s->conv[i])
		{
			s->conv[i] = ft_toupper(s->conv[i]);
			i++;
		}
	}
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(value, s->end, ft_strlen(value));
	ft_strdel(&value);
	value = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&value);
	s->beg = 0;
	s->q = 0;
	ft_strdel(&s->conv);
	initparcer(&(*s));
}

int		x_conv(struct s_stru *s, va_list ap)
{
	int		z;
	char	*value;

	value = NULL;
	z = 0;
	ft_putstr(s->print);
	s->conv = x_modif(s, ap, &z);
	if (s->conv[0] == '0')
		z = 1;
	s->conv = x_preci(s, s->conv);
	value = s->conv;
	s->conv = x_width(&(*s), s->conv, z);
	ft_strdel(&value);
	x_conv2(&(*s), &(*value));
	return (0);
}
