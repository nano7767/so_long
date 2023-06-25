/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:12:03 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/25 15:56:52 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	count_substr(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (s == NULL || *s == '\0')
		return (0);
	i = 0;
	count = 0;
	if (s[i] != c)
	{
		i++;
		count++;
	}
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i - 1] == c && i > 0)
			count++;
		i++;
	}
	return (count);
}

static	char	*copy_substring(const char *s, char c, unsigned int start)
{
	char	*substring;
	size_t	length;

	length = 0;
	while (s[start + length] != '\0' && s[start + length] != c)
		length++;
	substring = ft_substr(s, start, length);
	return (substring);
}

char	*copy_copy(const char *s, char c, unsigned int start)
{
	char	*cp;
	size_t	len;

	cp = copy_substring(s, c, start);
	len = ft_strlen(cp);
	if (cp == NULL)
	{
		free(cp);
		return (NULL);
	}
	while (len > 0 && cp[len - 1] == c)
	{
		cp[len - 1] = '\0';
		len--;
	}
	return (cp);
}

char	**ft_split(const char *s, char c)
{
	char			**list_string;
	size_t			j;
	size_t			count;
	unsigned int	start;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	j = 0;
	count = count_substr(s, c);
	list_string = (char **)malloc((count + 1) * sizeof(char *));
	if (list_string == NULL)
		return (NULL);
	i = 0;
	while (j < count)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		list_string[j++] = copy_copy(s, c, start);
	}
	list_string[j] = NULL;
	return (list_string);
}
