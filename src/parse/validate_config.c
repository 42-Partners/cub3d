/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:12:23 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/21 23:46:13 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_all(bool checks[6]);
static bool	validate_line(t_game *game, char *line, bool checks[6]);
static void	parse_config(t_game *game, char *line, int flag);

/* bool array checks every config following the table below: */
// checks[0] = NO;
// checks[1] = SO;
// checks[2] = WE;
// checks[3] = EA;
// checks[4] = floor;
// checks[5] = ceeling;
// REMINDER: free all alocated configs when line 56 becomes true
void	validate_config(t_game *game)
{
	char	*line;
	char	*aux;
	bool	checks[6];

	ft_memset(checks, 0, sizeof(checks));
	line = get_next_line(game->map.map_fd);
	while (line && !check_all(checks))
	{
		aux = ft_strtrim(line, " \t\n");
		free(line);
		if (!aux)
			error_exit(game, "Malloc error");
		if (!validate_line(game, aux, checks))
		{
			clean_gnl(game->map.map_fd);
			free(aux);
			error_exit(game, "Invalid configuration");
		}
		free(aux);
		line = get_next_line(game->map.map_fd);
	}
	free(line);
	if (!check_all(checks))
		error_exit(game, "Incomplete configuration");
}

/* start parsing here */
static bool	validate_line(t_game *game, char *line, bool checks[6])
{
	int	check_num;

	check_num = -1;
	if (ft_strncmp("SO", line, 2) == 0)
		check_num = 0;
	else if (ft_strncmp("NO", line, 2) == 0)
		check_num = 1;
	else if (ft_strncmp("WE", line, 2) == 0)
		check_num = 2;
	else if (ft_strncmp("EA", line, 2) == 0)
		check_num = 3;
	else if (ft_strncmp("F", line, 1) == 0)
		check_num = 4;
	else if (ft_strncmp("C", line, 1) == 0)
		check_num = 5;
	else if (*line == '\0')
		return (true);
	else
		return (false);
	if (checks[check_num])
		return (false);
	checks[check_num] = true;
	parse_config(game, line, check_num);
	return (true);
}

static bool	check_all(bool checks[6])
{
	int		i;

	i = 0;
	while (i < 6 && checks[i])
		i++;
	return (i == 6);
}

static void	parse_config(t_game *game, char *line, int flag)
{
	if (flag == 0)
		(void)game;
	else if (flag == 1)
		(void)game;
	else if (flag == 2)
		(void)game;
	else if (flag == 3)
		(void)game;
	else if (flag == 4 || flag == 5)
		parse_color(game, line);
}
