/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:27 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/13 11:56:24 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) *(ft_strlen(s1) + 1));
	if (dest != NULL)
	{
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i - len1] != '\0')
	{	
		s3[i] = s2[i - len1];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	current;
	char	*sub;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	else if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	i = 0;
	current = start;
	new_len = len;
	if (len > ft_strlen(&s[start]))
		new_len = ft_strlen(&s[start]);
	sub = (char *)malloc((new_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < new_len && current < new_len + current)
	{
		current = start + i;
		sub[i] = s[current];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
