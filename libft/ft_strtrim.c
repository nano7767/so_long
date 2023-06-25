/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:15:39 by svikornv          #+#    #+#             */
/*   Updated: 2023/03/01 13:13:13 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first_occurence;
	size_t	last;

	if (set == NULL)
		return (ft_strdup(s1));
	else if (s1 == NULL)
		return (NULL);
	first_occurence = 0;
	while (ft_strchr(set, s1[first_occurence]) != NULL)
	{
		if (first_occurence == ft_strlen(s1))
			return (ft_strdup(""));
		first_occurence++;
	}
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[last]) != NULL)
		last--;
	return (ft_substr(s1, first_occurence, last - first_occurence + 1));
}
