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

int	validate_map(t_game *game, char *filename);

void	validate_input(t_game *game, int argc, char *filename)
{
	char	*dot;

	if (argc != 2)
		error_exit(game, "Usage: ./cub3d <map.cub>");
	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5) != 0)
		error_exit(game, "Invalid file format.");
	validate_map(game, filename);
}
