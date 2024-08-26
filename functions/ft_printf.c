/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:29:58 by dtanski           #+#    #+#             */
/*   Updated: 2024/05/06 09:40:59 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == '%')
		return (print_char('%'));
	else if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_itoa_base(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count += print_capital_hexa(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_hexa(va_arg(ap, unsigned int));
	else if (specifier == 'p')
		count += put_pointer(va_arg(ap, unsigned long long));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	// void a;

	// printf("The number in HEX %X\n",23445);
	// printf("The number in hex %x",23445);
	// ft_printf("The number in HEX %X\n",23445);
	// ft_printf("The number in hex %x",23445);

// 	printf("The number in hex %x\n",-23445);
// 	printf("The number in hex %x",23445);
// 	ft_printf("The number in hex %x\n",-23445);
// 	ft_printf("The number in hex %x",23445);

// 	// a = ;
// 	// ft_printf ("This is the test %x \n", 204234);
// 	// printf ("This is the test %x", 204234);
// 	// ft_printf ("This is the test %p \n", &a);
// 	// write (1,'\n',1);
// 	// printf ("This is the test %p", &a);
// 	return (0);
// }