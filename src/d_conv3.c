/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 04:56:09 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 04:56:11 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	d_preci_cond(struct s_stru *s, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < s->preci - ft_strlen(s->conv))
	{
		s2[i] = '0';
		i++;
	}
	while (s->conv[k])
	{
		s2[i] = s->conv[k];
		i++;
		k++;
	}
	s2[i] = '\0';
	ft_strdel(&s->conv);
}

char	*d_preci(struct s_stru *s, char *s1)
{
	char	*s2;

	if (!(s2 = ft_strnew(sizeof(s2) * s->preci + 2)))
		return (0);
	if (s1[0] == '0' && s->preci == 0 && s->ppp == 1)
	{
		s2[0] = '\0';
		ft_strdel(&s->conv);
		return (s2);
	}
	if (s->preci == 0 || (s->preci != 0 && s->preci <= ft_strlen(s1)))
	{
		ft_strdel(&s2);
		return (s1);
	}
	if (s->preci != 0 && s->preci > ft_strlen(s1))
	{
		d_preci_cond(&(*s), &(*s2));
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}

void	d_width2(struct s_stru *s, char *s1, char *s2, int *neg)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (*neg != 0)
	{
		s1 = negdesac(&(*s));
		s->width++;
		*neg = 0;
	}
	while (s1[i])
		s2[k++] = s1[i++];
	while (k < s->width)
		s2[k++] = ' ';
	s2[k] = '\0';
}

void	d_width3(struct s_stru *s, char *s1, char *s2)
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

void	d_width4(struct s_stru *s, char **s1, int *neg)
{
	*s1 = negdesac(&(*s));
	s->width++;
	*neg = 0;
}
