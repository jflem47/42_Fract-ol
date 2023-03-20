/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:13 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/20 14:26:35 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractol.h"
# include "pthread.h"

typedef struct s_thread_data {
	t_env	*env;
	double	id;
}	t_thread_data;

void	*fract_mandel_thread(void *t_data);
void	*fract_julia_thread(void*t_data);
void	*fract_ship_thread(void *t_data);
void	execute_threads(t_env *env, void*(*f)(void *));

#endif
