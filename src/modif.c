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

static void	ft_neg_n_count2(intmax_t *i, intmax_t *n, intmax_t *y)
{
	intmax_t		count;

	count = *n;
	if (*n < 0)
	{
		*n = *n * (-1);
		*y = 1;
	}
	while (count != 0)
	{
		count = count / 10;
		*i = *i + 1;
	}
}

char		*ft_itoa2(intmax_t n)
{
	intmax_t		i;
	intmax_t		y;
	int		p;
	char	*tab;

	i = 0;
	y = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	ft_neg_n_count2(&i, &n, &y);
	tab = ft_strnew(i + y + 1);
	while (i != 0)
	{
		p = n % 10;
		if (p < 0)
			p = p * -1;
		tab[i + y - 1] = p + '0';
		i--;
		n = n / 10;
	}
	if (y == 1)
		tab[0] = '-';
	return (tab);
}


void	modif2(struct s_stru *s, va_list ap)
{
	if (s->hh != 0)
		s->numconv = (char)va_arg(ap, intmax_t);
	else if (s->h != 0)
		s->numconv = (short int)va_arg(ap, intmax_t);
	else if (s->l != 0)
		s->numconv = (long int)va_arg(ap, intmax_t);
	else if (s->ll != 0)
		s->numconv = (long long int)va_arg(ap, intmax_t);
	else if (s->j != 0)
		s->numconv = va_arg(ap, intmax_t);
	else if (s->z != 0)
		s->numconv = (size_t)va_arg(ap, intmax_t);
	else
		s->numconv = (int)va_arg(ap, intmax_t);
}

void	modifunsigned(struct s_stru *s, va_list ap)
{
	if (s->hh != 0)
		s->numconv2 = (unsigned char)va_arg(ap, uintmax_t);
	else if (s->h != 0)
		s->numconv2 = (unsigned short int)va_arg(ap, uintmax_t);
	else if (s->l != 0)
		s->numconv2 = (unsigned long int)va_arg(ap, uintmax_t);
	else if (s->ll != 0)
		s->numconv2 = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (s->j != 0)
		s->numconv2 = va_arg(ap, uintmax_t);
	else if (s->z != 0)
		s->numconv2 = (size_t)va_arg(ap, uintmax_t);
	else
		s->numconv2 = (unsigned int)va_arg(ap, uintmax_t);
}

char	*modif(struct s_stru *s, va_list ap)
{
	char *str;

	modif2(&(*s), ap);
	str = ft_itoa2(s->numconv);
	return (str);
}
