# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 12:42:17 by pcervill          #+#    #+#              #
#    Updated: 2023/09/27 13:57:08 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS = philo.c arg.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = philo

LIBFT_PATH = ./include/libft/

all:	$(NAME)
	@echo " \033[32m[ OK ] | Philo ready!\033[0m"

$(NAME):	$(OBJS)
	@echo " \033[34m"'╔═════════════════════════════════════════════════════╗'	"\033[0m"
	@echo " \033[34m"'║ \033[33m   _______    __    __   __    ___        ______   \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m  |   __ "\  /" |  | "\ |" \  |"  |      /    " \  \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m  (. |__) :)(:  (__)  :)||  | ||  |     // ____  \ \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m  |:  ____/  \/      \/ |:  | |:  |    /  /    ) :)\033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m  (|  /      //  __  \\\ |.  |  \  |___(: (____/ // \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m /|__/ \    (:  (  )  :)/\  |\( \_|:  \\\        /  \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m(_______)    \__|  |__/(__\_|_)\_______)\"_____/   \033[34m ║'	"\033[0m"
	@echo " \033[34m"'║ \033[33m                                                   \033[34m ║'	"\033[0m"
	@echo " \033[34m"'╚═════════════════════════════════════════════════════╝'	"\033[0m"
	@echo " \033[33m[ .. ] | Compiling libft...\033[0m"
	@make bonus -C $(LIBFT_PATH) -silent
	@echo " \033[32m[ OK ] | Libft ready!\033[0m"
	@echo " \033[33m[ .. ] | Compiling philo...\033[0m"
	@$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(OBJS)  -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH) -silent
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) -silent
	@echo " \033[35m[ OK ] | Philo fclean ready!\033[0m"

re:	fclean all

.PHONY = all clean fclean re
.SILENT: $(OBJS)