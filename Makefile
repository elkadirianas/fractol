NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC = fractol.c init.c utils.c render.c math_op.c event.c


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