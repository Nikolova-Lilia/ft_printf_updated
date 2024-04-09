/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:30 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//the actual printf below. First part checks the string and stops on
//every char to see if it's a placeholder & counts the length
//else handles everything that is a simple text. ex: "Hello world";

int	ft_printf(const char	*s, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_placeholder(s[i], &args, &length);
			i++;
		}
		else
		{
			ft_putchar_length((char)s[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}

//checks for %c,prints & counts the length
//checks for %s, prints & counts the length
//checks for %p, prints & counts the length
//allocates space and returns string
//checks for %d or %i, prints & counts the length
//build on recursion this time insted of itoa
// checks for %x & %X, prints & counts the length
//allocates space and returns string
//for the case %%, prints the second %

void	ft_check_placeholder(const char s, va_list *args, int *length)
{
	if (s == 'c')
		ft_putchar_length(va_arg(*args, int), length);
	else if (s == 's')
		ft_putchar_str(va_arg(*args, char *), length);
	else if (s == 'p')
		ft_putchar_pointer(va_arg(*args, unsigned long), length);
	else if (s == 'd' || s == 'i')
		ft_putnbr_int(va_arg(*args, int), length);
	else if (s == 'u')
		ft_putnbr_unsgint(va_arg(*args, unsigned int), length);
	else if (s == 'x' || s == 'X')
		ft_putnbr_hex(s, va_arg(*args, unsigned int), length);
	else if (s == '%')
		ft_putchar_length('%', length);
}
