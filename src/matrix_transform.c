/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <asamuilk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:15:41 by llai              #+#    #+#             */
/*   Updated: 2024/05/09 18:44:24 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"
#include <math.h>

float	radians(float deg)
{
	float	res;

	res = deg / 180 * M_PI;
	return (res);
}

t_matrix	*translation(float x, float y, float z)
{
	t_matrix	*trans;
	int			i;
	int			j;

	trans = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				trans->data[i][j] = 1.0;
			else
				trans->data[i][j] = 0.0;
		}
	}
	trans->data[0][3] = x;
	trans->data[1][3] = y;
	trans->data[2][3] = z;
	return (trans);
}

t_matrix	*scaling(float x, float y, float z)
{
	t_matrix	*scale;
	int			i;
	int			j;

	scale = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				scale->data[i][j] = 1.0;
			else
				scale->data[i][j] = 0.0;
		}
	}
	scale->data[0][0] = x;
	scale->data[1][1] = y;
	scale->data[2][2] = z;
	return (scale);
}

t_matrix	*rotation_x(float theta)
{
	t_matrix	*rot_x;
	float		cos_theta;
	float		sin_theta;

	rot_x = init_identitymatrix(4);
	cos_theta = cos(theta);
	if (cos_theta < EPSILON)
		cos_theta = 0; 
	sin_theta = sin(theta);
	if (sin_theta < EPSILON)
		sin_theta = 0;
	rot_x->data[1][1] = cos_theta;
	rot_x->data[1][2] = -sin_theta;
	rot_x->data[2][1] = sin_theta;
	rot_x->data[2][2] = cos_theta;
	return (rot_x);
}

t_matrix	*rotation_y(float theta)
{
	t_matrix	*rot_y;
	float		cos_theta;
	float		sin_theta;

	rot_y = init_identitymatrix(4);
	cos_theta = cos(theta);
	if (cos_theta < EPSILON)
		cos_theta = 0; 
	sin_theta = sin(theta);
	if (sin_theta < EPSILON)
		sin_theta = 0;
	rot_y->data[0][0] = cos_theta;
	rot_y->data[0][2] = sin_theta;
	rot_y->data[2][0] = -sin_theta;
	rot_y->data[2][2] = cos_theta;
	return (rot_y);
}

t_matrix	*rotation_z(float theta)
{
	t_matrix	*rot_z;
	float		cos_theta;
	float		sin_theta;

	rot_z = init_identitymatrix(4);
	cos_theta = cos(theta);
	if (cos_theta < EPSILON)
		cos_theta = 0; 
	sin_theta = sin(theta);
	if (sin_theta < EPSILON)
		sin_theta = 0;
	rot_z->data[0][0] = cos_theta;
	rot_z->data[0][1] = -sin_theta;
	rot_z->data[1][0] = sin_theta;
	rot_z->data[1][1] = cos_theta;
	return (rot_z);
}
//
// t_matrix	shearing(float xy, float xz, float yx,
// float yz, float zx, float zy)
// {
// 	t_matrix shear;
//
// 	shear = init_identitymatrix(4);
// 	shear.data[0][1] = xy;
// 	shear.data[0][2] = xz;
// 	shear.data[1][0] = yx;
// 	shear.data[1][2] = yz;
// 	shear.data[2][0] = zx;
// 	shear.data[2][1] = zy;
// 	return (shear);
// }