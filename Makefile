NAME			:= build/cub3d
BUILD_DIR		:= build

CC				:= cc
CFLAGS			:= -Wextra -Wall -Werror -MMD -MP -Wunreachable-code -O0 -g
LDFLAGS			:= -ldl -lglfw -pthread -lm

# Libraries
LIBFT			:= ./libs/libft
LIBMLX			:= ./libs/MLX42
LIBS			:= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a 

# Directories
INCLUDE_DIRS	:= includes $(LIBFT)/includes $(LIBMLX)/include
INCLUDES		:= $(foreach dir,$(INCLUDE_DIRS),-I$(dir))

# Files
SRC_DIR			:= src
SRC				:= main.c

OBJ				:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP				:= $(OBJ:.o=.d)

TOTAL_FILES		:= $(words $(SRC))
COMPILED		:= 0

# Colors
GREEN 			:= \033[0;32m
YELLOW			:= \033[0;33m
RED				:= \033[0;31m
BLUE			:= \033[0;34m
RESET			:= \033[0m

$(NAME): $(OBJ) $(LIBS)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)🔧 Linking objects...$(RESET)"
	@$(CC) $(OBJ) $(LIBS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) built successfully$(RESET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@printf "$(BLUE)[%d/%d]$(RESET) Compiling %s\n" $(COMPILED) $(TOTAL_FILES) "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT)/libft.a:
	@echo "$(YELLOW)📚 Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT) --silent

$(LIBMLX)/build/libmlx42.a:
	@echo "$(YELLOW)📚 Building MLX42...$(RESET)"
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build > /dev/null
	@cmake --build $(LIBMLX)/build -j4 > /dev/null

# Rules
all: $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) clean -C $(LIBFT) --silent
	@rm -rf $(LIBMLX)/build
	@echo "$(RED)🧴 Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT) --silent
	@echo "$(RED)🧼 Everything cleaned$(RESET)"

re: fclean all

norminette:
	@echo "$(YELLOW)🧠 Running norminette...$(RESET)"
	@norminette src includes

-include $(DEP)

.PHONY: all clean fclean re norminette valgrind