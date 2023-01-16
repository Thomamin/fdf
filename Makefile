# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:58:04 by dmin              #+#    #+#              #
#    Updated: 2023/01/16 11:58:13 by dmin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs
SRC_NAME = fdf.c c_to_f.c mlx_util.c my_hook.c read_fdf.c ft_c_rotate.c ft_err_mng.c \
			my_hook_sub.c read_fdf_sub.c translate.c color.c draw_line.c
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC_LINK = -I./includes 
LIBFT = -L./lib/libft -lft 
MLX = -L./lib/mlx -lmlx 
OPENGL = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) libft mlx
	gcc	$(FLAGS) $(OBJ) $(INC_LINK) $(LIBFT) $(MLX) $(OPENGL) -o $(NAME) 

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	gcc $(FLAGS) $(INC_LINK) -o $@ -c $<
    
# libft compile
libft :
	@$(MAKE) -C ./lib/libft all

mlx :
	@$(MAKE) -C ./lib/mlx all

clean :
	@$(MAKE) -C ./lib/libft clean
	@$(MAKE) -C ./lib/mlx clean
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(OBJ) $(NAME)

re : fclean all

.PHONY: all clean fclean re
