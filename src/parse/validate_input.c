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
#include <limits.h>

#include <limits.h>

void		validate_config(t_game *game);
static void	parse_map(t_game *game);
static void	fill_map(t_game *game, char *line, int map_fd);
static void	set_map_size(t_game *game);
static bool	add_row(t_game *game, char *row);

void	validate_input(t_game *game, int argc, char *filename)
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
	set_map_size(game);
	close(game->map.map_fd);
	game->map.map_fd = -1;
}

static void	parse_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->map.map_fd);
	game->map.map = ft_calloc(1, sizeof (char *));
	if (!game->map.map)
		error_exit(game, "Malloc error");
	while (line && ft_strcmp("\n", line) == 0)
	{
		free(line);
		line = get_next_line(game->map.map_fd);
	}
	fill_map(game, line, game->map.map_fd);
	clean_gnl(game->map.map_fd);
}

static void	fill_map(t_game *game, char *line, int map_fd)
{
	char	*trimmed;

	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			error_exit(game, "Malloc error");
		if (*trimmed == '\0')
		{
			free(trimmed);
			break ;
		}
		else if (!add_row(game, trimmed))
			error_exit(game, "Malloc error");
		line = get_next_line(map_fd);
	}
}

static bool	add_row(t_game *game, char *row)
{
	int		i;
	char	**new_map;

	i = 0;
	while (game->map.map[i])
		i++;
	new_map = ft_realloc(
			game->map.map, sizeof(char *) * i, sizeof(char *) * (i + 2));
	if (!new_map)
	{
		ft_free_arr(&game->map.map);
		return (false);
	}
	game->map.map = new_map;
	game->map.map[i] = row;
	game->map.map[i + 1] = NULL;
	return (true);
}

static void	set_map_size(t_game *game)
{
	int	max_y;
	int	y;
	int	x;

	x = 0;
	max_y = 0;
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y] && game->map.map[x][y] != '\n')
		{
			if (y == INT_MAX - 10)
				error_exit(game, "Map too big");
			if (y > max_y)
				max_y = y;
			y++;
		}
		if (x == INT_MAX - 10)
			error_exit(game, "Map too big");
		x++;
	}
	if (max_y < 2 || x < 2)
		error_exit(game, "Invalid map");
	game->map.rows = x;
	game->map.cols = max_y + 1;
}
