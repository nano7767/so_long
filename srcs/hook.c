/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:43:27 by svikornv          #+#    #+#             */
/*   Updated: 2023/05/22 13:46:46 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
int	key_hooked_function(int keycode, void *param)
