/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:12:23 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/20 01:26:44 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_all(bool checks[6]);
static bool	validate_line(char *line, t_game *game, bool checks[6]);
static bool	parse_config(t_game *game, char *line, int flag);
static void	clean_gnl(int fd);

/* bool array checks every config following the table below: */
// checks[0] = NO;
// checks[1] = SO;
// checks[2] = WE;
// checks[3] = EA;
// checks[4] = floor;
// checks[5] = ceeling;
// REMINDER: free all alocated configs when line 56 becomes true
int	validate_config(int map_fd, t_game *game)
{
	char	*line;
	char	*aux;
	bool	checks[6];

	ft_memset(checks, 0, sizeof(checks));
	line = get_next_line(map_fd);
	while (line && !check_all(checks))
	{
		aux = ft_strtrim(line, " \t");
		free(line);
		if (!aux)
			error_exit(game, "Malloc.");
		if (!validate_line(aux, game, checks))
		{
			clean_gnl(map_fd);
			return (free(aux), false);
		}
		free(aux);
		line = get_next_line(map_fd);
	}
	return (free(line), check_all(checks));
}

/* start parsing here */
static bool	validate_line(char *line, t_game *game, bool checks[6])
{
	int	check_num;

	check_num = -1;
	if (ft_strncmp("SO", line, 2) == 0)
		check_num = 0;
	else if (ft_strncmp("NO ", line, 2) == 0)
		check_num = 1;
	else if (ft_strncmp("WE ", line, 2) == 0)
		check_num = 2;
	else if (ft_strncmp("EA ", line, 2) == 0)
		check_num = 3;
	else if (ft_strncmp("F ", line, 1) == 0)
		check_num = 4;
	else if (ft_strncmp("C ", line, 1) == 0)
		check_num = 5;
	else if (*line == '\n')
		return (true);
	else
		return (false);
	if (checks[check_num])
		return (false);
	else if (check_num != -1)
		checks[check_num] = true;
	return (parse_config(game, line, check_num));
}

static bool	check_all(bool checks[6])
{
	int		i;

	i = 0;
	while (i < 6 && checks[i])
		i++;
	return (i == 6);
}

static bool	parse_config(t_game *game, char *line, int flag)
{
	if (flag < 4)
		parse_textures(game, line + 3, flag);
	else if (flag == 4 || flag == 5)
		return (parse_color(game, line));
	return (true);
}

static void	clean_gnl(int fd)
{
	char	*aux;

	aux = get_next_line(fd);
	while (aux)
	{
		free(aux);
		aux = get_next_line(fd);
	}
}
