/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:33 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/31 20:49:23 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Usage: ./fractol <Set> <julia param1> <julia param2>
//Rendering
	//Julia set
	//Mandlebrot set
	//Bonus: Romanseco brocolli
	//Zoom +/- using mouse
	//Use Colors to reveal fractals depths
//Graphical managment
	//smooth window managment
	//clicking the window cross or ESC exits program cleanly
static void	my_mlx_put_pixel(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->b_pp / 8));
	*(unsigned int *)dst = color;
}

static void	init(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		(write(2, "Mlx init failed.\n", 17), exit(EXIT_FAILURE));
	mlx_data->mlx_window = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "Playzaa");
	if (!mlx_data->mlx_window)
		(write(2, "Mlx window init failed.\n", 24), exit(EXIT_FAILURE));
	//mlx_data->mlx_img.img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	//if (!mlx_data->mlx_img.img)
	//	(write(2, "Mlx image init failed.\n", 23), exit(EXIT_FAILURE));
	//mlx_data->mlx_img.addr = mlx_get_data_addr(mlx_data->mlx_img.img, &mlx_data->mlx_img.b_pp, &mlx_data->mlx_img.line_length, &mlx_data->mlx_img.endian);	
	//mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_window, mlx_data->mlx_img.img, 0, 0);
	//mlx_loop(mlx_data->mlx);
}

int main(int ac, const char **av)
{
	t_mlx_data	mlx_data;
	//t_fractal	fractal;
	
	if (ac < 2)
		return (write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 55), EXIT_FAILURE);
	init(&mlx_data);
	my_mlx_put_pixel(mlx_data.mlx_img.img, 10, 10, 0);
	return EXIT_SUCCESS;
}