#include "../../includes/miniRT.h"

void get_object(t_data *data, int x, int y);

int	mouse_whilling(int button, int x, int y, t_data *data)
{
    (void)data;
    if (button == LEFT_CLICK) {
        get_object(data, x, y);
    }
	return (1);
}

void get_object(t_data *data, int x, int y) {


}
