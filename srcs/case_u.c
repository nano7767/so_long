/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:49:34 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 13:28:14 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(unsigned int n)
{
	int				i;
	unsigned int	nb;

	i = 1;
	nb = n;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	case_u(unsigned int n)
{
	if (n / 10 != 0)
		case_u (n / 10);
	ft_putchar_fd(n % 10 + 48, 1);
	return (intlen(n));
}
