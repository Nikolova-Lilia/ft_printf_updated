/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_hex_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:34:13 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//checks 'x' || 'X' for the base, if it has to print lower or upper 

char	*ft_check_x(char s)
{
	if (s == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

//checks the size of the number and allocates space in a string for it.

char	*ft_allocates_str(unsigned long x)
{
	int	j;

	j = 0;
	while (x > 0)
	{
		x = x / 16;
		j++;
	}
	return ((char *)malloc((j) * sizeof(char)));
}

//function for printing the hexadecimal

int	ft_putnbr_hex(char s, unsigned long x, int *length)
{
	char	*str_x;
	int		j;
	char	*base_character_x;

	base_character_x = ft_check_x(s);
	if (x == 0)
	{
		ft_putchar_length('0', length);
		return (-1);
	}
	str_x = ft_allocates_str(x);
	if (!str_x)
		return (*length);
	j = 0;
	while (x != 0)
	{
		str_x[j] = base_character_x[x % 16];
		x = x / 16;
		j++;
	}
	while (j > 0)
		ft_putchar_length(str_x[--j], length);
	free(str_x);
	return (*length);
}
//function to print the %p pointer

void	ft_putchar_pointer(unsigned long p, int *length)
{
	if (!p)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	ft_putnbr_hex('x', p, length);
}
