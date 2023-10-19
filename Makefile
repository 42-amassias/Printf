CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

LIB_FT_PATH		=	libft
LIB_FT_INC_DIR	=	$(LIB_FT_PATH)
LIB_FT			=	$(LIB_FT_PATH)/libft.a

INC_DIR			=	includes
SRC_DIR			=	srcs

NAME			=	libftprintf.a

FILES			=						\
					ft_printf			\
					utils				\
					_hex_printer		\
					_char_printer		\
					_string_printer		\
					_pointer_printer	\
					_decimal_printer	\
					_integer_printer	\
					_unsigned_printer	\
					_lo_hex_printer		\
					_up_hex_printer		\

SRCS			=	$(addsuffix .c,$(addprefix $(SRC_DIR)/,$(FILES)))
OBJS			=	$(addsuffix .o,$(addprefix $(SRC_DIR)/,$(FILES)))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

$(NAME): $(LIB_FT) $(OBJS)
	ar rcs tmp $(OBJS)
	echo "CREATE $@\nADDLIB tmp\nADDLIB $(LIB_FT)\nSAVE\nEND" | ar -M
	rm tmp

%.o: %.c
	$(CC) -c $< -o $@ -I$(INC_DIR) -I$(LIB_FT_INC_DIR) $(CFLAGS)

$(LIB_FT):
	$(MAKE) -C $(LIB_FT_PATH)