/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:26:41 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/23 13:26:57 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->name = NULL;
	env->p = NULL;
	return (env);
}

t_env		*init_env(char *str)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->name = str;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_SIZE + 200, Y_SIZE, env->name);
	env->img = init_img(env);
	if (!ft_strcmp(env->name, "mandelbrot") || !ft_strcmp(env->name, "bship") || \
		!ft_strcmp(env->name, "tricorn") || !ft_strcmp(env->name, "celtic"))
		env->p = init_mandelbrot();
	else if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "chameleon") \
		 || !ft_strcmp(env->name, "sword") || !ft_strcmp(env->name, "tst"))
		env->p = init_julia();
	return (env);
}