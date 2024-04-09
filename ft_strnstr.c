/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:02:17 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strnstr() function locates the first occurrence
of the nullterminated string little in the string big,
where not more than len characters are searched.
Characters that appear after a ‘\0’ character are not searched.
Since the strnstr() function is a FreeBSD specific API,
it should only be used when portability is not a concern.*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
			if (big[i + j] == '\0')
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
