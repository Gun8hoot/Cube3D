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

bool	init_color(int **color, char *line, size_t *i)
{
	*i = 0;
	*color = ft_calloc(1, sizeof(int));
	if (!*color)
		return (fprintf(stderr, ALLOC_ERROR), false);
	while (ft_isalpha(line[*i]) || line[*i] == ' ')
		(*i)++;
	if (check_number(&line[*i]) < 0)
		return (free(*color), *color = NULL, false);
	return (true);
}

static bool	rgbtoi(int **color, char *line, size_t *i, size_t *j)
{
	static int	shift = 16;
	char	number[4];

	if (shift == 0)
		shift = 16;
	ft_strlcpy(number, &line[*i], *j + 1);
	if (ft_strlen(number) > 3 || ft_atoi(number) < 0 || ft_atoi(number) > 255)
		return (ft_fprintf(STDERR_FILENO, OOB_ERROR), false);
	**color += ft_atoi(number) << shift;
	shift -= 8;
	if (line[*i + *j] == '\0')
		*i += *j;
	else
		*i += *j + 1;
	return (true);
}

bool	get_color(int **color, char *line)
{
	size_t	i;
	size_t	j;
	char	number[4];

	if (!init_color(color, line, &i))
		return (false);
	while (line[i])
	{
		ft_memset(&number, '\0', sizeof(char) * 4);
		j = 0;
		while (ft_isspace(line[i]))
			i++;
		while (line[i + j] && ft_isdigit(line[i + j]))
			j++;
		while (ft_isspace(line[i + j]))
			i++;
		if (line[i + j] != ',' && line[i + j] != '\0')
			return (false);
		if (!rgbtoi(color, line, &i, &j))
			return (false);
	}
	return (true);
}
