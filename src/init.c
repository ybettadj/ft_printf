/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 01:58:55 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/24 01:58:57 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void 	initstru2(struct s_stru *s)
{
	s->ups = 0;
	s->p = 0;
	s->d = 0;
	s->upd = 0;
	s->i = 0;
	s->o = 0;
	s->upo = 0;
	s->u = 0;
	s->upu = 0;
	s->x = 0;
	s->upx = 0;
	s->c = 0;
	s->upc = 0;
	s->pourc = 0;
	s->valid = 0;
	s->ppp = 0;
	s->q = 0;
}

struct s_stru		initstru(const char *format)
{
	struct	s_stru s;

	s.print = ft_strnew(ft_strlen(format));
	s.numconv = 0;
	s.numconv2 = 0;
	s.beg = 0;
	s.end = 0;
	s.bs0 = 0;
	s.diese = 0;
	s.zero = 0;
	s.less = 0;
	s.plus = 0;
	s.hh = 0;
	s.h = 0;
	s.l = 0;
	s.ll = 0;
	s.j = 0;
	s.z = 0;
	s.width = 0;
	s.preci = 0;
	s.space = 0;
	s.s = 0;
	initstru2(&s);
	return (s);
}

void		initparcer2(struct s_stru *s)
{
	s->i = 0;
	s->o = 0;
	s->upo = 0;
	s->u = 0;
	s->upu = 0;
	s->x = 0;
	s->upx = 0;
	s->c = 0;
	s->upc = 0;
	s->pourc = 0;
	s->ppp = 0;
}

void		initparcer(struct s_stru *s)
{
	s->numconv = 0;
	s->numconv2 = 0;
	s->diese = 0;
	s->zero = 0;
	s->less = 0;
	s->plus = 0;
	s->hh = 0;
	s->h = 0;
	s->l = 0;
	s->ll = 0;
	s->j = 0;
	s->z = 0;
	s->width = 0;
	s->preci = 0;
	s->space = 0;
	s->s = 0;
	s->ups = 0;
	s->p = 0;
	s->d = 0;
	s->upd = 0;
	initparcer2(&(*s));
}

void		initmodif(struct s_stru *s)
{
	s->hh = 0;
	s->h = 0;
	s->l = 0;
	s->ll = 0;
	s->j = 0;
	s->z = 0;
}
