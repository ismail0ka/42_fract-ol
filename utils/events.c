/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:56:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/09 00:53:06 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

/*static void	zoom_in(t_fractal *fractal, double zoom_factor, int x, int y)
{
	printf("Zoom in: %f\n", fractal->zoom);
	fractal->zoom *= zoom_factor;
	fractal->o.real += (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom);
	fractal->o.imaginary += (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom);
}

static void	zoom_out(t_fractal *fractal, double zoom_factor, int x, int y)
{
	printf("Zoom out: %f\n", fractal->zoom);
	fractal->zoom /= zoom_factor;
	fractal->o.real -= (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom);
	fractal->o.imaginary -= (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom);
}*/
static void zoom_in(t_fractal *fractal, double zoom_factor, int x, int y)
{
    double aspect_ratio = (double)WIDTH / (double)HEIGHT;
    
    // Save the complex coordinates under the mouse before zooming
    double mouse_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH / fractal->zoom) + fractal->o.real;
    double mouse_im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT / fractal->zoom * aspect_ratio) + fractal->o.imaginary;
    
    // Adjust zoom level
    fractal->zoom *= zoom_factor;
    
    // Recalculate the origin to keep the point under the mouse at the same complex position
    fractal->o.real = mouse_re - (x - WIDTH / 2.0) * 4.0 / (WIDTH / fractal->zoom);
    fractal->o.imaginary = mouse_im - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT / fractal->zoom * aspect_ratio);
    
    printf("Zoom in: %f\n", fractal->zoom);
}

static void zoom_out(t_fractal *fractal, double zoom_factor, int x, int y)
{
    double aspect_ratio = (double)WIDTH / (double)HEIGHT;
    
    // Save the complex coordinates under the mouse before zooming
    double mouse_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH / fractal->zoom) + fractal->o.real;
    double mouse_im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT / fractal->zoom * aspect_ratio) + fractal->o.imaginary;
    
    // Adjust zoom level
    fractal->zoom /= zoom_factor;
    
    // Recalculate the origin to keep the point under the mouse at the same complex position
    fractal->o.real = mouse_re - (x - WIDTH / 2.0) * 4.0 / (WIDTH / fractal->zoom);
    fractal->o.imaginary = mouse_im - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT / fractal->zoom * aspect_ratio);
    
    printf("Zoom out: %f\n", fractal->zoom);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		zoom_in(fractal, 1.1, x , y);
		render_fractal(fractal);
	}
	else if (button == 5)
	{
		zoom_out(fractal, 1.1, x , y);
		render_fractal(fractal);
	}
	return (0);
}

int	close_window(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
	exit(EXIT_SUCCESS);
	return (0);
}
int	handle_key(int keycode, t_mlx_data *mlx_data)
{
	
	//Clean Up
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}