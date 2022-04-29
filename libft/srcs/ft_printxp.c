/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:27:56 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 18:27:58 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hexlen(unsigned long d)
{
	int	len;

	len = 0;
	while (d > 0)
	{
		d /= 16;
		len++;
	}
	return (len);
}

char	*ft_dec_to_hex(unsigned long d, char c)
{
	char			*hex;
	unsigned long	mod;
	int				i;

	i = ft_hexlen(d);
	hex = malloc(sizeof(char) * (i + 1));
	hex[i--] = '\0';
	while (i >= 0 && d > 0)
	{
		mod = d % 16;
		if (mod < 10)
			hex[i] = mod + '0';
		else if (c == 'X')
			hex[i] = mod + '7';
		else
			hex[i] = mod + 'W';
		d /= 16;
		i--;
	}
	return (hex);
}

size_t	ft_printp(unsigned long p)
{
	size_t	len;
	char	*hex;

	if (p == 0)
		return (ft_printf("(nil)"));
	hex = ft_dec_to_hex(p, 'p');
	len = ft_printf("0x%s", hex);
	free(hex);
	return (len);
}

size_t	ft_printx(unsigned int p, char flag)
{
	size_t	len;
	char	*hex;

	if (p == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = ft_dec_to_hex(p, flag);
	len = ft_strlen(hex);
	write(1, hex, len);
	free(hex);
	return (len);
}
