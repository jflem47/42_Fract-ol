/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:04:51 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/16 19:49:07 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	execute_threads(t_env *env, void *(*f)(void *))
{
	int				i;
	t_thread_data	t_data[5];
	pthread_t		threads[5];

	i = 0;
	while (i < 5)
	{
		t_data[i].env = env;
		t_data[i].id = i;
		pthread_create(&threads[i], NULL, f, &t_data[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
