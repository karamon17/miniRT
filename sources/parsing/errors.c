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
