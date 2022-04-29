/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:58:07 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 15:59:18 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_det_type(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_printc(va_arg(args, int)));
	if (flag == 's')
		return (ft_prints(va_arg(args, char *)));
	if (flag == 'p')
		return (ft_printp(va_arg(args, unsigned long)));
	if (flag == 'd' || flag == 'i')
		return (ft_printdi(va_arg(args, int)));
	if (flag == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	if (flag == 'x' || flag == 'X')
		return (ft_printx(va_arg(args, unsigned int), flag));
	if (flag == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		print_amount;
	va_list	args;

	i = 0;
	print_amount = 0;
	va_start(args, s);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			write(1, &s[i++], 1);
			print_amount++;
		}
		if (!s[i])
			break ;
		print_amount += ft_det_type(s[i + 1], args);
		i += 2;
	}
	va_end(args);
	return (print_amount);
}
