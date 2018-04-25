/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 06:28:10 by ybettadj          #+#    #+#             */
/*   Updated: 2018/04/25 06:28:12 by ybettadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int		conv_hex_p(intptr_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base_p(intptr_t *n, intptr_t base)
{
	intptr_t		tmpn;
	int				i;
	char			*str;

	i = 0;
	tmpn = *n;
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
		tmpn = *n % base;
		str[i] = conv_hex_p(tmpn);
		*n /= base;
		i--;
	}
	return (str);
}
