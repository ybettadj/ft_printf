/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:01:23 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/25 04:01:26 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		parcerflag1(struct s_stru *s)
{
	while (s->format[s->end] && (s->format[s->end] == ' ' || s->format[s->end]
		== '#' || s->format[s->end] == '0' || s->format[s->end] == '-' ||
		s->format[s->end] == '+'))
	{
		if (s->format[s->end] && s->format[s->end] == ' ')
			s->space++;
		if (s->format[s->end] && s->format[s->end] == '#')
			s->diese++;
		if (s->format[s->end] && s->format[s->end] == '0')
			s->zero++;
		if (s->format[s->end] && s->format[s->end] == '-')
			s->less++;
		if (s->format[s->end] && s->format[s->end] == '+')
			s->plus++;
		s->end += 1;
	}
}

void		parcerlarg2(struct s_stru *s, int *x)
{
	char	*str;
	int		k;

	k = 0;
	str = ft_strnew(*x + 1);
	while (*x > 0)
	{
		str[k++] = s->format[(s->end)++];
		*x = *x - 1;
	}
	s->width = ft_atoi(str);
	ft_strdel(&str);
}

void		parcerlarg(struct s_stru *s)
{
	int x;

	x = 0;
	if (s->format[s->end] && (s->format[s->end] == '1' || s->format[s->end]
		== '2' || s->format[s->end] == '3' || s->format[s->end] == '4' ||
		s->format[s->end] == '5' || s->format[s->end] == '6' ||
		s->format[s->end] == '7' || s->format[s->end] == '8' ||
		s->format[s->end] == '9'))
	{
		while (s->format[s->end] && (s->format[s->end] == '1' ||
			s->format[s->end] == '2' || s->format[s->end] == '3' ||
			s->format[s->end] == '4' || s->format[s->end] == '5' ||
			s->format[s->end] == '6' || s->format[s->end] == '7' ||
			s->format[s->end] == '8' || s->format[s->end] == '9' ||
			s->format[s->end] == '0'))
		{
			x++;
			s->end += 1;
		}
		s->end = s->end - x;
		parcerlarg2(&(*s), &x);
		valid_larg(&(*s));
	}
}

void		parcerpreci2(struct s_stru *s, int *x)
{
	char	*str;
	int		k;

	k = 0;
	str = ft_strnew(*x + 1);
	while (s->format[s->end] && (s->format[s->end] == '1' ||
		s->format[s->end] == '2' || s->format[s->end] == '3' ||
		s->format[s->end] == '4' || s->format[s->end] == '5' ||
		s->format[s->end] == '6' || s->format[s->end] == '7' ||
		s->format[s->end] == '8' || s->format[s->end] == '9' ||
		s->format[s->end] == '0'))
	{
		*x += 1;
		s->end += 1;
	}
	s->end = s->end - *x;
	while (*x > 0)
	{
		str[k++] = s->format[(s->end)++];
		*x = *x - 1;
	}
	s->preci = ft_atoi(str);
	ft_strdel(&str);
}

void		parcerpreci(struct s_stru *s)
{
	int x;

	x = 0;
	if (s->format[s->end] && s->format[s->end] == '.')
	{
		s->ppp = 1;
		s->end += 1;
		if (s->format[s->end] && (s->format[s->end] == '1' ||
			s->format[s->end] == '2' || s->format[s->end] == '3' ||
			s->format[s->end] == '4' || s->format[s->end] == '5' ||
			s->format[s->end] == '6' || s->format[s->end] == '7' ||
			s->format[s->end] == '8' || s->format[s->end] == '9' ||
			s->format[s->end] == '0'))
			parcerpreci2(&(*s), &x);
		valid_preci(&(*s));
	}
}
