/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourc_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 06:09:17 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/28 06:09:18 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	pourc2_width3(struct s_stru *s, char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s1[i])
		s2[k++] = s1[i++];
	while (k < s->width)
		s2[k++] = ' ';
	s2[k] = '\0';
}

void	pourc2_width2(struct s_stru *s, char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s->less != 0)
		pourc2_width3(&(*s), &(*s1), &(*s2));
	else if (s->zero != 0 && s->less == 0)
	{
		while (k < s->width - ft_strlen(s1))
			s2[k++] = '0';
		while (s1[i])
			s2[k++] = s1[i++];
		s2[k] = '\0';
	}
	else
	{
		while (k < s->width - ft_strlen(s1))
			s2[k++] = ' ';
		while (s1[i])
			s2[k++] = s1[i++];
		s2[k] = '\0';
	}
}

char	*pourc2_width(struct s_stru *s, char *s1)
{
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (s->width == 0 || (s->width != 0 && s->width <= ft_strlen(s1)))
	{
		ft_strdel(&s2);
		return (s1);
	}
	if (s->width != 0 && s->width > ft_strlen(s1))
	{
		pourc2_width2(&(*s), &(*s1), &(*s2));
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}

char	*pourc_changeformat(struct s_stru *s)
{
	char	*s1;
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(s1 = ft_strnew(sizeof(s1) * (1 + ft_strlen(s->format) + 1))))
		return (0);
	if (!(s2 = ft_strnew(sizeof(s2) * (1 + ft_strlen(s->format) + 1))))
		return (0);
	while (i < s->beg)
	{
		s1[i] = s->format[i];
		i++;
	}
	while (s->format[s->end])
		s2[k++] = s->format[s->end++];
	s1 = ft_strjoin(ft_strjoin(s1, s->conv), s2);
	s->format = s1;
	ft_strdel(&s2);
	return (s1);
}

int		pourc_conv(struct s_stru *s, va_list ap)
{
	char *value;

	value = NULL;
	ft_putstr(s->print);
	s->conv = ft_strnew(1);
	s->conv[0] = '%';
	s->conv = pourc2_width(s, pourc_preci(s, s->conv));
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	ft_strdel(&s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = ft_strdup(s->format);
	ft_strdel(&s->format);
	s->format = ft_strsub(value, s->end, ft_strlen(value) - s->end);
	ft_strdel(&value);
	ft_strdel(&s->print);
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	s->beg = 0;
	s->q = 0;
	initparcer(&(*s));
	return (0);
}
