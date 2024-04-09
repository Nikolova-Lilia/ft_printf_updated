/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:19:28 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
ft_strlen - provides us with the length
ft_memcpy - copies the information from src to dst*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	j;
	unsigned int	k;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	p = malloc((j + k + 1) * sizeof(char));
	if (p != NULL)
	{
		ft_memcpy(p, s1, j);
		ft_memcpy(&(p[j]), s2, k);
		p[j + k] = '\0';
	}
	return (p);
}
