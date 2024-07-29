/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:42:40 by dtanski           #+#    #+#             */
/*   Updated: 2024/05/05 13:23:01 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *str)
{
	int	count;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (str[count])
	{
		print_char((int)str[count]);
		count++;
	}
	return (count);
}
