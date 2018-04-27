/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:47:08 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/28 04:47:10 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*s_preci(struct s_stru *s, char *s1)
{
	char *s2;

	if (s->ppp == 0 || (s->preci != 0 && s->preci >= ft_strlen(s1)))
		return (s1);
	if (s->ppp != 0 && s->preci < ft_strlen(s1))
	{
		if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
			return (0);
		s2 = ft_strncpy(s2, s1, s->preci);
		return (s2);
	}
	return (s1);
}

void	s_width3(struct s_stru *s, char *s1, char *s2)
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

void	s_width2(struct s_stru *s, char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s->less != 0)
		s_width3(&(*s), &(*s1), &(*s2));
	else if (s->zero != 0 && s->preci == 0 && s->less == 0)
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

char	*s_width(struct s_stru *s, char *s1)
{
	char *s2;

	if (s->width == 0 || (s->width != 0 && s->width <= ft_strlen(s1)))
		return (s1);
	if (s->width != 0 && s->width > ft_strlen(s1))
	{
		if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
			return (0);
		s_width2(&(*s), &(*s1), &(*s2));
		return (s2);
	}
	return (s1);
}

int		s_conv(struct s_stru *s, va_list ap)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	ft_putstr(s->print);
	s->conv = va_arg(ap, char *);
	if (s->conv == NULL)
		s->conv = "(null)";
	s->conv = s_preci(s, s->conv);
	s->conv = s_width(s, s->conv);
	ft_putstr(s->conv);
	value = ft_strjoin(s->print, s->conv);
	s->retour = s->retour + ft_strlen(value);
	ft_strdel(&value);
	value = s->format;
	s->format = ft_strsub(s->format, s->end, ft_strlen(s->format) - s->end);
	ft_strdel(&value);
	value = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&value);
	s->beg = 0;
	s->q = 0;
	initparcer(&(*s));
	return (0);
}
