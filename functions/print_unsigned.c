/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:30:28 by dtanski           #+#    #+#             */
/*   Updated: 2024/05/06 09:08:41 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	ft_get_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_res_un(int size, int offset, unsigned int n, char *res)
{
	int	digit;

	while (size > offset)
	{
		digit = n % 10;
		res[size - 1] = digit + '0';
		n /= 10;
		size--;
	}
}

int	print_unsigned(unsigned int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_get_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	ft_fill_res_un(size, offset, n, res);
	res[size] = '\0';
	print_str(res);
	free(res);
	return (size);
}
