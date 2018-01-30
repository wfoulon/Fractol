# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 13:09:26 by wfoulon           #+#    #+#              #
#    Updated: 2018/01/23 13:10:54 by wfoulon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

LOGIN= wfoulon

SRCS= srcs/init_env.c \
		srcs/init_img.c \
		srcs/init_param.c \
		srcs/draw_fractals.c \
		srcs/draw_fractals2.c \
		srcs/main.c \
		srcs/select_fractals.c \

OBJ= $(SRCS:.c=.o)

INCLUDES= -I libft/includes -I includes -I mlx/

LIBS= -L./libft/ -lft -L./mlx -lmlx -lm

FLAGS= -Wall -Werror -Wextra

FRAMEWORK= -framework OpenGL -framework Appkit

$(NAME):	$(OBJ)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJ) $(LIBS) $(FRAMEWORK)
	@echo "\033[38;5;79m  [$(NAME)]	Compiled."
	@echo "\033[34m"
	@echo "\033[38;5;84m  MMMºººAMV '7MMºººYb.   '7MMºººMq. "
	@echo "  M'   AMV    MM    'Yb.   MM   'MM."
	@echo "\033[38;5;85m  '   AMV     MM     'Mb   MM   ,M9 "
	@echo "     AMV      MM      MM   MMmmdM9  "
	@echo "\033[38;5;86m    AMV   ,   MM     ,MP   MM"
	@echo "   AMV   ,M   MM    ,dP'   MM"
	@echo "\033[38;5;87m  AMVmmmmMM .JMMmmmdP'   .JMML. "
	@echo ""
	@echo "\033[38;5;7m [2018]                    [${LOGIN}]"
	@echo ""

$(OBJ): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJ)
	@echo "\033[37mall FDF_files.o are deleted\033[0m"

fclean:
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:			fclean all

norme:
	@norminette srcs/
	@norminette includes/
	@norminette libft/

.PHONY: all clean fclean re
