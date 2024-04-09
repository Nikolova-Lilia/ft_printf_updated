/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:08:30 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memset() function fills the first n bytes
of the memory area pointed to by s with the constant byte c.*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*p;
	size_t				i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p++ = (unsigned char)c;
		i++;
	}
	return (s);
}
