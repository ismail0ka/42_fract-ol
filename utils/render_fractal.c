/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:34:16 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/04 15:34:37 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->b_pp / 8));
	*(unsigned int *)dst = color;
}

void render_fractal(t_mlx_data *mlx_data, t_fractal *fractal)
{
    int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
    {
		y = -1;
		while (++y < HEIGHT)
        {
            int iter = 0;
			if (fractal->type == MANDELBROT)
            	mandelbrot(x, y, &iter);
			else if (fractal->type == JULIA)
				julia(x, y, &iter, fractal);
            int color = (iter == MAX_ITER) ? 0 : (iter * 255 / MAX_ITER);
            my_mlx_put_pixel(&(mlx_data->mlx_img), x, y, color);
        }
    }
    mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->mlx_img.img, 0, 0);
}