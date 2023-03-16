/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:26:56 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/16 16:29:15 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_env *env, double posx, double posy, double zoomFactor)
{
	double	interpolation;

	interpolation = 1.0 / zoomFactor;
	env->min_re = interpolate(posx, env->min_re, interpolation);
	env->min_im = interpolate(posy, env->min_im, interpolation);
	env->max_re = interpolate(posx, env->max_re, interpolation);
	env->max_im = interpolate(posy, env->max_im, interpolation);
}

void	set_colors(t_env *env, int type)
{
	if (type == 1)
	{
		env->color[0] = 0xA8D8B9FF;
		env->color[1] = 0xF3D37AFF;
		env->color[2] = 0xF0A202FF;
		env->color[3] = 0xD96C06FF;
		env->color[4] = 0x8F2D0CFF;
	}
	else if (type == 2)
	{
		env->color[0] = 0x0CB3A2FF;
		env->color[1] = 0x8BCAD7FF;
		env->color[2] = 0x56A191FF;
		env->color[3] = 0x506D90FF;
		env->color[4] = 0x375F73FF;
	}
	else if (type == 3)
	{
		env->color[0] = 0xFFFFFFAA;
		env->color[1] = 0xFFFFFFBB;
		env->color[2] = 0xFFFFFFCC;
		env->color[3] = 0xFFFFFFDD;
		env->color[4] = 0xFFFFFFEE;
	}
}
