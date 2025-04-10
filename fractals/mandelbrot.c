/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/10 01:17:43 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, int *iter, t_fractal *fractal)
{
	double		aspect_ratio;
	double		temp;
	t_complex	z;
	t_complex	c;

	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	c.real = (x - WIDTH / 2.0) * 4.0
		/ (WIDTH / fractal->zoom) + fractal->o.real;
	c.imaginary = (y - HEIGHT / 2.0) * 4.0
		/ (HEIGHT / fractal->zoom * aspect_ratio) + fractal->o.imaginary;
	z.real = 0;
	z.imaginary = 0;
	while (z.real * z.real + z.imaginary * z.imaginary <= 4 && *iter < MAX_ITER)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		(*iter)++;
	}
}
