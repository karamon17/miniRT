#include "../../includes/miniRT.h"

int	mouse_handle(int button, int x, int y, t_data *data)
{
    (void)data;
    if (button == LEFT_CLICK) {
        get_object(data, x, y);
    }
	return (1);
}



