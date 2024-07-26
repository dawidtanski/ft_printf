/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:51:44 by dtanski           #+#    #+#             */
/*   Updated: 2024/05/05 12:51:46 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		print_char(int c);
int		print_str(char *str);
int		put_pointer(unsigned long long ptr);
int		print_format(char specifier, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_itoa_base(int n);
int		print_unsigned(unsigned int n);
int		print_hexa(unsigned int n);
int		print_capital_hexa(unsigned int n);
#endif
