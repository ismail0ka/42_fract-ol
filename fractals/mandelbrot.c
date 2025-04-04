/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/04 01:05:50 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Calculate the number of iterations before the point escapes
int	mandelbrot(int x, int y)
{
	int iter = 0;

	t_complex c = { .real = (x - WIDTH/2.0)*4.0/WIDTH, .imaginary = (y - HEIGHT/2.0)*4.0/HEIGHT };
    t_complex z = { .real = 0, .imaginary = 0 };
    while (z.real*z.real + z.imaginary*z.imaginary <= 4 && iter < MAX_ITER)
    {
        double temp = z.real*z.real - z.imaginary*z.imaginary + c.real;
        z.imaginary = 2*z.real*z.imaginary + c.imaginary;
        z.real = temp;
        iter++;
    }
	return (iter);
}