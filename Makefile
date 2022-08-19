NAME	:= so_long.a
NAME_B	:= so_long_bonus.a

APP		:= so_long
APP_B	:= so_long_bonus

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Imlx
FILES	:= $(wildcard *.c) $(wildcard ./get_next_line/*.c)
OBJ		:= $(FILES:%.c=%.o)

FILES_B	:= $(wildcard ./bonus/*.c) $(wildcard ./get_next_line/*.c)
OBJ_B	:= $(FILES_B:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	$(CC) $(OBJ) -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit -o $(APP)

all: $(NAME) bonus

bonus: $(OBJ_B)
	ar -rcs $(NAME_B) $(OBJ_B)
	$(CC) $(OBJ_B) -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit -o $(APP_B)

clean:
	@rm -f *.o
	@rm -f ./get_next_line/*.o
	@rm -f ./bonus/*.o

fclean: clean
	@rm -f $(NAME) $(APP)
	@rm -f $(NAME_B) $(APP_B)

re: fclean all

.PHONY: all clean fclean re bonus
