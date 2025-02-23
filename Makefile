BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX_DIR = ./minilibx-linux

MINILIBX_INC = -I$(MINILIBX_DIR)
LIBS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(SRC_DIR)/fractol.c $(SRC_DIR)/print_functions.c $(SRC_DIR)/set_values.c \
	  $(SRC_DIR)/init_and_open_win.c $(SRC_DIR)/mlx_utils.c $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/event_loops.c $(SRC_DIR)/key_press_events.c $(SRC_DIR)/mouse_scroll_events.c \
	  $(SRC_DIR)/change_iterations.c $(SRC_DIR)/burning_ship_set.c \
	  $(SRC_DIR)/mandelbrot_set.c $(SRC_DIR)/julia_set.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MINILIBX_NAME = $(MINILIBX_DIR)/libmlx_Linux.a
NAME = $(BIN_DIR)/fractol

all: $(MINILIBX_NAME) $(NAME)

$(MINILIBX_NAME):
	@echo -e "$(GREEN)$(BOLD)Compiling MiniLibX...$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo -e "$(GREEN)$(MINILIBX_NAME) compiled successfully!...$(RESET)"

$(BIN_DIR):
	@mkdir -p $@
	@echo -e "$(CYAN)'$(BIN_DIR)' directory created...$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@
	@echo -e "$(CYAN)'$(OBJ_DIR)' directory created...$(RESET)"

$(NAME): $(OBJ) | $(BIN_DIR)
	@echo -e "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
	@echo -e "$(GREEN)$(BOLD)$(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(MINILIBX_INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo -e "$(RED)Cleaned object files...$(RESET)"

fclean:
	@$(MAKE) clean -C $(MINILIBX_DIR) > /dev/null
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@echo -e "$(RED)Cleaned MiniLibX, object files and bin directory...$(RESET)"

re: fclean all

.PHONY: all clean fclean re
