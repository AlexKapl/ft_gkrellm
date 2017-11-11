# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:34:18 by akaplyar          #+#    #+#              #
#    Updated: 2017/11/11 21:53:00 by hshakula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRCSFILES = main.cpp MyException.cpp Kernel.cpp UserModule.cpp Monitor.cpp Line.cpp\
		sfmlDisplay.cpp OsModule.cpp AModule.cpp

SRCPATH = ./
OBJPATH = obj/
CC = g++
INCLUDES = -I $(SRCPATH) -I $(shell pwd)/SFML/include

LDENV = DYLD_FRAMEWORK_PATH="$(shell pwd)/SFML/Frameworks"

LIBS =	-framework SFML -framework sfml-window -framework sfml-system -framework sfml-graphics\
		-lncurses
# LIBS = -lncurses SFML/lib/libsfml-audio.2.2.0.dylib SFML/lib/libsfml-graphics.2.2.0.dylib \
# 		SFML/lib/libsfml-network.2.2.0.dylib SFML/lib/libsfml-system.2.2.0.dylib \
# 		SFML/lib/libsfml-window.2.2.0.dylib
CFLAGS = -Werror -Wall -Wextra -g -F SFML/Frameworks
RM = rm -rf

SRC = $(addprefix $(SRCPATH),$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)%.cpp=$(OBJPATH)%.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

$(OBJECTS): $(OBJPATH)%.o : $(SRCPATH)%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

rmsfml:
	rm -rf SFML

sfml: rmsfml
	curl -O "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz" 
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

ldenv:
	@echo export $(LDENV)

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

