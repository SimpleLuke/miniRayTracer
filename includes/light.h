/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:21:20 by llai              #+#    #+#             */
/*   Updated: 2024/05/15 13:23:18 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "tuples.h"

typedef struct s_world			t_world;
typedef struct s_shape_comps	t_shape_comps;

typedef struct s_ambient
{
	float		intensity;
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	t_tuple		position;
	float		intensity;
	t_color		color;
}	t_light;

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_shadow
{
	t_tuple			v;
	t_tuple			direction;
	float			distance;
}	t_shadow;

// light_utils.c
t_light		point_light(t_tuple position, float intensity, t_color color);
t_material	material(void);

// light.c
t_color		lighting(t_world *w, t_shape_comps *c, bool in_shadow);
bool		is_shadowed(t_world *world, t_tuple point);

#endif // !LIGHT_H
