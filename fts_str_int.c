/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_str_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:34:16 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//function to print the characters & keep track of the length

void	ft_putchar_length(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

//function to handle the case of passing %s & keep track of the length

void	ft_putchar_str(char *args, int *length)
{
	int	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_length(args[i], length);
		i++;
	}
}

//recursion for printing the ints

void	ft_putnbr_int(int d, int *length)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (d < 0)
	{
		ft_putchar_length('-', length);
		ft_putnbr_int((d * (-1)), length);
	}
	else
	{
		if (d > 9)
			ft_putnbr_int((d / 10), length);
		ft_putchar_length((d % 10 + '0'), length);
	}
}

//recursion for printing the unsigned int

void	ft_putnbr_unsgint(unsigned int u, int *length)
{
	if (u >= 10)
		ft_putnbr_unsgint((u / 10), length);
	ft_putchar_length((u % 10 + '0'), length);
}
