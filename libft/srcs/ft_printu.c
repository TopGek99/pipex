/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:27:56 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 18:27:58 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_to_str(unsigned int num, char *dest)
{
	unsigned int	nb_arr[10];
	unsigned int	temp;
	unsigned int	count;
	unsigned int	reverse_count;

	if (num == 0)
	{
		*dest = '0';
		return (1);
	}
	count = 0;
	while (num > 0)
	{
		temp = num % 10;
		num /= 10;
		nb_arr[count++] = temp;
	}
	reverse_count = 0;
	while (count > 0)
		dest[--count] = nb_arr[reverse_count++] + '0';
	return (reverse_count);
}

size_t	ft_printu(unsigned int d)
{
	char	nb_str[10];
	size_t	len;

	len = ft_u_to_str(d, nb_str);
	write(1, nb_str, len);
	return (len);
}
