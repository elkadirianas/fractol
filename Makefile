NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC = mandatory/event.c   mandatory/fractol.c  mandatory/init.c    mandatory/math_op.c mandatory/render.c  mandatory/utils.c mandatory/utils1.c
SRC_BONUS = bonus/event_bonus.c   bonus/fractol_bonus.c  bonus/init_bonus.c    bonus/math_op_bonus.c bonus/render_bonus.c  bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

mandatory/%.o: mandatory/%.c mandatory/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: clean