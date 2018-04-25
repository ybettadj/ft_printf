/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:29:38 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 02:30:11 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*negdesac(struct s_stru *s)
{
	int		i;
	int		k;
	char	*str;

	i = 1;
	k = 0;
	str = ft_strnew(ft_strlen(s->conv) + 2);
	str[0] = '-';
	while (s->conv[k])
		str[i++] = s->conv[k++];
	ft_strdel(&s->conv);
	return (str);
}

char	*plus_d(struct s_stru *s, int neg, int *plus)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (neg == 0 && s->plus != 0)
	{
		tmp = ft_strnew(ft_strlen(s->conv) + 2);
		tmp[0] = '+';
		str = ft_strjoin(tmp, s->conv);
		ft_strdel(&tmp);
		s->width++;
		*plus += 1;
		ft_strdel(&s->conv);
		return (str);
	}
	return (s->conv);
}

char	*negactif(struct s_stru *s)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 1;
	str = ft_strnew(ft_strlen(s->conv));
	while (s->conv[k])
		str[i++] = s->conv[k++];
	ft_strdel(&s->conv);
	return (str);
}

char	*d_space(struct s_stru *s)
{
	int		i;
	int		k;
	char	*str;
	char	*tmp;

	i = 0;
	k = 1;
	tmp = NULL;
	tmp = ft_strnew(ft_strlen(s->conv) + 2);
	tmp[0] = ' ';
	str = ft_strjoin(tmp, s->conv);
	ft_strdel(&tmp);
	ft_strdel(&s->conv);
	return (str);
}
