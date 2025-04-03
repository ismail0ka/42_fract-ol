/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:47:46 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/03 15:06:11 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"

#define HEIGHT 600
#define WIDTH 900
#define MAX_ITER 100

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		b_pp;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*mlx_window;
	t_mlx_img	mlx_img;
}	t_mlx_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}	t_fractal_type;

typedef struct s_fractal{
	t_fractal_type	type;
	t_complex		z;
	t_complex		c;
	t_complex		min;
	t_complex		max;
	int				color;
}	t_fractal;

#endif //FRACTOL_H