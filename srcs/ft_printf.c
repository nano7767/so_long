/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:59 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/20 13:28:47 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static int	check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i = case_c((int)arg);
	else if (*input == 's')
		i = case_s((char *)arg);
	else if (*input == 'p')
		i = case_p((unsigned long)arg);
	else if (*input == 'd')
		i = case_d((int)arg);
	else if (*input == 'i')
		i = case_i((int)arg);
	else if (*input == 'u')
		i = case_u((unsigned int)arg);
	else if (*input == 'x')
		i = case_x((unsigned int)arg);
	else if (*input == 'X')
		i = case_ex((unsigned int)arg);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, va_arg(args, void *));
			else if (*input == '%')
				i += case_c('%');
		}
		else
			i = i + case_c(*input);
		input++;
	}
	va_end(args);
	return (i);
}
