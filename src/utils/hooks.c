/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:48:15 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/16 16:30:04 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_vals_key(t_env *env, t_updated updated)
{
	if (updated == UP)
	{
		env->max_im += 0.1 * env->z_fact;
		env->min_im += 0.1 * env->z_fact;
	}
	if (updated == DOWN)
	{
		env->max_im -= 0.1 * env->z_fact;
		env->min_im -= 0.1 * env->z_fact;
	}
	if (updated == LEFT)
	{
		env->max_re -= 0.1 * env->z_fact;
		env->min_re -= 0.1 * env->z_fact;
	}
	if (updated == RIGHT)
	{
		env->max_re += 0.1 * env->z_fact;
		env->min_re += 0.1 * env->z_fact;
	}
}

static void	update_vals_scroll(t_env *env, int direction)
{
	env->center_x = env->m_xpos / (W / (env->max_re - env->min_re))
		+ env->min_re;
	env->center_y = env->m_ypos / (H / (env->max_im - env->min_im))
		+ env->min_im;
	if (direction == 1)
		env->z_fact /= 1.15;
	if (direction == 0)
		env->z_fact *= 1.15;
}

void	mouse_hook(double xpos, double ypos, void *param)
{
	t_env	*env;

	env = param;
	env->m_xpos = xpos;
	env->m_ypos = ypos;
}

void	key_hook(void *param)
{
	t_env	*env;

	env = param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
		update_vals_key(env, UP);
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
		update_vals_key(env, DOWN);
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		update_vals_key(env, LEFT);
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		update_vals_key(env, RIGHT);
	if (mlx_is_key_down(env->mlx, MLX_KEY_1))
		set_colors(env, 1);
	if (mlx_is_key_down(env->mlx, MLX_KEY_2))
		set_colors(env, 2);
	if (mlx_is_key_down(env->mlx, MLX_KEY_3))
		set_colors(env, 3);
	mlx_delete_image(env->mlx, env->img);
	init_img(env);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_env	*env;
	int		direction;

	direction = 0;
	(void)xdelta;
	env = param;
	if (ydelta > 0)
	{
		direction = 1;
		zoom(env, env->center_x, env->center_y, 1.2);
	}
	else if (ydelta < 0)
	{
		direction = 0;
		zoom(env, env->center_x, env->center_y, 1.0 / 1.2);
	}
	update_vals_scroll(env, direction);
	mlx_delete_image(env->mlx, env->img);
	init_img(env);
}
