#include "../includes/ft_map.h"

char	*get_filename(void)
{
	int		pos;
	char	c;
	char	buffer[1024];
	char	*name;

	buffer[0] = '\0';
	pos = 0;
	while (read(0, &c, 1) > 0 && c != '\n')
		buffer[pos++] = c;
	buffer[pos] = '\0';
	name = ft_strdup(buffer);
	return (name);
}
