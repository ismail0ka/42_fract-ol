/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:30 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/03 17:43:35 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_fractal *fractal)
{
	t_complex z = { .real = (x - WIDTH/2.0)*4.0/WIDTH, .imaginary = (y - HEIGHT/2.0)*4.0/HEIGHT };
	t_complex c = fractal->c;

	int iter = 0;
	while (z.real*z.real + z.imaginary*z.imaginary <= 4 && iter < MAX_ITER)
	{
		double temp = z.real*z.real - z.imaginary*z.imaginary + c.real;
		z.imaginary = 2*z.real*z.imaginary + c.imaginary;
		z.real = temp;
		iter++;
	}
	return (iter);
}