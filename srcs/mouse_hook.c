/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:29:12 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/01 12:29:14 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_funct(int mouse, int x, int y, t_env *env)
{
	double	x_comp;
	double	y_comp;

	if (x > 0 && y > 0)
	{
		x_comp = (x / env->p->zoom) + env->p->x1;
		y_comp = (y / env->p->zoom) + env->p->y1;
		if (mouse == 4)
		{
			env->p->zoom *= 1.1;
			env->p->x1 = x_comp - (x / env->p->zoom);
			env->p->y1 = y_comp - (y / env->p->zoom);
		}
		if (mouse == 5)
		{
			env->p->zoom /= 1.1;
			env->p->x1 = x_comp - (x / env->p->zoom);
			env->p->y1 = y_comp - (y / env->p->zoom);
		}
		if (mouse == 2)
			env->p->motion = (env->p->motion == 0) ? 1 : 0;
	}
	select_fractals(env);
	return (0);
}

int			motion(int x, int y, t_env *env)
{
	if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "sword") \
		|| !ft_strcmp(env->name, "tst") || \
		!ft_strcmp(env->name, "chameleon"))
	{
		if (env->p->motion % 2 == 1)
		{
			if (x > 0 && x < X_SIZE && y > 0 && y < Y_SIZE)
			{
				if (x < X_SIZE / 2 && y < Y_SIZE / 2)
					env->p->c_r += 0.05;
				if (x > X_SIZE / 2 && y < Y_SIZE / 2)
					env->p->c_r -= 0.05;
				if (x < X_SIZE / 2 && y > Y_SIZE / 2)
					env->p->c_i += 0.05;
				if (x > X_SIZE / 2 && y < Y_SIZE / 2)
					env->p->c_i -= 0.05;
			}
		}
		select_fractals(env);
	}
	return (0);
}
