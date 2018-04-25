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

void	x_width2(struct s_stru *s, char *s1, char *s2, int z)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s->diese != 0 && z != 1)
	{
		s2[0] = '0';
		s2[1] = 'x';
		k = 2;
		while (s1[i])
			s2[k++] = s1[i++];
		while (k < s->width)
			s2[k++] = ' ';
	}
	else
	{
		while (s1[i])
			s2[k++] = s1[i++];
		while (k < s->width)
			s2[k++] = ' ';
	}
	s2[k] = '\0';
}

void	x_width3(struct s_stru *s, char *s1, char *s2, int z)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s->diese != 0 && z != 1)
	{
		s2[0] = '0';
		s2[1] = 'x';
		k = 2;
		while (k < s->width - ft_strlen(s1))
			s2[k++] = '0';
		while (s1[i])
			s2[k++] = s1[i++];
	}
	else
	{
		while (k < s->width - ft_strlen(s1))
			s2[k++] = '0';
		while (s1[i])
			s2[k++] = s1[i++];
	}
	s2[k] = '\0';
}

void	x_width4(struct s_stru *s, char *s1, char *s2, int z)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (s->diese != 0 && z != 1)
	{
		while (k < s->width - ft_strlen(s1) - 2)
			s2[k++] = ' ';
		s2[k] = '0';
		s2[k + 1] = 'x';
		k = k + 2;
	}
	else
	{
		while (k < s->width - ft_strlen(s1))
			s2[k++] = ' ';
	}
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
}

void	x_width5(struct s_stru *s, char *s1, char *s2, int z)
{
	if (s->less != 0)
		x_width2(&(*s), &(*s1), &(*s2), z);
	else if (s->zero != 0 && s->less == 0 && s->ppp != 1)
		x_width3(&(*s), &(*s1), &(*s2), z);
	else
		x_width4(&(*s), &(*s1), &(*s2), z);
}

char	*x_width(struct s_stru *s, char *s1, int z)
{
	char *s2;
	char *tmp;

	tmp = NULL;
	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (s->width == 0 || (s->width != 0 && s->width <= ft_strlen(s1)))
	{
		if (s->diese != 0 && z != 1)
		{
			s2[0] = '0';
			s2[1] = 'x';
		}
		tmp = ft_strjoin(s2, s1);
		ft_strdel(&s2);
		return (tmp);
	}
	if (s->width != 0 && s->width > ft_strlen(s1))
	{
		x_width5(&(*s), &(*s1), &(*s2), z);
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}
