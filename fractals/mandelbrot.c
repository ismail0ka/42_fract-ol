/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/05 22:33:03 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Calculate the number of iterations before the point escapes
void    mandelbrot(int x, int y, int *iter, t_fractal *fractal)
{
	t_complex c = { 
        .real = (x - WIDTH / 2.0) * 4.0 / (WIDTH / fractal->zoom) + fractal->o.real, 
        .imaginary = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT / fractal->zoom) + fractal->o.imaginary
    };
    t_complex z = { .real = 0, .imaginary = 0 };
    while (z.real*z.real + z.imaginary*z.imaginary <= 4 && *iter < MAX_ITER)
    {
        double temp = z.real*z.real - z.imaginary*z.imaginary + c.real;
        z.imaginary = 2*z.real*z.imaginary + c.imaginary;
        z.real = temp;
        (*iter)++;
    }
}