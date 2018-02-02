/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:46:24 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/30 12:46:25 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param			*init_mandelbrot(void)
{
	t_param		*p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 50;
	p->motion = 0;
	p->x1 = -2.02;
	p->x2 = 0.6;
	p->y1 = -2.02;
	p->y2 = 1.2;
	p->zoom = 204;
	p->color = RGB(255, 255, 255);
	p->x = 0;
	p->y = 0;
	return (p);
}

t_param			*init_julia(void)
{
	t_param		*p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 50;
	p->motion = 1;
	p->x1 = -1.95;
	p->y1 = -1.95;
	p->zoom = 204;
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->color = RGB(120, 120, 120);
	p->x = 0;
	p->y = 0;
	return (p);
}
