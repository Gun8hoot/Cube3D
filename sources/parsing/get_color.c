/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:36:51 by nclavel           #+#    #+#             */
/*   Updated: 2026/04/21 09:36:55 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

ssize_t	check_number(char *number)
{
	size_t	i;
	ssize_t	comma;

	i = 0;
	comma = 0;
	while (number[i])
	{
		while (number[i] == ' ')
			i++;
		while (ft_isdigit(number[i]))
			i++;
		while (number[i] == ' ')
			i++;
		if (number[i] == ',')
		{
			comma++;
			i++;
		}
		else if (number[i])
			return (fprintf(stderr, COLOR_ERROR, number), -1);
		if (comma > 2)
			return (fprintf(stderr, COLOR_ERROR, number), -1);
	}
	return (comma);
}

bool	init_color(int **color, char *line, t_vec *vec)
{
	ft_memset(vec, '\0', sizeof(t_vec));
	*color = ft_calloc(1, sizeof(int));
	if (!*color)
		return (fprintf(stderr, ALLOC_ERROR), false);
	while (ft_isalpha(line[vec->x]) || line[vec->x] == ' ')
		vec->x++;
	if (check_number(&line[vec->x]) < 0)
		return (free(*color), *color = NULL, false);
	return (true);
}

bool	rgbtoi(int **color, char *line, t_vec *vec, int *shift)
{
	char	number[4];

	ft_memset(&number, '\0', sizeof(char) * 4);
	ft_strlcpy(number, &line[vec->x], vec->y + 1);
	if (ft_strlen(number) > 3 || ft_atoi(number) < 0 || ft_atoi(number) > 255)
		return (ft_fprintf(STDERR_FILENO, OOB_ERROR), false);
	**color += ft_atoi(number) << *shift;
	shift -= 8;
	return (true);
}

bool	get_color(int **color, char *line)
{
	int		shift;
	t_vec	vec;

	shift = 16;
	if (!init_color(color, line, &vec))
		return (false);
	while (line[vec.x])
	{
		vec.y = 0;
		while (ft_isspace(line[vec.x]))
			vec.x++;
		while (line[vec.x + vec.y] && ft_isdigit(line[vec.x + vec.y]))
			vec.y++;
		while (ft_isspace(line[vec.x + vec.y]))
			vec.x++;
		if (line[vec.x + vec.y] != ',' && line[vec.x + vec.y] != '\0')
			return (false);
		if (!rgbtoi(color, line, &vec, &shift))
			return (false);
		if (line[vec.x + vec.y] == '\0')
			vec.x += vec.y;
		else
			vec.x += vec.y + 1;
	}
	return (true);
}
