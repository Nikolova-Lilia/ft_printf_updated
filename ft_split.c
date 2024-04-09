/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:02:52 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
ft_strlen - calculates the length of the string.
ft_substr
*/
static size_t	ft_strcount(char const *s, char c)
{
	size_t	n;
	int		count;

	count = 0;
	n = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (count > 0)
			{
				n++;
				count = 0;
			}
		}
		else
			count++;
		s++;
	}
	if (count > 0)
		n++;
	return (n);
}

static size_t	ft_array_sorting(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (len);
		else
			len++;
		s++;
	}
	return (len);
}

static char	**ft_dealloc(char **str, int i)
{
	int	f;

	f = 0;
	while (f < i)
		free(str[f++]);
	free(str);
	return (NULL);
}

static int	ft_check_null(size_t len, char const *s)
{
	if (s[len] == '\0')
		return (0);
	else
		return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	int			i;
	int			len;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = ft_array_sorting(s, c);
			str[i++] = ft_substr(s, 0, len);
			if (str[i - 1] == NULL)
				return (ft_dealloc(str, i));
			s += len + ft_check_null(len, s);
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
