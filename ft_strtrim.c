/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:58:19 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
ft_strlen - provides us with the length
ft_calloc - allocates memory for an array, setting to 0
ft_strlcpy - copies a string
ft_strchr - checkes a string with char and returns a pointer*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	lens1;
	size_t	lenset;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	lens1 = ft_strlen(s1);
	lenset = ft_strlen(set);
	start = 0;
	end = lens1;
	while (ft_strchr(set, s1[start]) && lens1 && lenset && start < lens1)
		start++;
	if (start == end)
		return ((char *)ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[end]) && lens1 && lenset)
		end--;
	if (lenset == 0)
		end--;
	p = (char *)malloc((end - start + 2) * sizeof(char));
	if (p != NULL)
		ft_strlcpy(p, &s1[start], end - start + 2);
	return (p);
}
