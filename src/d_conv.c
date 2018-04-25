/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 07:51:27 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/28 07:51:29 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char		*d_width_help(struct s_stru *s, char *s1, int *neg, int *plus)
{
	char	*s2;

	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (s->zero != 0 && s->preci == 0 && s->less == 0)
		d_width3(&(*s), &(*s1), &(*s2));
	else
	{
		if (*neg != 0)
		{
			s1 = negdesac(&(*s));
			s->width++;
			*neg = 0;
		}
		else
			s1 = plus_d(&(*s), *neg, &(*plus));
		d_width5(&(*s), &(*s1), &(*s2));
	}
	ft_strdel(&s1);
	return (s2);
}

char		*d_width(struct s_stru *s, char *s1, int *neg, int *plus)
{
	char	*s2;

	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (*neg != 0)
	{
		s1 = negdesac(&(*s));
		s->width++;
		*neg = 0;
	}
	d_width6(&(*s), &(*s1), &(*s2));
	ft_strdel(&s1);
	return (s2);
}

void		d_convhelp1(struct s_stru *s, int *neg, int *plus, va_list ap)
{
	ft_putstr(s->print);
	s->conv = modif(s, ap);
	if (s->conv[0] == '-')
	{
		s->conv = negactif(&(*s));
		*neg += 1;
		if (s->width > 0)
			s->width--;
	}
	if (*neg == 0 && s->plus != 0)
	{
		if (s->width > 0)
			s->width--;
	}
	if (s->space != 0 && *neg == 0 && s->plus == 0 && s->width > 0)
		s->width = s->width - 1;
	s->conv = d_preci(s, s->conv);
	if (s->width != 0 && s->width > ft_strlen(s->conv))
	{
		if (s->less == 0)
			s->conv = d_width_help(&(*s), s->conv, &(*neg), &(*plus));
		else
			s->conv = d_width(&(*s), s->conv, &(*neg), &(*plus));
	}
}

void		d_convhelp2(struct s_stru *s, int *neg, int *plus)
{
	if (s->space != 0 && *neg == 0 && s->plus == 0)
		s->conv = d_space(&(*s));
	if (*plus == 0)
		s->conv = plus_d(&(*s), *neg, &(*plus));
	if (*neg != 0)
		s->conv = negdesac(&(*s));
}

int			d_conv(struct s_stru *s, va_list ap)
{
	int		neg;
	int		plus;
	char	*value;

	neg = 0;
	plus = 0;
	value = NULL;
	d_convhelp1(&(*s), &neg, &plus, ap);
	d_convhelp2(&(*s), &neg, &plus);
	value = ft_strjoin(s->print, s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	ft_putstr(s->conv);
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
	return (0);
}
