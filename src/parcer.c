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
void	parcerlarg2(struct s_stru *s, int *x)
{
	char *str;
	int k;

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

void	parcerlarg(struct s_stru *s)
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

void	parcerpreci2(struct s_stru *s, int *x)
{
	char *str;
	int k;

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


void	parcerpreci(struct s_stru *s)
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

void	parcerflag2_2(struct s_stru *s)
{
	s->end += 1;
	s->hh++;
}

void	parcerflag2(struct s_stru *s)
{
	if (s->format[s->end] && ((s->format[s->end] == 'h' &&
		s->format[s->end + 1] == 'h') || s->format[s->end] == 'h' ||
		s->format[s->end] == 'l' || (s->format[s->end] == 'l' &&
		s->format[s->end + 1] == 'l') || s->format[s->end] == 'j' ||
		s->format[s->end] == 'z'))
	{
		if (s->format[s->end] == 'h' && s->format[s->end + 1] == 'h')
			parcerflag2_2(&(*s));
		else if (s->format[s->end] == 'l' && s->format[s->end + 1] == 'l')
		{
			s->end += 1;
			s->ll++;
		}
		else if (s->format[s->end] == 'h')
			s->h++;
		else if (s->format[s->end] == 'l')
			s->l++;
		else if (s->format[s->end] == 'j')
			s->j++;
		else if (s->format[s->end] == 'z')
			s->z++;
		s->end += 1;
		valid_flag(&(*s));
	}
}


void	parcerconv2(struct s_stru *s)
{
	if (s->format[s->end] == 'i')
		s->i++;
	else if (s->format[s->end] == 'o')
		s->o++;
	else if (s->format[s->end] == 'O')
		s->upo++;
	else if (s->format[s->end] == 'u')
		s->u++;
	else if (s->format[s->end] == 'U')
		s->upu++;
	else if (s->format[s->end] == 'x')
		s->x++;
	else if (s->format[s->end] == 'X')
		s->upx++;
	else if (s->format[s->end] == 'c')
		s->c++;
	else if (s->format[s->end] == 'C')
		s->upc++;
	else if (s->format[s->end] == 's')
		s->s++;
}

void	parcerconv(struct s_stru *s)
{
	if (s->format[s->end] && ((s->format[s->end] == 's' || s->format[s->end] == 'S' ||
		s->format[s->end] == 'p' || s->format[s->end] == 'd' || s->format[s->end] == 'D' || s->format[s->end]
		== 'i' || s->format[s->end] == 'o' || s->format[s->end] == 'O' || s->format[s->end] == 'u' ||
		s->format[s->end] == 'U' || s->format[s->end] == 'x' || s->format[s->end] == 'X' || s->format[s->end]
		== 'c' || s->format[s->end] == 'C' || s->format[s->end] == '%')))
	{
		if (s->format[s->end] == '%')
			s->pourc++;
		else if (s->format[s->end] == 'S')
			s->ups++;
		else if (s->format[s->end] == 'p')
			s->p++;
		else if (s->format[s->end] == 'd')
			s->d++;
		else if (s->format[s->end] == 'D')
			s->upd++;
		parcerconv2(&(*s));
		s->end += 1;
	}
	else
		s->valid++;
}
