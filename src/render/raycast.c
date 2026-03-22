/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 02:03:11 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/22 07:38:14 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	raycast(t_game *game)
{
	// mock de player
	double pos[2] = {8.5, 2.5};
	double dir[2] = {1.0, 0.0};
	
	// // fov
	double plane[2] = {0.0, 0.66};
	
	// ajustando angulo
	double angle = 3.14159265358979323846 / 2;
	dir[0] = cos(angle);
	dir[1] = sin(angle);

	// plano
	plane[0] = -dir[1] * 0.66;
	plane[1] =  dir[0] * 0.66;
	int i = -1;
	while (++i < WIDTH)
	{
		// calculando o raio
		double cameraX = 2 * i / (double)WIDTH - 1.0;
		double rayDir[2] = {dir[0] + plane[0] * cameraX, dir[1] + plane[1] * cameraX};
		if (fabs(rayDir[0]) < 1e-6)
			rayDir[0] = 1e-6;
		if (fabs(rayDir[1]) < 1e-6)
			rayDir[1] = 1e-6;

		//identificação de célula
		int map[2] = {floor(pos[0]), floor (pos[1])};

		// distância delta
		double deltaDis[2] = {1e30,1e30};
		if (rayDir[0] != 0)
			deltaDis[0] = fabs(1 / rayDir[0]);
		if (rayDir[1] != 0)
			deltaDis[1] = fabs(1 / rayDir[1]);

		// calcular step
		int step[2];
		double sideDist[2];
		if (rayDir[0] < 0) {
			step[0] = -1;
			sideDist[0] = (pos[0] - map[0]) * deltaDis[0];
		} else {
			step[0] = 1;
			sideDist[0] = (map[0] + 1.0 - pos[0]) *deltaDis[0];
		}
		if (rayDir[1] < 0) {
			step[1] = -1;
			sideDist[1] = (pos[1] - map[1]) * deltaDis[1];
		} else {
			step[1] = 1;
			sideDist[1] = (map[1] + 1.0 - pos[1]) *deltaDis[1];
		}

		// atingir parede mais prox
		bool hit = false;
		int side;
		while (!hit) {
			if (sideDist[0] < sideDist[1]) {
				sideDist[0] += deltaDis[0];
				map[0] += step[0];
				side = 0;
			} else {
				sideDist[1] += deltaDis[1];
				map[1] += step[1];
				side  = 1;
			}
			if (game->map.map[(map[1])][(map[0])] == '1')
				hit = true;
		}

		// distancia perpendicular (zoio de pexe)
		double perpWallDist;
		if (side == 0) {
			perpWallDist= (map[0] - pos[0] + (1 - step[0]) / 2) / rayDir[0];
		} else {
			perpWallDist= (map[1] - pos[1] + (1 - step[1]) / 2) / rayDir[1];
		}

		// desenhar paredes
		int lineHeight = HEIGHT / perpWallDist;
		int drawStart = -lineHeight / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
		int drawEnd = lineHeight / 2 + HEIGHT / 2 + CAMERA_HEIGHT;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		for (int y = drawStart; y <= drawEnd; y++)
			mlx_put_pixel(game->img, i, y, 0xFFFFFF);
	}
}
