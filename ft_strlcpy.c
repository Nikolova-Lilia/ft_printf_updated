/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:35:21 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strlcpy() and strlcat() functions copy and concatenate
 strings respectively.  They are designed to be safer, more
 consistent, and less error prone replacements for strncpy(3)
 and strncat(3).  Unlike those functions, strlcpy() and strlcat()
 take the full size of the buffer (not just the length) and
 guarantee to NUL-terminate the result (as long as size is larger
 than 0 or, in the case of strlcat(), as long as there is
 at least one byte free in dst).  Note that a byte for the NUL
 should be included in size.  Also note that strlcpy()
 and strlcat() only operate on true “C” strings.
 This means that for strlcpy() src must be NUL-terminated
 and for strlcat() both src and dst must be NUL-terminated.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
