/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:36:07 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/23 11:36:42 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "define.h"
# include "struct.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

/*
** draw_fractals.c
*/
void		draw_mandelbrot(t_env *e);
void		draw_bship(t_env *e);
void		draw_tricorn(t_env *e);
void		draw_celtic(t_env *e);

/*
** draw_fractals2.c
*/
void		draw_julia(t_env *e);
void		draw_chameleon(t_env *e);
void		draw_sword(t_env *e);
void		draw_tst(t_env *e);

/*
** function_event.c
*/
int			key_funct(int keycode, t_env *env);
void		moove(int keycode, t_env *env);

/*
** init_img.c
*/
t_img		*init_img(t_env *env);
void		mlx_put_pixel_to_img(t_env *env, int x, int y, int color);
void		set_pixel_to_image(t_env *e);

/*
** init_env.c
*/
t_env		*new_env(void);
t_env		*init_env(char *av1);

/*
** init_param.c
*/
t_param		*init_mandelbrot(void);
t_param		*init_julia(void);

/*
** key_functions.c
*/
void		iter(int keycode, t_env *env);
void		theme(int keycode, t_env *env);
void		color(int keycode, t_env *env);
void		origin(int keycode, t_env *env);

/*
** main.c
*/
void		ft_error(char *str);
int			ft_exit(t_env *env);

/*
** mouse_hook.c
*/
int			mouse_funct(int mouse, int x, int y, t_env *env);
int			motion(int x, int y, t_env *env);
/*
** print_menu.c
*/
void		name(t_env *env);
void		print_menu(t_env *env);

/*
** select_fractals.c
*/
void		select_fractals(t_env *env);

#endif
