/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:33:59 by llai              #+#    #+#             */
/*   Updated: 2024/05/15 13:19:33 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

typedef struct s_progressbar
{
	int		total_pixels;
	int		current_pixel;
	float	progress;
}	t_progresbar;

typedef struct s_matrix	t_matrix;

void	malloc_errcheck(void *p);
void	print_progress(float progress);
void	print_matrix(t_matrix *mat);

#endif // DEBUG
