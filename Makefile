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

SRCS= srcs/init_env.c \
		srcs/init_img.c \

OBJ= $(SRCS:.c=.o)

INCLUDES= -I libft/includes -I includes -I mlx/

LIBS= -L./libft/ -lft -L./mlx -lmlx -lm

FLAGS= -Wall -Werror -Wextra

FRAMEWORK= -framework OpenGL -framework Appkit

all:		$(NAME)

$(NAME):	$(OBJ)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\n"
	@echo "	\033[37;1m  ,__________,   ,______________, \033[0m"
	@echo "	\033[37;1m  |          |   |               \     \033[0m"
	@echo "	\033[37;1m  |___,      |   |     ,____,     \   \033[0m"
	@echo "	\033[37;1m     /      /    |     |     \     \  \033[0m"
	@echo "	\033[37;1m    /      /     |     |      \     \ \033[0m"
	@echo "	\033[37;1m   /______/      |_____|      /     / \033[0m"
	@echo "	\033[37;1m  ,________________________./      /  \033[0m"
	@echo "	\033[37;1m  |                               /   \033[0m"
	@echo "	\033[37;1m  |_____________________________./     \033[0m"
	@echo "	\033[31;1m  +--------------------------------+\033[0m"
	@echo "	\033[31;1m  | ZDTEAM  @  42 SCHOOL   2 0 1 8 |\033[0m"
	@echo "	\033[31;1m  +--------------------------------+\033[0m"
	@echo "\n"

$(OBJ): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

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
