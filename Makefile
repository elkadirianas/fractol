NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC = mandatory/fractol.c mandatory/init.c mandatory/utils.c mandatory/render.c mandatory/math_op.c mandatory/event.c


OBJ = $(SRC:.c=.o)


%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) 

re : fclean all