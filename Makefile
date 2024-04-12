# Colors
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# Compilers
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIB_DIR = libft/
MLX_DIR = MLX42/
LIBS = $(LIB_DIR)libft.a $(MLX_DIR)libmlx42.a
INCLUDES = -I $(LIB_DIR) -I $(MLX_DIR) -I.
GLFW = -Iinclude -lglfw

LIB_SYS = -L "/Users/ffauth-p/.brew/opt/glfw/lib/"

# Files
SRCS = main.c map.c errors.c aid.c display.c play.c cleanup.c
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = so_long

# Rules
all : $(NAME)

#$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS) $(READLINE)
$(NAME): $(OBJS) $(LIBS)
	@echo "$(MAGENTA)$(BOLD)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(GLFW) $(LIB_SYS) -o $@ $(OBJS) $(LIBS)
	@echo "$(CYAN)$(BOLD)Done.$(RESET)"

$(LIBS):
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(MAGENTA)$(BOLD)Cleaning objects from so_long...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(CYAN)$(BOLD)Done.$(RESET)"
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@make -C $(MLX_DIR) fclean

re : fclean all

.PHONY : all re fclean clean
