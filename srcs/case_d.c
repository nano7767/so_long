/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:41:50 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 13:27:24 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	case_d(int n)
{
	int				nb;
	unsigned int	intlen;

	nb = n;
	intlen = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		intlen++;
	}
	else if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	while (nb > 9)
	{
		nb = nb / 10;
		intlen++;
	}
	ft_putnbr_fd(n, 1);
	return (intlen);
}
