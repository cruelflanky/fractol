/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:06:44 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/26 13:45:21 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// #include <X11/X.h>

void			draw_fractol(t_fractol *fractol)
{
	int			x;
	int			y;
	int			it;

	y = fractol->y_start;
	while (y < fractol->y_end)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = fractol->x_start;
		while (x < fractol->x_end)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			it = choose_fractol(fractol);
			put_pixel(fractol, x, y, rgb_set(fractol, it));
			x++;
		}
		y++;
	}
}

void			thread(t_fractol *frac, t_fractol *f, pthread_t *thr, int *i)
{
	int			j;
	int			x;

	x = 0;
	while (*i < 40)
	{
		j = 0;
		while (j < 4)
		{
			frac[*i] = *f;
			frac[*i].y_start = x * (HEIGHT / 10);
			frac[*i].y_end = (x + 1) * (HEIGHT / 10);
			frac[*i].x_start = j * (WIDTH / 4);
			frac[*i].x_end = (j + 1) * (WIDTH / 4);
			if (pthread_create(&thr[*i], NULL,
				(void *(*)(void *))draw_fractol, (void *)&frac[*i]))
				ft_error("thread");
			j++;
			(*i)++;
		}
		x++;
	}
}

void			create_thread(t_fractol *fractol)
{
	pthread_t	threads[40];
	t_fractol	fractols[40];
	int			i;

	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	thread(fractols, fractol, threads, &i);
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			ft_error("thread");
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img_ptr->image, 0, 0);
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, 20,
		15, 0x00a5f7, "Usage: U");
}

void			ft_continue(int argc, char **argv)
{
	t_fractol	fractol[argc];
	t_image		img_ptr;
	void		*mlx_ptr;
	int			i;

	i = 0;
	mlx_ptr = mlx_init();
	while (i < argc)
	{
		fractol[i].name = argv[i + 1];
		full_fractol(&fractol[i]);
		fractol[i].mlx_ptr = mlx_ptr;
		fractol[i].win_ptr = mlx_new_window(fractol[i].mlx_ptr,
			WIDTH, HEIGHT, fractol[i].name);
		img_ptr.image = mlx_new_image(fractol[i].mlx_ptr, WIDTH, HEIGHT);
		img_ptr.data_addr = mlx_get_data_addr(img_ptr.image,
			&img_ptr.bits_per_pixel, &img_ptr.size_line, &img_ptr.endian);
		fractol[i].img_ptr = &img_ptr;
		mlx_hook(fractol[i].win_ptr, 2, 0, key_press, &fractol[i]);
		mlx_hook(fractol[i].win_ptr, 6, 0, mouse_cntrl, &fractol[i]);
		mlx_hook(fractol[i].win_ptr, 4, 0, mouse_zoom, &fractol[i]);
		create_thread(&fractol[i]);
		i++;
	}
	mlx_loop(mlx_ptr);
}
