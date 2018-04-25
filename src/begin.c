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

void		begin2(struct s_stru *s, va_list ap)
{
	if (s->u != 0)
		u_conv(&(*s), ap);
	else if (s->upu != 0)
	{
		initmodif(&(*s));
		s->l++;
		u_conv(&(*s), ap);
	}
	else if (s->o != 0)
		o_conv(&(*s), ap);
	else if (s->upo != 0)
	{
		initmodif(&(*s));
		s->l++;
		o_conv(&(*s), ap);
	}
}

void		begin3(struct s_stru *s, va_list ap)
{
	if (s->c != 0)
	{
		if (s->l != 0)
			s->beg++;
		else
			c_conv(&(*s), ap);
	}
	else if (s->p != 0)
		p_conv(&(*s), ap);
	else if (s->ups != 0)
		s->beg++;
	else if (s->upc != 0)
		s->beg++;
}

int			begin(struct s_stru *s, va_list ap)
{
	if (s->s != 0)
	{
		if (s->l != 0)
			s->beg++;
		else
			s_conv(&(*s), ap);
	}
	else if (s->pourc != 0)
		pourc_conv(&(*s), ap);
	else if (s->d != 0 || s->i != 0)
		d_conv(&(*s), ap);
	else if (s->upd != 0)
	{
		initmodif(&(*s));
		s->l++;
		d_conv(&(*s), ap);
	}
	else if (s->x != 0)
		x_conv(&(*s), ap);
	else if (s->upx != 0)
		x_conv(&(*s), ap);
	begin2(&(*s), ap);
	begin3(&(*s), ap);
	return (0);
}
