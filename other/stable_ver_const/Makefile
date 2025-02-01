NAME	= miniregex.exe
CC		= cc
RM		= rm -f
FLAGS	= -g3 -Wall -Werror -Wextra -pthread -I $(INC_DIR)
HDR		= miniregex.h

SRC	=		$(SRC_DIR)mini_regex.c \
			$(SRC_DIR)isbase_valid.c \
			$(SRC_DIR)isvalue_valid.c \
			$(SRC_DIR)ft_atoi_base_positive.c \
			$(SRC_DIR)utils_prefix.c \
			$(SRC_DIR)utils_str.c \
			$(SRC_DIR)pattern.c \
			$(SRC_DIR)pattern_utils.c \
			$(SRC_DIR)isbase_alpha_digit.c \
			$(SRC_DIR)main.c

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj

OBJ	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
DEP	= $(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
