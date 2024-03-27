/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:36:57 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/27 16:14:58 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	split_destroy(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	my_mlx_pixel_put(t_fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void ft_print_menu(void)
{
	ft_printf("-------------\n");
	ft_printf("1.\t Choose M(Mandlebrot) or J(Julia)\n");
	ft_printf("2.\t Choose Position on x & y (float) ex : 0.35 0.76\n");
	ft_printf("3.\t Choose Hexadecimal color ex : EB34D8\n");
	ft_printf("-------------\n");
}
double	ft_atof(const char *s) // extrait la position sur x et y en input
{
	char **string;
	int flag;
	int i;
	int a;
	int b;
	int temp;
	int power;
	int neg;
	double result;
	i = 0;
	power = 0;
	flag = 0;
	neg = 1;
	while(s[i]) //check if param are more than one point
	{
		if(s[i] == '-')
			neg = -neg;
		if(s[i] == '.')
			flag += 1;
		if(flag > 1)
		{
			ft_printf("error, you should enter a correct parameter\n");
			exit(EXIT_FAILURE);
		}
		i++;	
	}
	string = ft_split(s,'.');
	a = ft_atoi(string[0]);
	b = ft_atoi(string[1]);
	temp = b;
	while(temp >= 1)
	{
		temp = temp / 10;
		power++;
	}
	split_destroy(string);
	return(result = a + (b / pow(10,power)) * neg);
}
int ft_hex_to_dec(char c) {
    if (c >= '0' && c <= '9') 
		return c - '0';
    c = ft_toupper(c);
    if (c >= 'A' && c <= 'F') return 10 + c - 'A';
    return -1;
}

int ft_extract_color(char *hex) {
    int result = 0;
	int i;
    int len;
	i = 0;
	len = ft_strlen(hex);
	while(i < len)
	{
        int dec = ft_hex_to_dec(hex[i]);
        if (dec >= 0) 
            result += dec * pow(16, len - 1 - i);
		i++;
	}
    return (result);
}


void ft_parser(t_fract *data)
{
	if(data->argc == 1)
	{
		ft_print_menu();
		exit(EXIT_FAILURE);
	}
	if(ft_strlen(data->argv[1]) > 1)
	{
		return; // display error message
	}
	if(data->argc > 1)
	{
		data->param_1 = ft_atof(data->argv[2]);
		data->param_2 = ft_atof(data->argv[3]);
		data->hex_color = ft_extract_color(data->argv[4]);
	}
	if(data->argv[1][0] == 'M')
	{
		//draw mandlrebot
	}
	if(data->argv[1][0] == 'J')
	{
		//draw julia
	}

}
int	ft_close(int keycode, t_fract *vars)
{
	if(keycode == XK_Escape)//65367
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
int	main(int argc, char **argv)
{
	t_fract data;
	data.argv = argv;
	data.argc = argc;
	int i = 960;
	ft_parser(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx,1920,1080,"Fractol");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	while(i < 1500) // test
	{
		my_mlx_pixel_put(&data, i, 540, data.hex_color);
		mlx_hook(data.mlx_win, 2, 1L<<0, ft_close, &data);
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img,0,0);
		i++;
	}
	mlx_loop(data.mlx);
}