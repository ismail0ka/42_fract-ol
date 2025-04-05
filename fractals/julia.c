/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:30 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/05 22:32:44 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int x, int y, int *iter,t_fractal *fractal)
{
	t_complex z = { 
		.real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractal->zoom) + fractal->o.real,
		.imaginary = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractal->zoom) + fractal->o.imaginary
	};
	t_complex c = fractal->c;

	while (z.real*z.real + z.imaginary*z.imaginary <= 4 && *iter < MAX_ITER)
	{
		double temp = z.real*z.real - z.imaginary*z.imaginary + c.real;
		z.imaginary = 2*z.real*z.imaginary + c.imaginary;
		z.real = temp;
		(*iter)++;
	}
}