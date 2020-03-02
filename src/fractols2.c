/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:36:51 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/25 18:37:23 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_usual(t_fractol *fractol)
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
			2.0 * z.re * z.im + fractol->c.im);
		it++;
	}
	return (it);
}

int		julia_usual(t_fractol *fractol)
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
			2.0 * z.re * z.im + fractol->k.im);
		it++;
	}
	return (it);
}
