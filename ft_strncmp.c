/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:26:03 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The  strcmp() function compares the two strings s1 and s2.
  The locale is not taken into account
  (for  a  locale-aware  comparison,  see  str‐coll(3)).
  The comparison is done using unsigned characters.
  Strcmp() returns an integer indicating the result
   of the comparison, as follows:
• 0, if the s1 and s2 are equal;
• a negative value if s1 is less than s2;
• a positive value if s1 is greater than s2.
The strncmp() function is similar,
 except it compares  only  the  first(at most)
  n bytes of s1 and s2.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && i < n - 1 && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
