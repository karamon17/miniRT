#include "../includes/miniRT.h"


int get_color(t_data *data, t_vector *ray);

t_color	*color_multiply(t_color *color, float intecivity);

void ray_trace(void *mlx, void *win, t_data *data)
{
	int mlx_x;
	int mlx_y = 0;
	float x_angle;
	float y_angle;
	float x_ray;
	float y_ray;
	int color;

	t_vector *ray;
	t_view_plane *vplane;
	vplane = view_plane_new(data->height, data->width, data->camera->fov);
	y_angle = data->height / 2.f;
	while(y_angle >= (data->height / 2.f) * -1)
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (data->width / 2.f) * -1;
		mlx_x = 0;
		while (x_angle <= data->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vector_new(x_ray, y_ray, -1);
			vector_normalize(ray);
			color = get_color(data, ray);
			mlx_pixel_put(mlx, win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_figure *ClosestIntersection(t_figure *figure, t_vector *vector, t_vector *ray, float *closest_dist, t_color **color)
{
	t_figure *closest_figure;
	float dist;

	closest_figure = NULL;
	while(figure)
    {
        if (figure->type == SPHERE)
			dist = sphere_intercept(figure, vector, ray);
		else if (figure->type == PLANE)
			dist = plane_intercept(figure, vector, ray);
		else if (figure->type == CYLINDER)
			dist = cylinder_intercept(figure, vector, ray);
        if ((dist > 0) && (dist < *closest_dist || closest_figure == NULL))
		{
            *color = figure->RGB_color;
            *closest_dist = dist;
            closest_figure = figure;
        }
		figure = figure->next;
    }
	return (closest_figure);
}

t_figure *check_intersection(t_figure *figure, t_vector *vector, t_vector *ray)
{
	while(figure)
    {
        if (figure->type == SPHERE && sphere_intercept(figure, vector, ray))
			return (figure);
		if (figure->type == PLANE && plane_intercept(figure, vector, ray))
			return (figure);
		if (figure->type == CYLINDER && cylinder_intercept(figure, vector, ray))
			return (figure);
		figure = figure->next;
    }
	return (0);
}

int get_color(t_data *data, t_vector *ray)
{
    t_color *color;
	t_color *temp;
    float closest_dist = 0;
	t_figure *closest_figure = NULL;

	color = color_new(0, 0, 0);
	temp = color;
	closest_figure = ClosestIntersection(data->figures, data->camera->origin, ray, &closest_dist, &color);
	if (closest_figure)
	{
		t_vector *p = multiply_vector(closest_dist, ray);
		t_vector *n = vector_subtract(p, closest_figure->figure_body.sphere.center);
		vector_normalize(n);
		temp = color_multiply(color, compute_lighting(data, p, n, multiply_vector(-1, ray), closest_figure->specular));
	}
    return (color_to_int(temp));
}

t_color	*color_multiply(t_color *color, float intecivity)
{
	t_color *res;

	res = malloc(sizeof(t_color));
	res->red = color->red * intecivity;
	res->green = color->green * intecivity;
	res->blue = color->blue * intecivity;
	res->red = res->red > 255 ? 255 : res->red;
	res->green = res->green > 255 ? 255 : res->green;
	res->blue = res->blue > 255 ? 255 : res->blue;
	return (res);
}

float sphere_intercept(t_figure *sphere, t_vector *vector, t_vector *ray)
{
	float a;
	float b;
	float c;
	float discr;
	float dist_1;
	t_vector *oc;

	oc = vector_subtract(vector, sphere->figure_body.sphere.center);
	a = vector_dot_product(ray, ray);
	b = 2 * vector_dot_product(oc, ray);
	c = vector_dot_product(oc, oc) - (sphere->figure_body.sphere.radius * sphere->figure_body.sphere.radius);
	discr = b * b - (4 * a * c);
	if (discr < 0)
		return (0);
	dist_1 = (-b - sqrt(discr)) / 2 / a;
	free(oc);
	if (dist_1 > 0)
		return (dist_1);
	return (0);
}

float plane_intercept(t_figure *plane, t_vector *vector, t_vector *ray)
{
	float a;

	a = vector_dot_product(plane->figure_body.plane.normal, ray);
	if (a == 0)
		return (0);
	a = vector_dot_product(vector_subtract(plane->figure_body.plane.center, vector), plane->figure_body.plane.normal) / a;
	if (a < 0)
		return (0);
	return (a);
}

float	cylinder_intercept(t_figure *cylinder, t_vector *vector, t_vector *ray)
{
	t_vector *oc;
	float a;
	float b;
	float c;
	float discr;
	float dist_1;
	float dist_2;
	float y1;
	float y2;
	float projection;

	oc = vector_subtract(vector, cylinder->figure_body.cylinder.center);
	projection = vector_dot_product(ray, oc);
	a = vector_dot_product(ray, ray);
	b = 2 * vector_dot_product(oc, ray);
	c = vector_dot_product(oc, oc) - (cylinder->figure_body.cylinder.radius * cylinder->figure_body.cylinder.radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	dist_1 = (-b + sqrt(discr)) / 2 / a;
	dist_2 = (-b - sqrt(discr)) / 2 / a;
	y1 = vector->z + dist_1 * ray->z;
	y2 = vector->z + dist_2 * ray->z;
	if (y1 >= cylinder->figure_body.cylinder.center->z && y1 <= cylinder->figure_body.cylinder.center->z + cylinder->figure_body.cylinder.height)
		return (dist_1);
	else if (y2 >= cylinder->figure_body.cylinder.center->z && y2 <= cylinder->figure_body.cylinder.center->z + cylinder->figure_body.cylinder.height)
		return (dist_2);
	float t_bottom = (cylinder->figure_body.cylinder.center->z - vector->z) / ray->z;
    float t_top = (cylinder->figure_body.cylinder.center->z + cylinder->figure_body.cylinder.height - vector->z) / ray->z;

    // Проверяем, лежит ли точка пересечения с нижним основанием внутри окружности
    float x_bottom = vector->x + t_bottom * ray->x - cylinder->figure_body.cylinder.center->x;
    float y_bottom = vector->y + t_bottom * ray->y - cylinder->figure_body.cylinder.center->y;
    if (x_bottom * x_bottom + y_bottom * y_bottom <= cylinder->figure_body.cylinder.radius * cylinder->figure_body.cylinder.radius) {
        return t_bottom;
    }

    // Проверяем, лежит ли точка пересечения с верхним основанием внутри окружности
    float x_top = vector->x + t_top * ray->x - cylinder->figure_body.cylinder.center->x;
    float y_top = vector->y + t_top * ray->y - cylinder->figure_body.cylinder.center->y;
    if (x_top * x_top + y_top * y_top <= cylinder->figure_body.cylinder.radius * cylinder->figure_body.cylinder.radius) {
        return t_top;
    }
	return (0);
}

t_view_plane *view_plane_new(float height, float width, float fov)
{
	t_view_plane	*view_plane;
	float 			aspect_ratio;

	view_plane = malloc(sizeof(t_view_plane));
	if (!view_plane)
		return (NULL);
	aspect_ratio = width / height;
	view_plane->width = tan(fov / 2 * M_PI / 180) * 2;
	view_plane->height = view_plane->width / aspect_ratio;
	view_plane->x_pixel = view_plane->width / width;
	view_plane->y_pixel = view_plane->height / height;
	return (view_plane);
}