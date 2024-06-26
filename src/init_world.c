/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:11:32 by llai              #+#    #+#             */
/*   Updated: 2024/05/16 14:46:44 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/world.h"
#include "../includes/ray.h"
#include "../includes/matrix.h"
#include "../includes/debug.h"
#include "../includes/world.h"
#include "../includes/scene.h"
#include <math.h>
#include <stdbool.h>

void	init_world(t_data *data)
{
	data->scene->world.ambient = data->scene->ambient;
	data->scene->world.light = data->scene->light;
	configure_camera(data, &data->scene->camera);
}

void	make_orientation(
	t_tuple left, t_tuple true_up, t_tuple forward, t_matrix *orientation)
{
	orientation->size = 4;
	orientation->data[0][0] = left.x;
	orientation->data[0][1] = left.y;
	orientation->data[0][2] = left.z;
	orientation->data[0][3] = 0;
	orientation->data[1][0] = true_up.x;
	orientation->data[1][1] = true_up.y;
	orientation->data[1][2] = true_up.z;
	orientation->data[1][3] = 0;
	orientation->data[2][0] = -forward.x;
	orientation->data[2][1] = -forward.y;
	orientation->data[2][2] = -forward.z;
	orientation->data[2][3] = 0;
	orientation->data[3][0] = 0;
	orientation->data[3][1] = 0;
	orientation->data[3][2] = 0;
	orientation->data[3][3] = 1;
}

// It mimics the eye/camera moves instead of the world
// from where the eye in the scene
// to where you want to look at
// and a vector indicates which direction is up
void	view_transform(t_data *data, t_tuple up, t_matrix *res)
{
	t_tuple		from;
	t_camconfig	config;
	t_matrix	orientation;
	t_matrix	trans_m;

	from = data->scene->camera.position;
	config.forward = normalize(data->scene->camera.rotation);
	if (equal_tuple(config.forward, normalize(vector(0, 1, 0)))
		|| equal_tuple(config.forward, normalize(vector(0, -1, 0))))
		config.forward.z = 0.1;
	config.upn = normalize(up);
	config.left = cross(config.forward, config.upn);
	config.true_up = cross(config.left, config.forward);
	trans_m.size = 4;
	res->size = 4;
	make_orientation(config.left, config.true_up, config.forward, &orientation);
	translation(-from.x, -from.y, -from.z, &trans_m);
	matrix_multiply(&orientation, &trans_m, res);
}

// The camera pixel size is calculated with the horizontal aspect
// and vertical aspect
// t_camera	camera(float hsize, float vsize, float field_of_view)
void	configure_camera(t_data *data, t_cam *c)
{
	float		half_view;
	float		aspect;

	c->hsize = WIDTH;
	c->vsize = HEIGHT;
	if (equal(c->fov, 180))
		c->fov = 179.9;
	c->rfov = radians(c->fov);
	view_transform(
		data,
		vector(0, 1, 0),
		&c->transform);
	half_view = tan(c->rfov / 2);
	aspect = c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / c->hsize;
}
