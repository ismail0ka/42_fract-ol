/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:33 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/04 01:09:00 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, const char **av)
{
	t_mlx_data	mlx_data;
	t_fractal	fractal;

	if (ac < 2)
		return (write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), EXIT_FAILURE);
	(win_init(&mlx_data), fractal_init(&fractal, av, ac));
	render_fractal(&mlx_data, &fractal);
	mlx_loop(mlx_data.mlx);
	return EXIT_SUCCESS;
}