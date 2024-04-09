/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:29:05 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memcpy() function copies n bytes
from memory area src to memory area dest.
The memory areas must not overlap.
Use memmove() if the memory areas do overlap.*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
