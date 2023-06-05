/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:14:45 by svikornv          #+#    #+#             */
/*   Updated: 2023/03/01 15:16:07 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	number;
	char	*itoa;

	i = ft_intlen(n);
	number = (long)n;
	itoa = (char *)malloc((i + 1) * sizeof(char));
	if (itoa == NULL)
		return (NULL);
	if (number < 0)
	{
		itoa[0] = '-';
		number = number * -1;
	}
	else if (number == 0)
		itoa[0] = '0';
	itoa[i] = '\0';
	while (number > 0)
	{
		i--;
		itoa[i] = number % 10 + '0';
		number = number / 10;
	}
	return (itoa);
}
