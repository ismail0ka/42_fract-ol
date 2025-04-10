/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:34:16 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/10 01:08:01 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iter, int max_iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == max_iter)
		return (0x00000000);
	t = (double)iter / max_iter;
	t = pow(t, 0.5);
	r = (int)255 * pow(t, 0.7);
	g = (int)255 * pow(t, 0.5);
	b = (int)255 * pow(t, 0.3);
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_put_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->b_pp / 8));
	*(unsigned int *)dst = color;
}

void	render_fractal(t_fractal *f)
{
	int	x;
	int	y;
	int	iter;
	int	color;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			iter = 0;
			if (f->type == MANDELBROT)
				mandelbrot(x, y, &iter, f);
			else if (f->type == JULIA)
				julia(x, y, &iter, f);
			if (iter == MAX_ITER)
				color = 0;
			else
				color = get_color(iter, MAX_ITER);
			my_mlx_put_pixel(&(f->mlx_data->mlx_img), x, y, color);
		}
	}
	mlx_put_image_to_window(f->mlx_data->mlx, f->mlx_data->mlx_window,
		f->mlx_data->mlx_img.img, 0, 0);
}
