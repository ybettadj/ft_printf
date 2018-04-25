/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 08:09:19 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 08:09:21 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	x_preci2(struct s_stru *s, char *s1, char *s2)
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

char	*x_preci(struct s_stru *s, char *s1)
{
	char *s2;

	if (!(s2 = ft_strnew(sizeof(s2) * s->preci + 4)))
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
		return(s1);
	}
	if (s->preci != 0 && s->preci > ft_strlen(s1))
	{
		x_preci2(&(*s), &(*s1), &(*s2));
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}
