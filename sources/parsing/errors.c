#include "../../includes/miniRT.h"

void		wrong_argc(char *program_name)
{
    printf("Usage: %s <scene.rt>\n", program_name);
    exit(EXIT_FAILURE);
}

void error(const char *string, int i) {
	write(2, "Error ", 6);
	write(2, string, ft_strlen(string));
	exit(i);
}

void check_correct_file_extension(char *filename) {
	int i;
	int dot_count;

	i = 0;
	dot_count = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count != 1)
		error("Wrong file extension\n", EXIT_FAILURE);
	if (ft_strncmp(filename + i - 3, ".rt", 3) != 0)
		error("Wrong file extension\n", EXIT_FAILURE);
}

void check_elements(t_data *data) {
	if (data->checker.camera_init == 0)
		error("No camera in scene\n", EXIT_FAILURE);
	if (data->checker.has_ambient == 0)
		error("No ambient light in scene\n", EXIT_FAILURE);
	if (data->checker.has_spot == 0)
		error("No light in scene\n", EXIT_FAILURE);
	if (data->checker.has_object == 0)
		error("No object in scene\n", EXIT_FAILURE);
}