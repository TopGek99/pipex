/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:58:18 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 15:58:21 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
size_t	ft_printc(int c);
size_t	ft_prints(char *s);
size_t	ft_printp(unsigned long p);
size_t	ft_printdi(int d);
size_t	ft_printu(unsigned int d);
size_t	ft_printx(unsigned int p, char flag);

#endif
