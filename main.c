#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	close(fd);
	return (0);
}
