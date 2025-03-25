/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:33 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/25 23:12:00 by ikarouat         ###   ########.fr       */
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
	
int main()//int ac, const char **av)
{
	void	*mlx;
	void	*mlx_window;
	void	*mlx_img;

	mlx = mlx_init();
	if (!mlx)
		(write(2, "Mlx init failed.\n", 17), exit(EXIT_FAILURE));
	mlx_window = mlx_new_window(mlx, 1024, 1024, "Playzaa");
	if (!mlx_window)
		(write(2, "Mlx window init failed.\n", 24), exit(EXIT_FAILURE));
	mlx_img = mlx_new_image(mlx, 1024, 1024);
	if (!mlx_img)
		(write(2, "Mlx image init failed.\n", 23), exit(EXIT_FAILURE));
	
	return EXIT_SUCCESS;
}