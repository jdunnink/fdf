# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:33:47 by jdunnink       #+#    #+#                 #
#    Updated: 2019/11/23 12:36:04 by jdunnink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC =	main.c				\
		error.c				\
		read_input.c		\
		init_object.c		\
		init_win.c			\
		init_img.c			\
		input_checks.c		\
		free_object.c		\
		free_vectors.c		\
		set_coor_range.c	\
		update_coor_range.c	\
		add_colors.c		\
		center_vectors.c	\
		scale_vectors.c		\
		set_x_grid.c		\
		set_z_grid.c		\
		merge_sort_list.c	\
		draw_line.c			\
		draw_grid.c			\
		draw_object.c		\
		img_pixel_put.c		\
		get_color.c			\
		add_interface.c		\
		key_release.c		\
		set_vectors.c		\
		key_press.c			\
		rotate.c			\
		set_breaks.c		\
		alt_get_vectors.c	\
		zoom.c				\
		reset.c				\
		get_vectors.c		\
		push_vector.c		\
		change_view.c		\
		dump_image.c		\
		check_line.c		\

OBJ = $(SRC:.c=.o)

SRCDIR = srcs

OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes

CC = gcc

NAME = fdf

CFLAGS =

LIBS = -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(HEADER) $(LIBS)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR) ;
	make -C libft/
	make -C minilibx_macos/
	$(CC) -c $(CFLAGS) $(SRCS) $(HEADER)
	/bin/mv $(OBJ) $(OBJDIR)/

clean:
	/bin/rm -Rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

relib:
	make re -C libft/
	make re -C minilibx_macos/

cleanse: fclean
	make fclean -C libft/
	make clean -C minilibx_macos/
