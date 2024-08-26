# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 13:27:23 by ehedeman          #+#    #+#              #
#    Updated: 2024/08/26 14:45:00 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Contact.cpp		\
		PhoneBook.cpp	\
		main.cpp

OBJS_DIR = objs/
OBJS = $(SRC:.cpp=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
HEADERS = PhoneBook.hpp Contact.hpp
CC = g++
RM = rm -rf
MKDIR = mkdir -p
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = phonebook

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