NAME	= miniregex.exe
CC		= cc
RM		= rm -f
FLAGS	= -g3 -Wall -Werror -Wextra -pthread -I $(INC_DIR)
HDR		= miniregex.h

SRC_1	=	src/main.c \
			src/miniregexphilo.c \
			src/isbase_valid.c

INC_DIR = inc/
SRC_DIR = src
OBJ_DIR = obj

OBJ_1	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_1:.c=.o)))
DEP_1	= $(OBJ_1:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP_1)

$(NAME): $(OBJ_1)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_1)

clean:
	$(RM) $(OBJ_1) $(DEP_1)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
