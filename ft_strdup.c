/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:34:51 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The  strdup() function returns a pointer to a new string
which is a duplicate of the string s. Memory for the
new string  is  obtained  with malloc(3), and can be
freed with free(3).*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s) + 1;
	dst = malloc(len);
	if (dst != NULL)
	{
		ft_memcpy (dst, s, len);
	}
	return (dst);
}
