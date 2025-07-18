/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:36:41 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/17 14:02:58 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

/*
	checking if information was saved
	getting the mlx with the command:
	git submodule update --init --recursive
	and the valgrind:
	valgrind --leak-check=full --track-origins=yes 
	--show-leak-kinds=all -s ./cub3D amazing.cub
	int cc = 0;
	while (info.map[cc] != NULL)
	{
		ft_printf("%s\n", info.map[cc]);
		cc++;
	}
	ft_printf("flag is set to = %d\n", info.player->orient);
	ft_printf("east path is '%s'\n", info.graphic->east_path);
	ft_printf("blue for floor is '%d'\n", info.graphic->floor_blue);
*/
/*
	leak checking with:
	static void	leaks(void)
	{
		system("leaks cub3D");
	}
	atexit(leaks);
*/

int	main(int ac, char **av)
{
	t_info	info;

	before_alloc(ac, av);
	initialization(av, &info);
	mlx_loop_hook(info.mlx, raycaster, &info);
	mlx_key_hook(info.mlx, key_hook, &info);
	mlx_loop(info.mlx);
	mlx_close_window(info.mlx);
	clean_textures(&info, 4);
	mlx_delete_image(info.mlx, info.img);
	mlx_terminate(info.mlx);
	bin_malloc(-1);
	return (EXIT_SUCCESS);
}
