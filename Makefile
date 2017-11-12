# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:34:18 by akaplyar          #+#    #+#              #
#    Updated: 2017/11/12 10:29:50 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @clang++
CFLAGS = -Wall -Wextra -Werror

OBJ =	main.o MyException.o Kernel.o UserModule.o Monitor.o Line.o\
		NcursesDisplay.o AModule.o OsModule.o DateModule.o CpuModule.o

NAME = ft_gkrellm

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses -lpanel
	@printf "\x1B[32m\0%s created\x1B[0m\0\n" $(NAME)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\x1B[32m\0Compile %s\x1B[0m\0\n" $<

clean:
	@rm -rf $(OBJ)
	@printf "\x1B[31m\0%s objects cleared\x1B[0m\0\n" ${NAME}

fclean: clean
	@rm -rf $(NAME)
	@printf "\x1B[31m\0%s deleted\x1B[0m\0\n" ${NAME}

re: fclean all

SFML:
	git clone https://github.com/SFML/SFML.git SFML
