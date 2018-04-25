/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 06:08:38 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 06:08:41 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*o_diese(struct s_stru *s, char *s1)
{
	char *s2;
	int i;
	int k;

	i = 0;
	k = 0;
	if (!(s2 = ft_strnew(sizeof(s2) * s->preci + 4)))
			return (0);
	if (s->conv[0] == '0' && s->conv[1] == '\0' )
		s2 = ft_strjoin(s2, s1);
	else
	{
		s2[0] = '0';
		s2 = ft_strjoin(s2, s1);
	}
	ft_strdel(&s->conv);
	return (s2);
}

void 	o_width2(struct s_stru *s, char *s1, char *s2)
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

void 	o_width3(struct s_stru *s, char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < s->width - ft_strlen(s1))
		s2[k++] = '0';
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
}

void 	o_width4(struct s_stru *s, char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < s->width - ft_strlen(s1))
		s2[k++] = ' ';
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
}

char	*o_width(struct s_stru *s, char *s1)
{
	char *s2;

	s2 = NULL;
	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (s->width == 0 || (s->width != 0 && s->width <= ft_strlen(s1)))
	{
		ft_strdel(&s2);
		return (s1);
	}
	if (s->width != 0 && s->width > ft_strlen(s1))
	{
		if (s->less != 0)
			o_width2(&(*s), &(*s1), &(*s2));
		else if (s->zero != 0 && s->less == 0 && s->ppp != 1)
			o_width3(&(*s), &(*s1), &(*s2));
		else
			o_width4(&(*s), &(*s1), &(*s2));
		ft_strdel(&s->conv);
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}
