/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:10:01 by ybettadj          #+#    #+#             */
/*   Updated: 2018/03/06 17:10:04 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			before_pourc(struct s_stru *s, va_list ap)
{
	while (s->format[s->beg] != '%' && s->format[s->beg] != '\0')
	{
		s->print[s->q] = s->format[s->beg];
		s->beg += 1;
		s->q += 1;
	}
	if (s->format[s->beg] == '%')
	{
		s->end = s->beg;
		after_pourc(&(*s), ap);
	}
	if (s->format[s->beg] == '\0')
		return (0);
	return (1);
}

void		invalid(struct s_stru *s, va_list ap)
{
	char *tmp;

	tmp = NULL;
	ft_putstr(s->print);
	s->retour = s->retour + ft_strlen(s->print);
	s->conv = ft_strnew(1);
	s->conv = void_width(&(*s), s->conv);
	ft_putstr(s->conv);
	tmp = s->format;
	s->format = ft_strsub(tmp, s->end, ft_strlen(tmp));
	ft_strdel(&tmp);
	tmp = s->print;
	s->print = ft_strnew(ft_strlen(s->format) + 3);
	ft_strdel(&tmp);
	s->beg = 0;
	s->q = 0;
	s->retour = s->retour + ft_strlen(s->conv);
	ft_strdel(&s->conv);
	initparcer(&(*s));
}

void		after_pourc(struct s_stru *s, va_list ap)
{
	s->end++;
	parcerflag1(&(*s));
	parcerlarg(&(*s));
	parcerpreci(&(*s));
	parcerflag2(&(*s));
	parcerconv(&(*s));
	if (s->valid == 0)
		begin(&(*s), ap);
	else if (s->width > 0)
		invalid(&(*s), ap);
	else
	{
		s->beg++;
		while (s->format[s->beg] == ' ')
			s->beg += 1;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_stru		s;
	int			i;
	int			x;
	char		*tmp;

	i = 0;
	x = 0;
	s = initstru(format);
	s.format = ft_strdup(format);
	s.mark = 0;
	s.retour = 0;
	s.counter = 0;
	va_start(ap, format);
	while ((before_pourc(&s, ap) != 0))
		i++;
	ft_putstr(s.print);
	va_end(ap);
	s.retour = s.retour + ft_strlen(s.print);
	ft_strdel(&s.print);
	ft_strdel(&s.format);
	return (s.retour);
}
