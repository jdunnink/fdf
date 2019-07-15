#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:33:47 by jdunnink      #+#    #+#                  #
#    Updated: 2019/05/04 14:33:06 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

SRC =	main.c				\
		error.c				\
		read_input.c		\
		init_object.c		\
		init_win.c			\
		init_img.c			\
		input_checks.c		\
		print_vectors.c		\
		free_object.c		\
		free_vectors.c		\
		ft_lstappend.c		\
		print_obj_stat.c	\
		set_coor_range.c	\
		add_colors.c		\
		copy_vector.c		\
		
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
