/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:44:17 by svikornv          #+#    #+#             */
/*   Updated: 2023/03/13 15:03:50 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;
	t_list	*ptr2;
	int		count;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	count = 0;
	while (ptr != NULL)
	{
		ptr = ptr -> next;
		count++;
	}
	ptr2 = lst;
	while (count > 1)
	{
		ptr2 = ptr2 -> next;
		count--;
	}
	return (ptr2);
}
