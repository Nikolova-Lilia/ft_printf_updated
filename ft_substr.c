/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:00:33 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*ft_substr() allocates (with malloc()) and returns
 a substring from the string 's'. The substring begins
at index 'start' and is of maximum size 'len'.
ft_strlen - provides us with the length
ft_memcpy - copies the information from src to dst*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (len != 0 && ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	while (*s != '\0' && i < start && len != 0)
	{
		s++;
		i++;
	}
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p != NULL)
	{
		ft_memcpy(p, s, len);
		p[len] = '\0';
	}
	return (p);
}
