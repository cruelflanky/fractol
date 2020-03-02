/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:47:11 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/24 22:28:05 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	i;

	i = (x * fractol->img_ptr->bits_per_pixel / 8)
		+ (y * fractol->img_ptr->size_line);
	fractol->img_ptr->data_addr[i] = color;
	fractol->img_ptr->data_addr[++i] = color >> 8;
	fractol->img_ptr->data_addr[++i] = color >> 16;
}

int		rgb_set(t_fractol *fractol, int iteration)
{
	double		t;
	t_color		rgb;

	t = (double)iteration / fractol->max_iteration;
	rgb.r = (unsigned char)((9 + fractol->rgb.r)
		* (1 - t) * pow(t, 3) * 255);
	rgb.g = (unsigned char)((15 + fractol->rgb.g)
		* pow((1 - t), 2) * pow(t, 2) * 255);
	rgb.b = (unsigned char)((8.5 + fractol->rgb.b)
		* pow((1 - t), 3) * t * 255);
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}
