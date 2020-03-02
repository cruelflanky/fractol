/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:02:16 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/25 18:47:09 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	if (ft_strcmp(str, "argv") == 0)
	{
		ft_putendl("Wrong arguments\n");
		ft_usage();
	}
	if (ft_strcmp(str, "thread") == 0)
		ft_putendl("Thread error");
	exit(EXIT_FAILURE);
}

void	ft_usage(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(" __   __   _____       _        ____   _____");
	ft_putendl("|  | |  | |   __|    /   \\    /  ___| |   __|");
	ft_putendl("|  | |  | |_____    / /_\\ \\  |   ___  |  |__");
	ft_putendl("|  | |  |  ___  |  /  ___  \\ |  |__ | |  |__");
	ft_putendl(" \\_____/  |_____| /_ /   \\ _\\ \\_____/ |_____|");
	ft_putendl(" ___________________________________________");
	ft_putendl("| You need to type at least 1 fractal name  |");
	ft_putendl("|                                           |");
	ft_putendl("| List of fractals:                         |");
	ft_putendl("| > Mandelbrot                              |");
	ft_putendl("| > Julia                                   |");
	ft_putendl("| > Burning Ship                            |");
	ft_putendl("| > Heart Mandelbrot                        |");
	ft_putendl("| > Mandelbrot 5th                          |");
	ft_putendl("\\___________________________________________/");
}

void	print_usage(t_fractol *fractol)
{
	int		(*f)(void *, void *, int, int, int, char *);

	f = &mlx_string_put;
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 20, 0x00a5f7, "Usage");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 80, 0x00a5f7, "Iteration: </>");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 120, 0x00a5f7, "Move: Arrows");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 160, 0x00a5f7, "Zoom: Num +/-");
	f(fractol->mlx_ptr, fractol->win_ptr, 40,
		200, 0x00a5f7, "Mouse Zoom: scroll");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 240, 0x00a5f7, "Julia motion: J");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 280, 0x00a5f7, "RGB controls");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 320, 0xff0000, "Red: 7/9");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 360, 0x00ff00, "Green: 4/6");
	f(fractol->mlx_ptr, fractol->win_ptr, 40, 400, 0x0000ff, "Blue: 1/3");
}

void	draw_usage(t_fractol *fractol)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < (WIDTH / 3))
			put_pixel(fractol, x++, y, 0x000000);
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img_ptr->image, 0, 0);
	print_usage(fractol);
}
