/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:52:48 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/15 17:59:21 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_input(int ac, char **av)
{
	if (ac == 1)
		return (display_options(), 0);
	else if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(av[1], "Julia", 6) == 0)
		return (JULIA);
	else
		return (-1);
}

void	julia_params(int type, t_env *env)
{
	if (type == 2)
	{
		env->j_x = -1.037;
		env->j_y = 0.17;
	}
	else if (type == 3)
	{
		env->j_x = -0.624;
		env->j_y = 0.435;
	}
	else
	{
		env->j_x = -0.8;
		env->j_y = 0.2;
	}
}

void	display_options(void)
{
	ft_putendl_fd("Entrez le type de fractale:", 1);
	ft_putendl_fd("Mandelbrot", 1);
	ft_putendl_fd("Julia", 1);
}
