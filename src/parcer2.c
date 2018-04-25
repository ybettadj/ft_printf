/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 07:03:37 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 07:03:40 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

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
	if (s->format[s->end] && ((s->format[s->end] == 's' || s->format[s->end]
		== 'S' || s->format[s->end] == 'p' || s->format[s->end] == 'd' ||
		s->format[s->end] == 'D' || s->format[s->end] == 'i' ||
		s->format[s->end] == 'o' || s->format[s->end] == 'O' ||
		s->format[s->end] == 'u' || s->format[s->end] == 'U' ||
		s->format[s->end] == 'x' || s->format[s->end] == 'X' ||
		s->format[s->end] == 'c' || s->format[s->end] == 'C' ||
		s->format[s->end] == '%')))
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
