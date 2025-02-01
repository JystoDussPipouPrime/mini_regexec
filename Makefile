NAME =	miniregex.a
NAME_EXE =	test.exe
CC		= cc
RM		= rm -f
CFLAGS =	-Wall -Wextra -Werror -g3 -I $(INC_DIR)
DFLAGS =	-MMD -MP

P_DIR = portable_ver_const/

INC_DIR = $(P_DIR)inc/
SRC_DIR = $(P_DIR)src/
OBJ_DIR = $(P_DIR)obj/

SRC	=		$(SRC_DIR)mini_regex.c \
			$(SRC_DIR)isbase_valid.c \
			$(SRC_DIR)isvalue_valid.c \
			$(SRC_DIR)ft_atoi_base_positive.c \
			$(SRC_DIR)utils_prefix.c \
			$(SRC_DIR)utils_str.c \
			$(SRC_DIR)pattern.c \
			$(SRC_DIR)pattern_utils.c \
			$(SRC_DIR)isbase_alpha_digit.c

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

$(NAME): $(OBJ)
	ar -rcs $(NAME) -o $(OBJ)
	$(CC) $(CFLAGS) main.c ./miniregex.a -o test.exe

re: fclean all

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_EXE)
	@make fclean -sC $(P_DIR)

clean:
	$(RM) $(OBJ) $(DEPS)

.PHONY: all re fclean clean
