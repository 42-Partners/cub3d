/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:46:03 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/10 20:46:03 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_config(int map_fd, t_game *game);
int	validate_map(int map_fd, t_game *game);

void	validate_input(t_game *game, int argc, char *filename)
{
	char	*dot;
	int		map_fd;

	if (argc != 2)
		error_exit(game, "Usage: ./cub3d <map.cub>");
	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5) != 0)
		error_exit(game, "Invalid file format.");
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		error_exit(game, "Could not open the file.");
	if (!validate_config(map_fd, game))
		error_exit(game, ".cub file configuration is not correctly definined.");
	if (!validate_map(map_fd, game))
		error_exit(game, ".cub file	map definition is not correct.");
}

