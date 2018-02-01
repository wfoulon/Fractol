/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:35:45 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/30 12:35:47 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		select_fractals(t_env *env)
{
	if (ft_strcmp(env->name, "mandelbrot") == 0)
		draw_mandelbrot(env);
	if (ft_strcmp(env->name, "julia") == 0)
		draw_julia(env);
	if (ft_strcmp(env->name, "bship") == 0)
		draw_bship(env);
	if (ft_strcmp(env->name, "chameleon") == 0)
		draw_chameleon(env);
	if (ft_strcmp(env->name, "tricorn") == 0)
		draw_tricorn(env);
	if (ft_strcmp(env->name, "celtic") == 0)
		draw_celtic(env);
	if (ft_strcmp(env->name, "sword") == 0)
		draw_sword(env);
	if (ft_strcmp(env->name, "tst") == 0)
		draw_tst(env);
	mlx_clear_window(env->mlx, env->win);
	print_menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_mouse_hook(env->win, mouse_funct, env);
	mlx_hook(env->win, 6, 1 << 8, motion, env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_hook(env->win, 17, 1l < 17, ft_exit, env);
	mlx_loop(env->mlx);
}
