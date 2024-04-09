/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:16 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*ft_itoa() - Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/
static char	*ft_str_return(char *str, int t, int sign, long long x)
{
	int	v;

	v = 0;
	str[t + sign] = '\0';
	if (x == 0)
		str[0] = '0';
	else
	{
		while (x > 0 && t >= 0)
		{
			v = x % 10;
			str[t - 1 + sign] = v + '0';
			t--;
			x = x / 10;
		}
	}
	if (sign > 0)
		str[0] = '-';
	return (str);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	long long	result;
	int			t;
	int			sign;
	char		*str;
	long long	x;

	x = n;
	sign = ft_sign(n);
	if (x < 0)
		x = x * (-1);
	result = x;
	t = 0;
	if (result == 0)
		t = 1;
	while (result > 0)
	{
		result = result / 10;
		t++;
	}
	str = (char *)malloc((t + 1 + sign) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_str_return(str, t, sign, x));
}
