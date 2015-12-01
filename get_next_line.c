#include "get_next_line.h"

static int		ft_read(int const fd, char **doc)
{
	int result;
	char *buff;
	char *temp;

	buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE));
	if (buff == NULL)
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	if (result > 0)
	{
		buff[result] = '\0';
		temp = buff;
		*doc = ft_strjoin(*doc, temp);
	}
	free(buff);
	return (result);
}


int				get_next_line(int const fd, char **line)
{
	int		result;
	char	*end_of_line;
	static char *doc = NULL;

	if (!doc)
		doc = (char*)malloc(sizeof(*doc));
	if (doc == NULL || fd < 0)
		return (-1);
	while (end_of_line == NULL)
	{
		result = ft_read(fd, &doc);
		end_of_line = ft_strchr(doc, '\n');
		if (result == 0)
		{
			if (ft_strlen(doc) == 0)
				return (0);
		}
		else if (result < 0)
			return (-1);
	}
	*line = ft_strsub(doc, 0, ft_strlen(doc)-ft_strlen(end_of_line));
	doc = ft_strdup(end_of_line + 1);
	return (1);
}
