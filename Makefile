NAME = minirt

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

SRC = camera.c\
      main.c\
      scene.c\
      sphere.c\
      trace_ray.c\
      vector.c

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
