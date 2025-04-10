/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:56:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/10 15:44:39 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(t_fractal *fractal, double zoom_factor, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	aspect_ratio;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	mouse_re = (x - WIDTH / 2.0) * 4.0
		/ (WIDTH / fractal->zoom) + fractal->o.real;
	mouse_im = (y - HEIGHT / 2.0) * 4.0
		/ (HEIGHT / fractal->zoom * aspect_ratio) + fractal->o.imaginary;
	fractal->zoom *= zoom_factor;
	fractal->o.real = mouse_re - (x - WIDTH / 2.0) * 4.0
		/ (WIDTH / fractal->zoom);
	fractal->o.imaginary = mouse_im - (y - HEIGHT / 2.0) * 4.0
		/ (HEIGHT / fractal->zoom * aspect_ratio);
}

static void	zoom_in(t_fractal *fractal, double zoom_factor, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	aspect_ratio;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	mouse_re = (x - WIDTH / 2.0) * 4.0
		/ (WIDTH / fractal->zoom) + fractal->o.real;
	mouse_im = (y - HEIGHT / 2.0) * 4.0
		/ (HEIGHT / fractal->zoom * aspect_ratio) + fractal->o.imaginary;
	fractal->zoom /= zoom_factor;
	fractal->o.real = mouse_re - (x - WIDTH / 2.0) * 4.0
		/ (WIDTH / fractal->zoom);
	fractal->o.imaginary = mouse_im - (y - HEIGHT / 2.0) * 4.0
		/ (HEIGHT / fractal->zoom * aspect_ratio);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		zoom_in(fractal, 1.1, x, y);
		render_fractal(fractal);
	}
	else if (button == 5)
	{
		zoom_out(fractal, 1.1, x, y);
		render_fractal(fractal);
	}
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx_data->mlx, f->mlx_data->mlx_img.img);
	mlx_destroy_window(f->mlx_data->mlx, f->mlx_data->mlx_window);
	mlx_destroy_display(f->mlx_data->mlx);
	(free(f->mlx_data->mlx), free(f->mlx_data), free(f));
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(f->mlx_data->mlx, f->mlx_data->mlx_img.img);
		mlx_destroy_window(f->mlx_data->mlx, f->mlx_data->mlx_window);
		mlx_destroy_display(f->mlx_data->mlx);
		(free(f->mlx_data->mlx), free(f->mlx_data), free(f));
		exit(EXIT_SUCCESS);
	}
	return (0);
}
