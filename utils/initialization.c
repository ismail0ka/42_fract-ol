/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:31:19 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/05 22:28:17 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_valid_float(const char *s)
{
	while (s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (*s == 0)
		return (0);
	while (s && ft_isdigit(*s))
		s++;
	if (*s == '.')
		s++;
	while (s && ft_isdigit(*s))
		s++;
	if (*s == 0)
		return (1);
	return (0);
}

void	win_init(t_mlx_data *mlx_data)
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

void	fractal_init(t_fractal *f, const char **av, int ac)
{
	if (ft_strncmp(av[1], "mandelbrot", 9) == 0)
		f->type = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		f->type = JULIA;
		if (ac == 2)
		{
			f->c.real = 0.285;
			f->c.imaginary = 0.01;
			return ;
		}
		else if (ac != 4)
			(write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), exit(EXIT_FAILURE));
		if (is_valid_float(av[2]) && is_valid_float(av[3]))
		{
			f->c.real = ft_atof(av[2]);
			f->c.imaginary = ft_atof(av[3]);
		}
		else
			(write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), exit(EXIT_FAILURE));
	}
	else
		(write(2, "Usage: ./fractol <Set> <julia param1> <julia param2>\n", 54), exit(EXIT_FAILURE));
}
