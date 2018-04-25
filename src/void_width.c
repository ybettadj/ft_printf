/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:26:54 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 02:26:56 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char		*void_width4(struct s_stru *s, char *s1, char *s2, int k)
{
	int i;

	i = 0;
	while (k + 1 < s->width - ft_strlen(s1))
		s2[k++] = ' ';
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
	return (s2);
}

char		*void_width3(struct s_stru *s, char *s1, char *s2, int k)
{
	int i;

	i = 0;
	while (k + 1 < s->width - ft_strlen(s1))
		s2[k++] = '0';
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = '\0';
	return (s2);
}

char		*void_width2(struct s_stru *s, char *s1, char *s2, int k)
{
	int i;

	i = 0;
	while (s1[i])
		s2[k++] = s1[i++];
	s2[k] = s->format[s->end];
	k += 1;
	while (k < s->width)
		s2[k++] = ' ';
	s2[k] = '\0';
	s->end += 1;
	return (s2);
}

char		*void_width(struct s_stru *s, char *s1)
{
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(s2 = ft_strnew(sizeof(s2) * (s->width + 2))))
		return (0);
	if (s->less != 0)
		s2 = void_width2(&(*s), s1, s2, k);
	else if (s->zero != 0)
		s2 = void_width3(&(*s), s1, s2, k);
	else
		s2 = void_width3(&(*s), s1, s2, k);
	return (s2);
}
