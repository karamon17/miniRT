#include "../../includes/miniRT.h"

int	mouse_whilling(int button, int x, int y, t_data *data)
{
	(void ) data;
	if (button == 5)
		printf("zoom in\n");
	else if (button == 4)
		printf("zoom out\n");
	printf("position: %d %d\n", x, y);
	return (1);
}