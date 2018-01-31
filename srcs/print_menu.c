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

void		name2(t_env *env)
{
	if (ft_strcmp(env->name, "julia") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0x42F483, "Julia");
	/*if (ft_strcmp(av1, "sword") == 0)
	{
		env->name = "Sword";
		mlx_string_put(env->mlx, env->win, 875, 20, 0xC1500D, env->name);
	}
	if (ft_strcmp(av1, "tst") == 0)
	{
		env->name = "Tst";
		mlx_string_put(env->mlx, env->win, 880, 20, 0xC1500D, env->name);
	}
	if (ft_strcmp(av1, "chameleon") == 0)
	{	
		env->name = "Chameleon";
		mlx_string_put(env->mlx, env->win, 866, 20, 0xC1500D, env->name);
	}*/
}

void		name(t_env *env)
{
	if (ft_strcmp(env->name, "mandelbrot") == 0)
	{	
		env->name = "Mandelbrot";
		mlx_string_put(env->mlx, env->win, 850, 20, 0xC1500D, env->name);
	}
	/*else if (ft_strcmp(av1, "bship") == 0)
		env->name = "Bship";
	else if (ft_strcmp(av1, "tricorn") == 0)
		env->name = "Tricorn";
	else if (ft_strcmp(av1, "celtic") == 0)
		env->name = "Celtic";*/
	else 
		name2(env);
}

static void	commands(t_env *env)
{
	char	*iter;
	char	*zoom;

	iter = ft_itoa(env->p->iter);
	zoom = ft_itoa(env->p->zoom);
	mlx_string_put(env->mlx, env->win, 815, 70, 0x42DCF4, "Moove   :  Arrows");
	mlx_string_put(env->mlx, env->win, 815, 110, 0x42DCF4, "Iter +  :    s  ");
	mlx_string_put(env->mlx, env->win, 815, 150, 0x42DCF4, "Iter -  :    a  ");
	mlx_string_put(env->mlx, env->win, 815, 190, 0x42DCF4, "Reset   :   Tild ");
	mlx_string_put(env->mlx, env->win, 815, 230, 0x42DCF4, "Themes  :  1 to 5");
	mlx_string_put(env->mlx, env->win, 815, 270, 0x42DCF4, "Color + :    +  ");
	mlx_string_put(env->mlx, env->win, 815, 310, 0x42DCF4, "Color - :    -  ");
	mlx_string_put(env->mlx, env->win, 815, 350, 0x42DCF4, "Motion  :   Click");
	mlx_string_put(env->mlx, env->win, 813, 620, 0x42F483, "    PARAMETERS   ");
	mlx_string_put(env->mlx, env->win, 815, 670, 0x42DCF4, "Iter    :        ");
	mlx_string_put(env->mlx, env->win, 935, 670, 0x42DCF4, iter);
	mlx_string_put(env->mlx, env->win, 815, 710, 0x42DCF4, "Motion  :        ");
	if (env->p->motion == 0)
		mlx_string_put(env->mlx, env->win, 935, 710, 0x990000, "off");
	else
		mlx_string_put(env->mlx, env->win, 935, 710, 0x10A943, "on");
	mlx_string_put(env->mlx, env->win, 815, 750, 0x42DCF4, "Zoom    :        ");
	mlx_string_put(env->mlx, env->win, 935, 750, 0x42DCF4, zoom);
}

void		print_menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;
	while (y <= Y_SIZE)
	{
		mlx_pixel_put(env->mlx,env->win, x, y, 0x165AA4);
		y++;
	}
	name(env);
	commands(env);
}