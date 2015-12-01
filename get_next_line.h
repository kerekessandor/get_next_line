#ifndef GET_NEXT_LINE_H
# define GE_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 8

int		get_next_line(int const fd, char **line);

#endif
