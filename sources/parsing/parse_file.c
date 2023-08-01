#include "../../includes/miniRT.h"


void parse_rt_file(t_data *data) {
	int fd;
	char *file_content;
	check_correct_file_extension(data->filename);
	if ((fd = open(data->filename, 0)) == -1)
		error("file does not exist\n", EXIT_FAILURE);
	file_content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	file_content[0] = '\0';
	file_content = read_file(file_content, fd);
	parse_elements(file_content, data);
}



char		*read_file(char *str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		retairment;

	while ((retairment = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[retairment] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			error("Error in ft_strjoin\n", EXIT_FAILURE);
	}
	return (str);
}

