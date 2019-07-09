#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd = open(argv[1], O_RDONLY);
	int		oui;

	oui = argc;
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
}
