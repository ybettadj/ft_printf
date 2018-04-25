/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifhelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 05:13:58 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 05:14:00 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int		conv_hex(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(uintmax_t n, uintmax_t base)
{
	uintmax_t		tmpn;
	int				i;
	char			*str;

	i = 0;
	tmpn = n;
	while (tmpn >= base)
	{
		tmpn /= base;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmpn = n % base;
		str[i] = conv_hex(tmpn);
		n /= base;
		i--;
	}
	return (str);
}

char	*x_modif(struct s_stru *s, va_list ap, int *z)
{
	char *str;

	modifunsigned(&(*s), ap);
	if (s->numconv2 == 0)
		*z = 1;
	str = ft_itoa_base(s->numconv2, 16);
	return (str);
}

char	*u_modif(struct s_stru *s, va_list ap)
{
	char *str;

	modifunsigned(&(*s), ap);
	str = ft_itoa_base(s->numconv2, 10);
	return (str);
}

char	*o_modif(struct s_stru *s, va_list ap)
{
	char *str;

	modifunsigned(&(*s), ap);
	str = ft_itoa_base(s->numconv2, 8);
	return (str);
}
