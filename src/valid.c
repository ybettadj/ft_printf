/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 00:49:43 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/25 00:49:45 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		valid_larg(struct s_stru *s)
{
	if ((s->format[s->end] == '\0') || (s->format[s->end] != '.' &&
		(s->format[s->end] != 'h' && s->format[s->end + 1] != 'h') &&
		s->format[s->end] != 'h' && s->format[s->end] != 'l' &&
		(s->format[s->end] != 'l' && s->format[s->end + 1] != 'l') &&
		s->format[s->end] != 'j' && s->format[s->end] != 'z' &&
		s->format[s->end] != 's' && s->format[s->end] != 'S' &&
		s->format[s->end] != 'p' && s->format[s->end] != 'd' &&
		s->format[s->end] != 'D' && s->format[s->end] != 'i' &&
		s->format[s->end] != 'o' && s->format[s->end] != 'O' && 
		s->format[s->end] != 'u' && s->format[s->end] != 'U' &&
		s->format[s->end] != 'x' && s->format[s->end] != 'X' &&
		s->format[s->end] != 'c' && s->format[s->end] != 'C' &&
		s->format[s->end] != '%'))
		s->valid++;
}

void		valid_preci(struct s_stru *s)
{
	if ((s->format[s->end] == '\0') || (s->format[s->end] != 'C' &&
		(s->format[s->end] != 'h' && s->format[s->end + 1] != 'h') &&
		s->format[s->end] != 'h' && s->format[s->end] != 'l' &&
		(s->format[s->end] != 'l' && s->format[s->end + 1] != 'l') &&
		s->format[s->end] != 'j' && s->format[s->end] != 'z' &&
		s->format[s->end] != 's' && s->format[s->end] != 'S' &&
		s->format[s->end] != 'p' && s->format[s->end] != 'd' &&
		s->format[s->end] != 'D' && s->format[s->end] != 'i' &&
		s->format[s->end] != 'o' && s->format[s->end] != 'O' &&
		s->format[s->end] != 'u' && s->format[s->end] != 'U' &&
		s->format[s->end] != 'x' && s->format[s->end] != 'X' &&
		s->format[s->end] != 'c' && s->format[s->end] != '%'))
		s->valid++;
}

void		valid_flag(struct s_stru *s)
{
	if ((s->format[s->end] == '\0') || (s->format[s->end] != 's' &&
		s->format[s->end] != 'S' && s->format[s->end] != 'p' &&
		s->format[s->end] != 'd' && s->format[s->end] != 'D' &&
		s->format[s->end] != 'i' && s->format[s->end] != 'o' &&
		s->format[s->end] != 'O' && s->format[s->end] != 'u' &&
		s->format[s->end] != 'U' && s->format[s->end] != 'x' &&
		s->format[s->end] != 'X' && s->format[s->end] != 'c' &&
		s->format[s->end] != 'C' && s->format[s->end] != '%'))
		s->valid++;
}
