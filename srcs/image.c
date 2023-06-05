/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:46:51 by svikornv          #+#    #+#             */
/*   Updated: 2023/05/22 13:51:46 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*mlx_new_image(void *mlxptr, int width, int height);
void	*mlx_xpm_file_to_img(void *mlxptr, char *relative_path, int *width, int *height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
