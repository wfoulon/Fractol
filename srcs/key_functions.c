/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:37:34 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/31 12:37:36 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iter(int keycode, t_env *env)
{
	if (keycode == MORE_ITER)
		env->p->iter++;
	if (keycode == LESS_ITER && env->p->iter > 2)
		env->p->iter--;
}

void		theme(int keycode, t_env *env)
{
	if (keycode == T1)
		env->p->color = RGB(255, 255, 255);
	if (keycode == T2)
		env->p->color = RGB(210, 210, 210);
	if (keycode == T3)
		env->p->color = RGB(160, 160, 160);
	if (keycode == T4)
		env->p->color = RGB(110, 110, 110);
	if (keycode == T5)
		env->p->color = RGB(50, 50, 50);
}

void		color(int keycode, t_env *env)
{
	if (keycode == MORE_COLOR && env->p->color < 2147483391)
		env->p->color += 3000;
	if (keycode == LESS_COLOR && env->p->color > 256)
		env->p->color -= 3000;
}

void		origin(int keycode, t_env *env)
{
	if (keycode == ORIGIN)
	{
		if (!ft_strcmp(env->name, "julia") || \
			!ft_strcmp(env->name, "chameleon") || \
			!ft_strcmp(env->name, "sword") || \
			!ft_strcmp(env->name, "tst"))
			env->p = init_julia();
		else
			env->p = init_mandelbrot();
	}
}