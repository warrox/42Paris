/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:36:51 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/27 16:12:58 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_LIB_H
# define FRACTOL_LIB_H
#include "libft.h"
#include "../Printf/ft_printf.h"
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
typedef struct s_fract
{
	int  x;
	int	 y;
	double param_1;
	double param_2;
	int argc;
	void *mlx;
	void *mlx_win;
	void	*img;
	char	*addr;
	char 	**argv;
	int 	hex_color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fract;
#endif
