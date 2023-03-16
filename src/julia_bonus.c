/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:25:32 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/16 15:25:58 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	calculate_julia(t_mandel *vals)
{
	vals->y = 2 * vals->x * vals->y + vals->y0;
	vals->x = vals->x2 - vals->y2 + vals->x0;
	vals->x2 = vals->x * vals->x;
	vals->y2 = vals->y * vals->y;
}

static void	init_vals(t_mandel *vals, unsigned int px, unsigned int py,
		t_env *env)
{
	vals->x0 = env->j_x;
	vals->y0 = env->j_y;
	vals->x = (env->min_re) + px * ((env->max_re) - (env->min_re)) / W;
	vals->y = (env->max_im) - py * ((env->max_im) - (env->min_im)) / H;
	vals->x2 = vals->x * vals->x;
	vals->y2 = vals->y * vals->y;
}

static void	color_julia(t_env *env, unsigned int i, unsigned int px,
		unsigned int py)
{
	int	palette[5];

	palette[0] = env->color[0];
	palette[1] = env->color[1];
	palette[2] = env->color[2];
	palette[3] = env->color[3];
	palette[4] = env->color[4];
	mlx_put_pixel(env->img, px, py, palette[(i - 1) % 5]);
}

static void	plot_julia(unsigned int i, t_env *env, int px, int py)
{
	unsigned int	iter;
	t_mandel		vals;

	init_vals(&vals, px, py, env);
	iter = 0;
	while (iter++ < i && (vals.x2 + vals.y2) <= 4)
		calculate_julia(&vals);
	if (iter < i + 1)
		color_julia(env, iter, px, py);
	else
		mlx_put_pixel(env->img, px, py, 0x000000FF);
}

void	*fract_julia_thread(void *t_data)
{
	int				px;
	int				py;
	t_thread_data	*data;

	data = t_data;
	px = 0;
	py = data->id * 200;
	while (py < (data->id + 1) * 200)
	{
		px = 0;
		while (px < W)
		{
			plot_julia(100, data->env, px, py);
			px++;
		}
		py++;
	}
	return (NULL);
}
