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

t_img		*init_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(env->mlx, X_SIZE, Y_SIZE);
	img->data = mlx_get_data_addr(img->img,\
		&img->bpp, &img->sizeline, &img->endian);
	return (img);
}

void		mlx_put_pixel_to_img(t_env *env, int x, int y, int color)
{
	int		octet;

	octet = env->img->bpp / 8;
	if (x > 0 && x < X_SIZE && y > 0 && y < Y_SIZE)
		ft_memcpy(&env->img->data[octet * (x + env->img->sizeline / \
			octet * y)], &color, octet);
}

void		set_pixel_to_image(t_env *e)
{
	if (e->p->i == e->p->iter)
		mlx_put_pixel_to_img(e, e->p->x, e->p->y, 0);
	else
		mlx_put_pixel_to_img(e, e->p->x, e->p->y, e->p->color * e->p->i /\
			e->p->iter);
}
