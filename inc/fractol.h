/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2020/02/25 19:46:28 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include "hotkeys.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_comp
{
	double			re;
	double			im;
}					t_comp;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*img_ptr;
	t_color			rgb;
	t_comp			min;
	t_comp			max;
	t_comp			factor;
	t_comp			c;
	t_comp			k;
	int				julia;
	int				max_iteration;
	char			*name;
	int				y_start;
	int				y_end;
	int				x_start;
	int				x_end;
	int				usage;
}					t_fractol;

t_comp				init_complex(double re, double im);
void				draw_fractol(t_fractol *fractol);
int					choose_fractol(t_fractol *fractol);
int					mandelbrot_usual(t_fractol *fractol);
int					heart_mandelbrot(t_fractol *fractol);
void				create_thread(t_fractol *fractol);
int					rgb_set(t_fractol *fractol, int iteration);
int					mouse_zoom(int key, int x, int y, t_fractol *fractol);
void				put_pixel(t_fractol *fractol, int x, int y, int color);
void				draw_usage(t_fractol *fractol);
void				full_fractol(t_fractol *fractol);
int					key_press(int key, void *param);
int					julia_usual(t_fractol *fractol);
int					mouse_cntrl(int x, int y, t_fractol *fractol);
void				ft_continue(int argc, char **argv);
void				ft_zoom(int key, t_fractol *fractol);
void				ft_error(char *str);
void				ft_usage(void);

#endif
