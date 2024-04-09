/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:46:15 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strrchr() function returns a pointer to
the last occurrence of  the character c in the string s.
The strchr() and strrchr() functions return a pointer to
the matched character or NULL if the character is not found.
The terminating null byte is considered part of the string,
so that if c is specified as aq\0aq, these functions return a
pointer to the terminator.*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			p = s;
		s++;
	}
	if (c == '\0')
		p = s;
	return ((char *)p);
}
