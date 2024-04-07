# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 10:30:09 by vconesa-          #+#    #+#              #
#    Updated: 2024/04/07 22:57:15 by xvislock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_DIR := ./srcs/
SOURCES := $(shell find $(SRCS_DIR) -name '*.c')
OBJECTS = $(SOURCES:.c=.o)
HEADER = includes
FLAGS = -Wall -Wextra -Werror
NAME = bsq
RM = rm -f
CC = gcc
CREATELIB = ar rc
RANLIB = ranlib

all:${NAME} clean

${NAME}: ${OBJECTS}
	${CC} ${FLAGS} -o ${NAME} ${SOURCES} -I${HEADER} -g

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

