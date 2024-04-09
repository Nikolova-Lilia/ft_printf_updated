/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:16:24 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memchr() function scans the initial
n bytes of the memory area poined to by s
for the first istance of c.
Both c and the bytes of the memory area
poited to by s are interpreted as unsigned char.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*find;

	p = (unsigned char *)s;
	find = NULL;
	while ((s != NULL) && (n-- > 0))
	{
		if (*p != (unsigned char)c)
		{
			p++;
		}
		else
		{
			find = p;
			break ;
		}
	}
	return (find);
}
