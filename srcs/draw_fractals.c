/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:40:37 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/30 11:40:39 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_mandelbrot(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->c_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->c_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = (e->p->z_r * e->p->z_r) - (e->p->z_i * e->p->z_i) \
				+ e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_bship(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->c_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->c_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = fabs((e->p->z_r * e->p->z_r) - (e->p->z_i * \
					e->p->z_i) + e->p->c_r);
				e->p->z_i = fabs(2 * e->p->z_i * e->p->tmp + e->p->c_i);
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_tricorn(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->c_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->c_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = ((e->p->z_r * e->p->z_r) - (e->p->z_i * e->p->z_i) \
					+ e->p->c_r);
				e->p->z_i = -2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_celtic(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->c_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->c_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				e->p->i < e->p->iter)
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = fabs((e->p->z_r * e->p->z_r) - (e->p->z_i * \
					e->p->z_i)) + e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}
