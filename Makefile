# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 17:26:27 by amassias          #+#    #+#              #
#    Updated: 2024/05/11 17:20:12 by Antoine Mas      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

LIB_FT_PATH		=	libft
LIB_FT_INC_DIR	=	$(LIB_FT_PATH)
LIB_FT			=	$(LIB_FT_PATH)/libft.a

SRC_DIR			=	src
INC_DIR			=	include
OBJ_DIR			=	build

NAME			=	libftprintf.a

include Files.mk

SRCS			=	$(addsuffix .c,$(addprefix $(SRC_DIR)/,$(FILES)))
OBJS			=	$(addsuffix .o,$(addprefix $(OBJ_DIR)/,$(FILES)))

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

$(NAME): $(LIB_FT) $(OBJS)
	@cp $(LIB_FT) $@
	@sh -c "ar rcs $@ $(OBJS) || rm $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ -I$(INC_DIR) -I$(LIB_FT_INC_DIR) $(CFLAGS)

$(LIB_FT):
	$(MAKE) -C $(LIB_FT_PATH)