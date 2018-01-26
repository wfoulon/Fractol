/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:22:57 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/23 12:23:08 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img		*init_img(t_env *env, int height, int width)
{
	t_img	*image;

	if (!(image = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	image->img = mlx_new_image(env->mlx, height, width);
	image->data = mlx_get_data_addr(image->img,\
		&image->bpp, &image->sizeline, &image->endian);
	return (image);
}

void		mlx_put_pixel_to_img(t_env *env, int x, int y, int color)
{
	int		octet;
	octet = env->img->bpp / 8;
	if (x > 0 && x < X_SIZE && y > 0 && y < Y_SIZE)
		ft_memcpy(&env->img->data[octet * (x + env->img->sizeline / \
			octet * y)], &color, octet);
}

int			fill_img(t_env *env)
{
	int		h;
	int		w;

	h = HEIGHT_DRAW;
	w = WIDTH_DRAW;
	if (!(env->back_img->img = mlx_xpm_file_to_image(env->mlx, \
			"./images/paysage-galaxy2.xpm", &w, &h)))
		return (0);
	if (!(env->sup_img->img = mlx_xpm_file_to_image(env->mlx, \
			"./images/blancdim.XPM")))
		return (0);
	return (1);
}