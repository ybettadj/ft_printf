/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourc_conv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 07:20:05 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 07:20:07 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*pourc_preci(struct s_stru *s, char *s1)
{
	char *s2;

	if (!(s2 = ft_strnew(sizeof(s2) * ft_strlen(s1) + 1)))
		return (0);
	if (s->preci == 0 || (s->preci != 0 && s->preci >= ft_strlen(s1)))
	{
		ft_strdel(&s2);
		return (s1);
	}
	if (s->preci != 0 && s->preci < ft_strlen(s1))
	{
		s2 = ft_strncpy(s2, s1, s->preci);
		ft_strdel(&s->conv);
		return (s2);
	}
	ft_strdel(&s2);
	return (s1);
}
