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

#include "libft.h"
#include <fcntl.h>

int	validate_arg(char *filename)
{
	char	*dot;
	int		map_fd;

	dot = ft_strrchr(filename, '.');
	if (ft_strlen(dot) != 4 || !*(ft_strnstr(dot, ".cub", 5)))
	{
		ft_printf("Invalid file format.\n");
		return (1);
	}
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		ft_printf("Could not open the file!\n");
	close(map_fd);
	return (0);
}
