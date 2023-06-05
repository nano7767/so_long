/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:07:11 by svikornv          #+#    #+#             */
/*   Updated: 2023/03/03 12:11:08 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	y = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] != '\0' && i < (dstsize - dstlen - 1))
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (dstlen + srclen);
}
