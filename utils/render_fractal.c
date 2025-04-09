/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:34:16 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/09 12:19:09 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iter, int max_iter)
{
	int	color;

	if (iter == max_iter)
		return (0x00000000);
	color = (iter * 255 / max_iter);
	return ((color << 16) | (color << 8) | color);
}

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->b_pp / 8));
	*(unsigned int *)dst = color;
}

void render_fractal(t_fractal *f)
{
	int x;
	int y;

	x = -1;
	while (++x < WIDTH)
    {
		y = -1;
		while (++y < HEIGHT)
        {
            int iter = 0;
			if (f->type == MANDELBROT)
            	mandelbrot(x, y, &iter, f);
			else if (f->type == JULIA)
				julia(x, y, &iter, f);
            int color = (iter == MAX_ITER) ? 0 : get_color(iter, MAX_ITER);
            my_mlx_put_pixel(&(f->mlx_data->mlx_img), x, y, color);
        }
    }
    mlx_put_image_to_window(f->mlx_data->mlx, f->mlx_data->mlx_window, f->mlx_data->mlx_img.img, 0, 0);
}