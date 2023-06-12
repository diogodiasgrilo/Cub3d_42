/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:38:05 by diogpere          #+#    #+#             */
/*   Updated: 2023/06/12 16:53:54 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/raycasting.h"

// void    anti_aliasing_top_left(t_game *g)
// {
//     int x_i;
//     int	y_i;
//     int x;
// 	int y;
    
// 	x = -1;
// 	while (++x < WIDTH)
// 	{
// 		y = -1;
// 		while (++y < HEIGHT)
// 		{
// 			if ((*(unsigned int*)(g->scene.data + ((y * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 4278190080 && \
// 				(*(unsigned int*)(g->scene.data + (((y + 1) * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 16777215)
// 			{
// 				x_i = x;
// 				y_i = y + 1;
// 				if (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i + 1) * (g->scene.bpp / 8)))) == 4278190080 && y_i < HEIGHT)
// 				{
// 					while (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i + 1) * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && y_i < HEIGHT)
// 						y_i++;
// 					x_i++;
// 					while (*(unsigned int*)(g->scene.data + (((y_i - 1) * g->scene.size_line) + (x_i * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && x_i < WIDTH)
// 						x_i++;
// 					if (abs(x_i - x) < 20 && abs(y_i - y) < 20)
// 						while (y < y_i)
// 							draw_simple_line(g, x, (y++) + 1, x_i - 1, y_i, NEWWHITE);
// 				}
//                 break;
// 			}
// 		}
// 	}
// }

// void    anti_aliasing_bottom_left(t_game *g)
// {
//     int x_i;
//     int	y_i;
//     int x;
// 	int y;
    
// 	x = -1;
// 	while (++x < WIDTH)
// 	{
// 		y = -1;
// 		while (++y < HEIGHT)
// 		{
// 			if (y > 0 && (*(unsigned int*)(g->scene.data + ((y * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 4278190080 && \
// 				(*(unsigned int*)(g->scene.data + (((y - 1) * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 16777215)
// 			{
// 				x_i = x;
// 				y_i = y - 1;
// 				if (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i + 1) * (g->scene.bpp / 8)))) == 4278190080 && y_i < HEIGHT)
// 				{
// 					while (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i + 1) * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && y_i < HEIGHT)
// 						y_i--;
// 					x_i++;
// 					while (*(unsigned int*)(g->scene.data + (((y_i + 1) * g->scene.size_line) + (x_i * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && x_i < WIDTH)
// 						x_i++;
// 					if (abs(x_i - x) < 20 && abs(y_i - y) < 20)
// 						while (y > y_i + 1)
// 							draw_simple_line(g, x, (y--) - 1, x_i - 1, y_i, NEWWHITE);
// 				}
//                 break;
// 			}
// 		}
// 	}
// }

// void    anti_aliasing_top_right(t_game *g)
// {
//     int x_i;
//     int	y_i;
//     int x;
// 	int y;
    
// 	x = WIDTH;
// 	while (--x >= 0)
// 	{
// 		y = HEIGHT;
// 		while (--y >= 0)
// 		{
// 			if ((*(unsigned int*)(g->scene.data + ((y * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 4278190080 && \
// 				(*(unsigned int*)(g->scene.data + (((y + 1) * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 16777215)
// 			{
// 				x_i = x;
// 				y_i = y + 1;
// 				if (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i - 1) * (g->scene.bpp / 8)))) == 4278190080 && y_i < HEIGHT)
// 				{
// 					while (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i - 1) * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && y_i < HEIGHT)
// 						y_i++;
// 					x_i--;
// 					while (*(unsigned int*)(g->scene.data + (((y_i - 1) * g->scene.size_line) + (x_i * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && x_i < WIDTH)
// 						x_i--;
// 					if (abs(x_i - x) < 20 && abs(y_i - y) < 20)
// 						while (y < y_i)
// 							draw_simple_line(g, x, (y++) + 1, x_i + 1, y_i, NEWWHITE);
// 				}
//                 break;
// 			}
// 		}
// 	}
// }

// void    anti_aliasing_bottom_right(t_game *g)
// {
//     int x_i;
//     int	y_i;
//     int x;
// 	int y;
    
// 	x = WIDTH;
// 	while (--x >= 0)
// 	{
// 		y = HEIGHT;
// 		while (--y >= 0)
// 		{
// 			if (y > 0 && (*(unsigned int*)(g->scene.data + ((y * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 4278190080 && \
// 				(*(unsigned int*)(g->scene.data + (((y - 1) * g->scene.size_line) + (x * (g->scene.bpp / 8))))) == 16777215)
// 			{
// 				x_i = x;
// 				y_i = y - 1;
// 				if (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i - 1) * (g->scene.bpp / 8)))) == 4278190080 && y_i < HEIGHT)
// 				{
// 					while (*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i - 1) * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && y_i < HEIGHT)
// 						y_i--;
// 					x_i--;
// 					while (*(unsigned int*)(g->scene.data + (((y_i + 1) * g->scene.size_line) + (x_i * (g->scene.bpp / 8)))) == 4278190080 && \
// 						*(unsigned int*)(g->scene.data + ((y_i * g->scene.size_line) + ((x_i) * (g->scene.bpp / 8)))) == 16777215 && x_i < WIDTH)
// 						x_i--;
// 					if (abs(x_i - x) < 20 && abs(y_i - y) < 20)
// 						while (y > y_i + 1)
// 							draw_simple_line(g, x, (y--) - 1, x_i + 1, y_i, NEWWHITE);
// 				}
//                 break;
// 			}
// 		}
// 	}
// }