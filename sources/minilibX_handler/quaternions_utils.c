#include "../includes/miniRT.h"

void	quaternion_normalize(t_quaternion quaternion)
{
	float	magnitude;

	magnitude = sqrtf(quaternion.w * quaternion.w + quaternion.x
			* quaternion.x + quaternion.y * quaternion.y
			+ quaternion.z * quaternion.z);
	quaternion.w /= magnitude;
	quaternion.x /= magnitude;
	quaternion.y /= magnitude;
	quaternion.z /= magnitude;
}

t_quaternion	multiply_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (result);
}

t_quaternion	conjugate(t_quaternion q)
{
	t_quaternion	result;

	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return (result);
}