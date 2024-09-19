# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 14:34:05 by marlon            #+#    #+#              #
#    Updated: 2024/09/19 12:10:08 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Account.cpp	\
		tests.cpp

OBJS_DIR = objs/
OBJS = $(SRC:.cpp=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
HEADERS = Account.hpp
CC = g++
RM = rm -rf
MKDIR = mkdir -p
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = tests

all: $(NAME)

$(NAME): $(OBJS_PREFIXED)
	$(CC) $(CCPFLAGS) $(OBJS_PREFIXED) -o $(NAME)

$(OBJS_DIR)%.o : %.cpp $(HEADERS)
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CCPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean