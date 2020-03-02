/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:04:10 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/24 22:30:29 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int key, t_fractol *fractol)
{
	t_comp	delta;

	delta = init_complex(fabs(fractol->max.re - fractol->min.re),
		fabs(fractol->max.im - fractol->min.im));
	if (key == KEYCODE_LEFT_ARROW)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == KEYCODE_RIGHT_ARROW)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == KEYCODE_UP_ARROW)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == KEYCODE_DOWN_ARROW)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	create_thread(fractol);
}

void	ft_iteration(int key, t_fractol *fractol)
{
	if (key == KEYCODE_Z_HEIGHT_UP)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration += 1;
		else if (fractol->max_iteration < 1000000000)
			fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
	}
	if (key == KEYCODE_Z_HEIGHT_DOWN)
	{
		if (fractol->max_iteration < 50)
			fractol->max_iteration -= 1;
		else if (fractol->max_iteration >= 50)
			fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
	}
	create_thread(fractol);
}

void	ft_rgb_change(int key, t_fractol *fractol)
{
	if (key == KEYCODE_4_NUM)
		fractol->rgb.g++;
	if (key == KEYCODE_6_NUM)
		fractol->rgb.g--;
	if (key == KEYCODE_7_NUM)
		fractol->rgb.r++;
	if (key == KEYCODE_9_NUM)
		fractol->rgb.r--;
	if (key == KEYCODE_1_NUM)
		fractol->rgb.b++;
	if (key == KEYCODE_3_NUM)
		fractol->rgb.b--;
	create_thread(fractol);
}

void	bool_immitation(int key, t_fractol *fractol)
{
	if (key == KEYCODE_U)
	{
		if (fractol->usage == 0)
		{
			draw_usage(fractol);
			fractol->usage = 1;
		}
		else
		{
			create_thread(fractol);
			fractol->usage = 0;
		}
	}
	else
		fractol->julia *= -1;
}

int		key_press(int key, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	(key == KEYCODE_ESC) ? exit(0) : 0;
	if (key == KEYCODE_Z_HEIGHT_UP || key == KEYCODE_Z_HEIGHT_DOWN)
		ft_iteration(key, fractol);
	if (key == KEYCODE_MINUS || key == KEYCODE_PLUS)
		ft_zoom(key, fractol);
	if (key == KEYCODE_RIGHT_ARROW || key == KEYCODE_LEFT_ARROW ||
			key == KEYCODE_UP_ARROW || key == KEYCODE_DOWN_ARROW)
		ft_move(key, fractol);
	if (key == KEYCODE_U || key == KEYCODE_J)
		bool_immitation(key, fractol);
	if (key == KEYCODE_4_NUM || key == KEYCODE_6_NUM ||
			key == KEYCODE_7_NUM || key == KEYCODE_9_NUM ||
			key == KEYCODE_1_NUM || key == KEYCODE_3_NUM)
		ft_rgb_change(key, fractol);
	return (0);
}
