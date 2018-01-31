/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:17:04 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/23 14:17:44 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int			ft_exit(t_env *env)
{
	env = NULL;
	exit(0);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (ac != 2)
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/\
chameleon/celtic/test]");
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot") || \
		!ft_strcmp(av[1], "bship") || !ft_strcmp(av[1], "sword") || \
		!ft_strcmp(av[1], "tricorn") || !ft_strcmp(av[1], "chameleon") ||
		!ft_strcmp(av[1], "celtic") || !ft_strcmp(av[1], "tst"))
	{
		env = init_env(av[1]);
		select_fractals(env);
	}
	else
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/\
chameleon/celtic/tst");
	return (0);
}
