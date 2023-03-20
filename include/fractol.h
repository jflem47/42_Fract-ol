/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:10:00 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/20 14:26:03 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "MLX42/MLX42.h"
# include <complex.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define W 1000
# define H 1000

# define MIN_RE -2.5
# define MAX_RE 2.5
# define MIN_IM -2.5
# define MAX_IM 2.5
# define IM_H 5.0
# define RE_W 5.0

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

typedef struct s_mandel
{
	double		x0;
	double		y0;
	double		x;
	double		y;
	double		x2;
	double		y2;
}				t_mandel;

typedef struct s_env
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		z_fact;
	double		im_h;
	double		re_w;
	double		m_xpos;
	double		m_ypos;
	double		center_x;
	double		center_y;
	int			fract_type;
	int			color[5];
	double		j_x;
	double		j_y;
}				t_env;

typedef enum e_updated
{
	LEFT,
	RIGHT,
	UP,
	DOWN
}				t_updated;

int				valid_input(int ac, char **av);
void			display_options(void);
mlx_t			*init(void);
void			ft_error(void);
void			fract_mandel(mlx_image_t *img, unsigned int i, t_env *env);
void			key_hook(void *param);
void			init_env(t_env *env, int type, char **argv);
void			init_img(t_env *env);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			mouse_hook(double xpos, double ypos, void *param);
void			zoom(t_env *env, double posx, double posy, double zoomFactor);
void			fract_julia(mlx_image_t *img, unsigned int i, t_env *env);
void			set_colors(t_env *env, int type);

void			julia_params(int type, t_env *env);

#endif
