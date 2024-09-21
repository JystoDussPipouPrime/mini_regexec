NAME =	miniregex.a
CC		= cc
RM		= rm -f
CFLAGS =	-Wall -Wextra -Werror -g3
DFLAGS =	-MMD -MP

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

SRC	=		$(SRC_DIR)mini_regex.c \
			$(SRC_DIR)isbase_valid.c \
			$(SRC_DIR)ft_atoi_base_positive.c \
			$(SRC_DIR)utils_prefix.c \
			$(SRC_DIR)utils_str.c

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile| $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

$(NAME): $(OBJ)
	ar -rcs $(NAME) -o $(OBJ)

re: fclean all

fclean : clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

clean:
	$(RM) $(OBJ) $(DEPS)

.PHONY: all re fclean clean
