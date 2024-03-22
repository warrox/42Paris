/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:36:57 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/22 13:17:28 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
// int main (int argc, char **argv)
// {
// 	(void)argc;
// 	(void) argv;
// 	void *mlx;
// 	void *mlx_win;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx,1920,1080,"Hello world!");
// 	mlx_loop(mlx);
	
// }

int	main(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}