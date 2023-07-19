#include "../includes/miniRT.h"

void		wrong_argc(char *program_name)
{
    printf("Usage: %s <scene.rt>\n", program_name);
    exit(EXIT_FAILURE);
}

void fatal()
{
    char error_message[100];

    perror(error_message);
    exit(EXIT_FAILURE);
}