#include "includes/cube3d.h"

int main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, '\0', sizeof(t_game));
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, ARG_ERROR);
		return (1);
	}
	init(&game, argv[1]);
}
