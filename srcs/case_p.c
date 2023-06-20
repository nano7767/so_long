/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:40:05 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 13:27:55 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_string(unsigned long p, int *intlen)
{
	unsigned long	tmp;
	int				i;
	char			*string;

	tmp = p;
	i = 0;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	string = (char *)ft_calloc((i + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	*intlen = i;
	return (string);
}

int	case_p(unsigned long p)
{
	char			*hex;
	int				i;
	int				len;
	unsigned long	tmp;

	hex = make_string(p, &i);
	if (hex == NULL)
		return (-1);
	hex[i] = '\0';
	tmp = p;
	while (tmp != 0)
	{
		i--;
		if (tmp % 16 < 10)
			hex[i] = tmp % 16 + 48;
		else
			hex[i] = tmp % 16 + 87;
		tmp = tmp / 16;
	}
	len = case_s("0x");
	len += case_s(hex);
	free(hex);
	if (p == 0)
		len += case_c('0');
	return (len);
}
