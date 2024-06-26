/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:35:30 by llai              #+#    #+#             */
/*   Updated: 2024/05/08 21:34:09 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "color.h"

typedef struct s_img
{
	void	*mlx;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

void	put_pixel(t_img *img, int x, int y, t_color color);
void	put_pixel2(t_img *img, int x, int y, t_color color);
void	put_pixel_img(t_img *img, int x, int y, int color);

#endif // !IMAGE_H
