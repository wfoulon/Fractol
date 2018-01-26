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

/*
** init_img.c
*/
t_img		*init_img(t_env *env);
void		mlx_put_pixel_to_img(t_env *env, int x, int y, int color);
int			fill_img(t_env *env);

/*
** init_env.c
*/
t_env		*new_env(void);


/*
** init_param.c
*/

#endif
