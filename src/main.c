/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:53:38 by jlemieux          #+#    #+#             */
/*   Updated: 2023/03/15 18:12:24 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env			env;
	mlx_scrollfunc	scrollhook;
	mlx_cursorfunc	mousehook;
	void			(*keyhook)(void *);
	int				type;

	keyhook = &key_hook;
	mousehook = &mouse_hook;
	scrollhook = scroll_hook;
	type = valid_input(argc, argv);
	if (type < 1)
		return (EXIT_FAILURE);
	init_env(&env, type, argv);
	init_img(&env);
	mlx_scroll_hook(env.mlx, scroll_hook, &env);
	mlx_cursor_hook(env.mlx, mousehook, &env);
	mlx_loop_hook(env.mlx, keyhook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return (EXIT_SUCCESS);
}
