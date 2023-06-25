/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:20:21 by svikornv          #+#    #+#             */
/*   Updated: 2023/03/08 17:50:30 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

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
