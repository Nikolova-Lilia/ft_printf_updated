/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:36:23 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The calloc() function allocates memory for an array
of nmemb elements of size bytes each and returns
a pointer to the allocated memory. The memory is
set to zero. If nmemb or size is 0, then calloc()
returns either NULL,or a unique pointer value that
can later be successfully passed to free().
If the multiplication of nmemb and size would
result in integer overflow, then calloc() returns an error.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total;
	char	*p;
	char	*q;
	size_t	size_max;

	size_max = (size_t) - 1;
	if (size && size_max / size < nmemb)
		return (NULL);
	total = nmemb * size;
	p = malloc(total);
	q = p;
	if (p != NULL)
	{
		i = 0;
		while (i < total)
		{
			*p++ = 0;
			i++;
		}
	}
	return ((void *)q);
}
