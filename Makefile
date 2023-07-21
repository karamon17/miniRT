NAME     = minirt
GCC      = gcc
CFLAGS   = -Wall -Wextra -Werror -g
RM       = rm -rf
OUTPUT   = ./$(NAME)
LIBS     = -I./includes/
LIBS_DIR = includes

# Compiled directories
SRC = sources
OBJ = objects
SUBDIRS = main parsing
MLX = -lmlx -framework OpenGL -framework AppKit

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))
LIB_DIR = $(foreach dir, $(LIBS_DIR), $(wildcard $(dir)/*.h))

# Libft
LIBFT     = ft
LIBFT_DIR = ./lib$(LIBFT)/


all: $(NAME)

$(NAME): $(LIB_DIR) Makefile $(OBJS)
	make -C $(LIBFT_DIR) all
	$(GCC) -o $(NAME) $(OBJS) $(MLX) -g $(CFLAGS) $(LIBS) -L$(LIBFT_DIR) -l$(LIBFT)   -lncurses

$(OBJ)/%.o: $(SRC)/%.c $(LIB_DIR)
	mkdir -p $(OBJ) $(OBJ_DIR)
	$(GCC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(RDLINE)

re: fclean all