/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:12:23 by gustaoli          #+#    #+#             */
/*   Updated: 2026/03/14 02:37:04 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_all(bool checks[6]);
static int	validate_line(char *line, t_game *game, bool checks[6]);

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
	bool	checks[6];
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	while (i < 6)
		checks[i++] = false;
	line = get_next_line(map_fd);
	while (line && !check_all(checks))
	{
		aux = ft_strtrim(line, " \t");
		free(line);
		if (!aux)
		{
			return (false);
		}
		if (validate_line(aux, game, checks) == -1)
			return (false);
		line = get_next_line(map_fd);
	}
	return (check_all(checks));
}

/* start parsing here */
static int	validate_line(char *line, t_game *game, bool checks[6])
{
	int	check_num;

	(void)game;
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
	else if (ft_strcmp("\n", line) != -3)
		return (-1);
	if (checks[check_num])
		return (-1);
	else if (check_num != -1)
		checks[check_num] = true;
	else
		return (false);
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
