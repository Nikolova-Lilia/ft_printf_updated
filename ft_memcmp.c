/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:28:45 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memcmp() function returns an integer less than,
equal to, or greater than zero if the first n bytes
of s1 is found, respectively, to be less than, to match,
or be greater than the first n bytes of s2.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*p1;

	p = (unsigned char *)s1;
	p1 = (unsigned char *)s2;
	if (s1 == s2)
	{
		return (0);
	}
	while (n > 0)
	{
		if (*p != *p1)
		{
			if (*p > *p1)
				return (*p - *p1);
			else
				return (-(*p1 - *p));
		}
		n--;
		p++;
		p1++;
	}
	return (0);
}
