/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:36:50 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/31 11:36:52 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		name(t_env *env)
{
	if (ft_strcmp(env->name, "julia") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Julia");
	if (ft_strcmp(env->name, "sword") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Sword");
	if (ft_strcmp(env->name, "tst") == 0)
		mlx_string_put(env->mlx, env->win, 880, 20, 0x42F483, "Tst");
	if (ft_strcmp(env->name, "chameleon") == 0)
		mlx_string_put(env->mlx, env->win, 866, 20, 0x42F483, "Chameleon");
	if (ft_strcmp(env->name, "mandelbrot") == 0)
		mlx_string_put(env->mlx, env->win, 850, 20, 0x42F483, "Mandelbrot");
	if (ft_strcmp(env->name, "bship") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Bship");
	if (ft_strcmp(env->name, "tricorn") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Tricorn");
	if (ft_strcmp(env->name, "celtic") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Celtic");
}

static void	commands(t_env *env)
{
	char	*iter;

	iter = ft_itoa(env->p->iter);
	mlx_string_put(env->mlx, env->win, 815, 70, 0x42DCF4, "Moove   :  Arrows");
	mlx_string_put(env->mlx, env->win, 815, 110, 0x42DCF4, "Iter +  :    s  ");
	mlx_string_put(env->mlx, env->win, 815, 150, 0x42DCF4, "Iter -  :    a  ");
	mlx_string_put(env->mlx, env->win, 815, 190, 0x42DCF4, "Reset   :   Tild ");
	mlx_string_put(env->mlx, env->win, 815, 230, 0x42DCF4, "Themes  :  1 to 5");
	mlx_string_put(env->mlx, env->win, 815, 270, 0x42DCF4, "Color + :    +  ");
	mlx_string_put(env->mlx, env->win, 815, 310, 0x42DCF4, "Color - :    -  ");
	mlx_string_put(env->mlx, env->win, 815, 350, 0x42DCF4, "Motion  :   Click");
	mlx_string_put(env->mlx, env->win, 815, 390, 0x42DCF4, "Iter    :        ");
	mlx_string_put(env->mlx, env->win, 935, 390, 0x42DCF4, iter);
	mlx_string_put(env->mlx, env->win, 815, 430, 0x42DCF4, "Motion  :        ");
	if (env->p->motion == 0)
		mlx_string_put(env->mlx, env->win, 935, 430, 0x990000, "off");
	else
		mlx_string_put(env->mlx, env->win, 935, 430, 0x10A943, "on");
}

void		print_menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;
	while (y <= Y_SIZE)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x42F483);
		y++;
	}
	name(env);
	commands(env);
}
