/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/03 16:53:37 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Calculate the number of iterations before the point escapes
int	mandlebrot(t_complex z)
{
	int			i;
	int			color;
	t_complex	z;

	color = 0x00FF0000;
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (pow(z.real, 2) + pow(z.imaginary, 2) > 4)
			break ;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = pow(z.real, 2) - pow(z.imaginary, 2) + c.real;
		i++;
	}
	return (color);
}