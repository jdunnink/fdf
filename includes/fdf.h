/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/17 20:42:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

#include <stdio.h>

/*
**	t_matrix struct is used to store mathematical constants
**	that are frequently used during matrix multiplication.
*/

typedef	struct	s_matrix
{
	float		constant;
	float		cosine;
	float		sine;
	float		neg_sine;
}				t_matrix;

/*
**	t_minmax struct is used to store the minimum and maximum
**	coordinate of a series of vectors. Primarily used
**	in relation to centering a given object around a
**	centralized axis point.
*/

typedef	struct	s_minmax
{
	float		x_min;
	float		x_max;
	float		y_min;
	float		y_max;
	float		z_min;
	float		z_max;
}				t_minmax;

/*
**	t_point struct is used to store and define points in 2D space.
**	Primarily used in the linedrawing algorithm --> draw_line.c
*/

typedef	struct	s_point
{
	int			x;
	int			y;
	unsigned	color;
}				t_point;

/*
**	t_vec struct is used to store and define a vector in 3D space,
**	using x, y and z.
*/

typedef	struct	s_vec
{
	float		x;
	float		y;
	float		z;
	unsigned	color;
	int			br;
}				t_vec;

/*
**	t_img struct is used to store the variables related to the img_ptr,
**	usage allows for faster rendering with minilibx's put_image_to_window.
**	A new img can be created using the init_img function.
*/

typedef struct	s_img
{
	void		*img_ptr;
	char		*pixels;
	int			width;
	int			height;
	int			size_line;
	int			bpp;
	int			endian;
}				t_img;

/*
**	t_win struct is used to store the variables related to a window,
**	pointed to by win_ptr. A new window can be initiated using the
**	init_win function.
*/

typedef	struct	s_win
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	size_t		width;
	size_t		height;
	size_t		depth;
}				t_win;

/*
**	t_object is used to store the main target object and
**	any related variables. Three copies of the total vector
**	list are stored for changing object views and rotation.
**	z_grid and x_grid store the grid masks for effective
**	line rendering.
*/

typedef	struct	s_object
{
	t_win		*win;
	t_img		*img;
	t_list		*input;
	t_list		*centre;
	t_list		*scale;
	t_minmax	*coor_range;
	t_list		*z_grid;
	t_list		*x_grid;
	unsigned	x_count;
	unsigned	z_count;
	unsigned	total_vectors;
	t_matrix	*left;
	t_matrix	*right;
	t_matrix	*rotation;
}				t_object;

void			error(int error_code);
void			read_input(char *input_file, t_object **obj);
int				init_object(t_object **obj);
int				is_valid_nbr(char *str);
int				is_alt_nbr(char *str);
int				extract_nbr(char *str);
void			print_vectors(t_list *vectors, int mode);
void			free_object(t_object **target);
void			free_vectors(t_list **vectors, int mode);
void			free_img(t_img **target, void *mlx_ptr);
void			ft_lstappend(t_list **list, void *content, size_t size);
void			print_obj_stat(t_object **target);
void			set_coor_range(t_object **target);
void			add_colors(t_list *vectors, t_minmax *coor_range);
void			init_win(int x, int y, t_win **win, char *name);
void			init_img(t_img **img, t_win *window, int width, int height);
t_list			*copy_vector(t_list *elem);
void			center_vectors(t_list *vectors, t_minmax *coor_range);
void			scale_vectors(t_object *obj);
void			set_x_grid(t_object *obj);
void			set_z_grid(t_object *obj);
void			update_coor_range(t_list *vectors, t_minmax *coor_range);
t_list			*merge_sort_list(t_list *vectors);
void			draw_line(t_img *img, t_vec start, t_vec end, t_point sign);
void			draw_grid(t_img *img, t_list *grid, char type);
void			draw_object(t_object *obj);
void			img_pixel_put(t_img *img, int x, int y, int color);
int				get_color(t_point curr, t_point start, t_point end, t_point d);
int				key_release(int keycode, t_object *obj);
int				key_press(int keycode, t_object *obj);
void			add_interface(t_object *obj);
t_list			*ft_lstcpy(t_list *src);
t_list			*ft_lstref(t_list *src);
void			set_vectors(t_list *dest, t_list *src);
void			rotate(t_object *obj, char type, int render);
void			set_breaks(t_list *grid, int type);

#endif
