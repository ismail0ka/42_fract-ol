/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:33 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/08 18:22:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_init(t_fractal *fractal)
{
	if (!fractal)
	{
		write(2, "Memory allocation failed.\n", 25);
		exit(EXIT_FAILURE);
	}
	fractal->mlx_data = malloc(sizeof(t_mlx_data));
	if (!fractal->mlx_data)
	{
		free(fractal);
		write(2, "Memory allocation failed.\n", 25);
		exit(EXIT_FAILURE);
	}
	fractal->x = 0;
	fractal->y = 0;
	fractal->c.real = 0.0;
	fractal->c.imaginary = 0.0;
	fractal->zoom = 1.0;
}

int main(int ac, const char **av)
{
	t_fractal	*fractal;

	if (ac < 2)
		return (write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), EXIT_FAILURE);
	fractal = malloc(sizeof(t_fractal));
	(fractal_init(fractal), win_init(fractal->mlx_data));
	fractal_params(fractal, av, ac);
	render_fractal(fractal);
	mlx_mouse_hook(fractal->mlx_data->mlx_window, handle_mouse, fractal);
	mlx_key_hook(fractal->mlx_data->mlx_window, handle_esc, &(fractal->mlx_data));
	mlx_hook(fractal->mlx_data->mlx_window, 17, 0L, close_window, &(fractal->mlx_data));
	mlx_loop(fractal->mlx_data->mlx);
	return EXIT_SUCCESS;
}
