/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:33 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/03 16:52:26 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	win_init(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		(write(2, "Mlx init failed.\n", 17), exit(EXIT_FAILURE));
	mlx_data->mlx_window = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "Playzaa");
	if (!mlx_data->mlx_window)
		(write(2, "Mlx window init failed.\n", 24), exit(EXIT_FAILURE));
	mlx_data->mlx_img.img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (!mlx_data->mlx_img.img)
		(write(2, "Mlx image init failed.\n", 23), exit(EXIT_FAILURE));
	mlx_data->mlx_img.addr = mlx_get_data_addr(mlx_data->mlx_img.img,
			&mlx_data->mlx_img.b_pp, &mlx_data->mlx_img.line_length,
			&mlx_data->mlx_img.endian);
}

/*static void	fractal_init(t_fractal *f, const char **av, int ac)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		f->type = MANDELBROT;
		f->min.real = -4.0;
		f->min.imaginary = -4.0;
		f->max.real = 4.0;
		f->max.imaginary = 4.0;
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		f->type = JULIA;
		if (ac != 4)
			(write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 55), exit(EXIT_FAILURE));
		f->c.real = ft_atof(av[2]);
		f->c.imaginary = ft_atof(av[3]);
		f->min.real = -2.0;
		f->min.imaginary = -2.0;
		f->max.real = 2.0;
		f->max.imaginary = 2.0;
	}
	else
		(write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 55), exit(EXIT_FAILURE));
}

static void	render_fractal(t_fractal *f, t_mlx_data *mlx_data)
{
	int x;
	int y;
	int i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (f->type == MANDELBROT)
				i = mandlebrot(f->z);
			else if (f->type == JULIA)
				i = julia(f->z, f->c);
			// Set pixel color based on i
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->mlx_img.img, 0, 0);
}*/

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->b_pp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_fractal(t_fractal *f, t_mlx_data *mlx_data)
{
	int x;
	int y;
	int i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (f->type == MANDELBROT)
				i = mandlebrot(f->z);
			else if (f->type == JULIA)
				i = julia(f->z, f->c);
			my_mlx_pixel_put(&mlx_data->mlx_img, x, y, i);
			x++;
		}
		y++;
	}
}

int main(int ac, const char **av)
{
	t_mlx_data	mlx_data;
	t_fractal	fractal;

	if (ac < 2 && **av == 'f')
		return (write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), EXIT_FAILURE);
	win_init(&mlx_data);
	for (int i=WIDTH/2; i<WIDTH; i++)
	{
		for (int j=0; j<HEIGHT; j++)
			my_mlx_pixel_put(&mlx_data.mlx_img, i, j, 0x00FF0000);
	}
	fractal_init(&fractal, av, ac);
	draw_fractal(&fractal, &mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_window, mlx_data.mlx_img.img, 0, 0);
	mlx_loop(mlx_data.mlx);
	//render_fractal(&fractal, &mlx_data);
	return EXIT_SUCCESS;
}