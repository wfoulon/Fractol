/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:02:45 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/31 13:02:47 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double		rescale_moove(t_env *env)
{
	static double	i;

	i = 0.2;
	if (env->p->zoom <= 100)
		i = 0.2;
	if (env->p->zoom > 100 && env->p->zoom <= 1000)
		i = 0.02;
	if (env->p->zoom > 1000 && env->p->zoom <= 10000)
		i = 0.002;
	if (env->p->zoom > 10000 && env->p->zoom <= 100000)
		i = 0.0002;
	if (env->p->zoom > 100000)
		i = 0.00002;
	return (i);
}


void				moove(int keycode,t_env *env)
{
	double			i;

	i = rescale_moove(env);
	if (keycode == ARROW_LEFT)
		env->p->x1 += i;
	if (keycode == ARROW_RIGHT)
		env->p->x1 -= i;
	if (keycode == ARROW_DOWN)
		env->p->y1 += i;
	if (keycode == ARROW_UP)
		env->p->y1 -= i;
}

int					key_funct(int keycode, t_env *env)
{
	ft_putstr("keycode :\n");
	ft_putnbr(keycode);
	if (env->mlx == NULL)
		return (0);
	if (keycode == TOUCH_ESC)
		exit(1);
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env);
	if (keycode == MORE_COLOR || keycode == LESS_COLOR)
		color(keycode, env);
	if (keycode == ARROW_LEFT || keycode == ARROW_DOWN || keycode == \
		ARROW_UP || keycode == ARROW_RIGHT)
		moove(keycode, env);
	if (keycode == T1 || keycode == T2 || keycode == T3 || keycode == \
		T4 || keycode == T5)
		theme(keycode, env);
	if (keycode == ORIGIN)
		origin(keycode, env);
	select_fractals(env);
	return (0);
}