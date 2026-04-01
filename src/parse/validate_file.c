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

void		validate_config(t_game *game);
void		parse_map(t_game *game);
static void	check_after_map(t_game *game);

void	validate_file(t_game *game, int argc, char *filename)
{
	char	*dot;

	if (argc != 2)
		error_exit(game, "Usage: ./cub3d <map.cub>");
	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5) != 0)
		error_exit(game, "Invalid file format");
	game->map.map_fd = open(filename, O_RDONLY);
	if (game->map.map_fd == -1)
		error_exit(game, "Could not open the file");
	validate_config(game);
	parse_map(game);
	check_after_map(game);
	close(game->map.map_fd);
	game->map.map_fd = -1;
}

static void	check_after_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->map.map_fd);
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			free(line);
			error_exit(game, "Invalid content after map");
		}
		free(line);
		line = get_next_line(game->map.map_fd);
	}
}
