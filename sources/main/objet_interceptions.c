#include "../includes/miniRT.h"


t_figure *check_intersection(t_figure *figure, t_vector *vector, t_vector *ray)
{
    while(figure)
    {
        if (figure->type == SPHERE && sphere_intercept(figure, vector, ray))
            return (figure);
        if (figure->type == PLANE && plane_intercept(figure, vector, ray) && plane_intercept(figure, vector, ray) != INFINITY)
            return (figure);
        if (figure->type == CYLINDER && cylinder_intersection(vector, ray, figure) && cylinder_intersection(vector, ray, figure) != INFINITY)
            return (figure);
        figure = figure->next;
    }
    return (0);
}

float plane_intercept(t_figure *plane, t_vector *vector, t_vector *ray)
{
    float a;
	t_vector *temp;

    a = vector_dot_product(plane->figure_body.plane.normal, ray);
    if (a == 0)
        return (INFINITY);
	temp = vector_subtract(plane->center, vector);
    a = vector_dot_product(temp, plane->figure_body.plane.normal) / a;
	free(temp);
    if (a < EPSILON)
        return (INFINITY);
    return (a);
}

float sphere_intercept(t_figure *sphere, t_vector *vector, t_vector *ray)
{
    float a;
    float b;
    float c;
    float discr;
    float dist_1;
    t_vector *oc;

    oc = vector_subtract(vector, sphere->center);
    a = vector_dot_product(ray, ray);
    b = 2 * vector_dot_product(oc, ray);
    c = vector_dot_product(oc, oc) - (sphere->figure_body.sphere.radius * sphere->figure_body.sphere.radius);
    free(oc);
    discr = b * b - (4 * a * c);
    if (discr < 0)
        return (0);
    dist_1 = (-b - sqrt(discr)) / 2 / a;
    if (dist_1 > 0)
        return (dist_1);
    return (0);
}

t_figure *closest_intersection(t_figure *figure, t_vector *vector, t_vector *ray, float *closest_dist)
{
    t_figure *closest_figure;
    float dist;

    closest_figure = NULL;
	*closest_dist = 0;
    while(figure)
    {
        if (figure->type == SPHERE)
            dist = sphere_intercept(figure, vector, ray);
        else if (figure->type == PLANE)
            dist = plane_intercept(figure, vector, ray);
        else if (figure->type == CYLINDER)
            dist = cylinder_intersection(vector, ray, figure);
        if ((dist > 0) && (dist < *closest_dist || closest_figure == NULL))
        {
            *closest_dist = dist;
            closest_figure = figure;
        }
        figure = figure->next;
    }
    return (closest_figure);
}
