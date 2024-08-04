/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:25:38 by dtanski           #+#    #+#             */
/*   Updated: 2024/05/06 09:40:27 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_get_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	ft_fill_res(int size, int offset, unsigned int n, char *res)
{
	int	digit;

    while (size > offset)
    {
        digit = n % 16;
        if (digit < 10)
            res[size - 1] = digit + '0';
        else
            res[size - 1] = (digit - 10) + 'a';
        n /= 16;
        size--;
    }
}

int	print_hexa(unsigned int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_get_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_res(size, offset, n, res);
	res[size] = '\0';
	print_str(res);
	free(res);
	return (size);
}
