/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:08:39 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/26 13:45:05 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

void		ft_zoom(int key, t_fractol *fractol)
{
	double	zoom;
	double	inter;
	t_comp	center;

	center = init_complex(
			(double)500 / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)500 / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
	if (key == KEYCODE_MINUS)
		zoom = 0.80;
	if (key == KEYCODE_PLUS)
		zoom = 1.20;
	inter = 1.0 / zoom;
	fractol->min.re = interpolate(center.re, fractol->min.re, inter);
	fractol->min.im = interpolate(center.im, fractol->min.im, inter);
	fractol->max.re = interpolate(center.re, fractol->max.re, inter);
	fractol->max.im = interpolate(center.im, fractol->max.im, inter);
	create_thread(fractol);
}

int			mouse_zoom(int key, int x, int y, t_fractol *fractol)
{
	double	zoom;
	double	inter;
	t_comp	mouse;

	zoom = 1;
	mouse = init_complex(
			(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
	if (key == KEYCODE_SCROLL_DOWN)
		zoom = 0.80;
	if (key == KEYCODE_SCROLL_UP)
		zoom = 1.20;
	inter = 1.0 / zoom;
	fractol->min.re = interpolate(mouse.re, fractol->min.re, inter);
	fractol->min.im = interpolate(mouse.im, fractol->min.im, inter);
	fractol->max.re = interpolate(mouse.re, fractol->max.re, inter);
	fractol->max.im = interpolate(mouse.im, fractol->max.im, inter);
	create_thread(fractol);
	return (0);
}

int			mouse_cntrl(int x, int y, t_fractol *fractol)
{
	if (fractol->julia > 0)
	{
		fractol->k = init_complex(
			3 * ((double)x / WIDTH - 0.5),
			3 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		create_thread(fractol);
	}
	return (0);
}
