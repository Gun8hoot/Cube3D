
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
		if (ft_isdigit(number[i]))
			i++;
		else if (number[i] == ',')
		{
			comma++;
			i++;
		}
		else
			return (fprintf(stderr, COLOR_ERROR, number), -1);
		if (comma > 2)
			return (fprintf(stderr, COLOR_ERROR, number), -1);
	}
	return (comma);
}

bool	get_color(int **color, char *line)
{
	int		shift;
	size_t	i;
	size_t	j;
	char	number[4];
	int		tmp;

	i = 0;
	shift = 16;
	*color = ft_calloc(1, sizeof(int));
	if (!*color)
		return (fprintf(stderr, ALLOC_ERROR), false);
	while (ft_isalpha(line[i]) || line[i] == ' ')
		i++;
	if (check_number(&line[i]) < 0)
		return (free(*color), *color = NULL, false);
	while (line[i])
	{
		tmp = 0;
		ft_memset(&number, '\0', sizeof(char) * 4);
		j = 0;
		while (line[i + j] && ft_isdigit(line[i + j]))
			j++;
		if (line[i + j] != ',' && line[i + j] != '\0')
			return (false);
		ft_strlcpy(number, &line[i], j + 1);
		tmp = ft_atoi(number);
		if (ft_strlen(number) > 3 || tmp < 0 || tmp > 255)
			return (ft_fprintf(STDERR_FILENO, OOB_ERROR), false);
		**color += tmp << shift;
		shift -= 8;
		if (line[i + j] == '\0')
			i += j;
		else
			i += j + 1;
	}
	return (true);
}
