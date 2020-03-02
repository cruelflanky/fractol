/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/25 18:38:37 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp		init_complex(double re, double im)
{
	t_comp	comp;

	comp.re = re;
	comp.im = im;
	return (comp);
}

void		full_fractol(t_fractol *fractol)
{
	fractol->max_iteration = 30;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->usage = 0;
	fractol->julia = 1;
	fractol->rgb.r = 0;
	fractol->rgb.g = 0;
	fractol->rgb.b = 0;
	fractol->k = init_complex(-0.4, 0.6);
}

int			ft_check_argv(int argc, char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > 'A' && argv[i][j] < 'Z')
				argv[i][j] += 32;
			j++;
		}
		if ((!ft_strequ(argv[i], "mandelbrot")) &&
			(!ft_strequ(argv[i], "julia")) &&
			(!ft_strequ(argv[i], "burning ship")) &&
			(!ft_strequ(argv[i], "heart mandelbrot")) &&
			(!ft_strequ(argv[i], "mandelbrot 5th")))
			return (0);
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc >= 2 && argc <= 11)
	{
		(!ft_check_argv(argc, argv)) ? ft_error("argv") : 0;
		ft_continue(argc - 1, argv);
	}
	else
		ft_usage();
	return (0);
}
