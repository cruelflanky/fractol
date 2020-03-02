/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:54:00 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/25 18:42:40 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burning_ship(t_fractol *fractol)
{
	t_comp	z;
	int		it;

	z = init_complex(fractol->c.re, fractol->c.im);
	it = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& it < fractol->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0)
			- pow(z.im, 2.0) + fractol->c.re,
			-2.0 * fabs(z.re * z.im) + fractol->c.im);
		it++;
	}
	return (it);
}

int			heart_mandelbrot(t_fractol *fractol)
{
	t_comp	z;
	int		it;

	z = init_complex(fractol->c.re, fractol->c.im);
	it = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& it < fractol->max_iteration)
	{
		z = init_complex(pow(z.re, 2.0)
			- pow(z.im, 2.0) + fractol->k.re,
			2.0 * fabs(z.re) * z.im + fractol->k.im);
		it++;
	}
	return (it);
}

int			mandelbrot_5th(t_fractol *fractol)
{
	t_comp	z;
	int		it;

	z = init_complex(fractol->c.re, fractol->c.im);
	it = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& it < fractol->max_iteration)
	{
		z = init_complex(z.re * (pow(pow(z.re, 2.0), 2.0)
			- 10 * pow(z.im * z.re, 2.0) +
			5 * pow(pow(z.im, 2.0), 2.0)) + fractol->c.re,
			z.im * (5 * pow(pow(z.re, 2.0), 2.0)
			- 10 * pow(z.im * z.re, 2.0) +
			pow(pow(z.im, 2.0), 2.0)) + fractol->c.im);
		it++;
	}
	return (it);
}

int			choose_fractol(t_fractol *fractol)
{
	if (ft_strequ(fractol->name, "mandelbrot"))
		return (mandelbrot_usual(fractol));
	if (ft_strequ(fractol->name, "mandelbrot 5th"))
		return (mandelbrot_5th(fractol));
	if (ft_strequ(fractol->name, "heart mandelbrot"))
		return (heart_mandelbrot(fractol));
	if (ft_strequ(fractol->name, "burning ship"))
		return (burning_ship(fractol));
	if (ft_strequ(fractol->name, "julia"))
		return (julia_usual(fractol));
	return (0);
}
