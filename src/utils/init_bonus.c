/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:39:08 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/20 11:18:07 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

mlx_t	*init(void)
{
	mlx_t	*res;

	res = mlx_init(W, H, "fract'ol", true);
	if (!res)
		ft_error();
	mlx_set_window_limit(res, W, H, W, H);
	return (res);
}

void	init_env(t_env *env, int type, char **argv)
{
	mlx_t	*mlx;

	mlx = init();
	env->mlx = mlx;
	env->max_im = MAX_IM;
	env->min_im = MIN_IM;
	env->max_re = MAX_RE;
	env->min_re = MIN_RE;
	env->z_fact = 1;
	env->re_w = RE_W;
	env->im_h = IM_H;
	env->center_x = MAX_RE - RE_W;
	env->center_y = MAX_IM - IM_H;
	env->fract_type = type;
	env->color[0] = 0xA8D8B9FF;
	env->color[1] = 0xF3D37AFF;
	env->color[2] = 0xF0A202FF;
	env->color[3] = 0xD96C06FF;
	env->color[4] = 0x8F2D0CFF;
	julia_params(ft_atoi(argv[2]), env);
}

void	init_img(t_env *env)
{
	mlx_image_t	*fract;

	fract = mlx_new_image(env->mlx, W, H);
	env->img = fract;
	if (env->fract_type == MANDELBROT)
		execute_threads(env, fract_mandel_thread);
	else if (env->fract_type == JULIA)
		execute_threads(env, fract_julia_thread);
	else if (env->fract_type == BURNINGSHIP)
		execute_threads(env, fract_ship_thread);
	mlx_image_to_window(env->mlx, env->img, 0, 0);
}

void	ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
