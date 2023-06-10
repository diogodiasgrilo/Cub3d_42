PROJECT_NAME = Cub3D

SRC_PATH = srcs

## MODULES ##

SRC_FILES =  $(wildcard $(addprefix $(SRC_PATH)/, *.c))

SRCS = $(SRC_FILES)#$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = cub3D

CC = cc

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = [$(CYAN)$(PROJECT_NAME)$(RESET)]

### END OF COLORS ###

## SYSTEM DEPENDENCIES ##

__SYSTEM__ = $(shell uname -s)
__S_MACOS__ = Darwin
__S_LINUX__ = Linux

## LIBRARIES ##

LIBFT_PATH = libs/libft
LIBFT_BIN = $(addprefix $(LIBFT_PATH)/,bin)
LIBFT_INCLUDES = $(addprefix $(LIBFT_PATH)/,includes/)
LIBFT_ARCH = $(addprefix $(LIBFT_BIN)/,libft.a)

MLX_PATH = $(addprefix libs/mlx_, $(__SYSTEM__))
MLX_ARCH = $(addprefix $(MLX_PATH)/,libmlx.a)

PROGRAM_FLAGS = -L$(LIBFT_BIN) -L$(MLX_PATH) -lft -lmlx
ifeq ($(__SYSTEM__), $(__S_LINUX__))
	INCLUDES =			-I /usr/include -D OS=0
	PROGRAM_FLAGS +=	-L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(__SYSTEM__), $(__S_MACOS__))
	INCLUDES =			-I /usr/local/include -D OS=1
	PROGRAM_FLAGS +=	-framework OpenGL -framework AppKit \
						-L /opt/X11/lib -lXext -lX11 \
						-L/usr/local/lib -lpng
else
$(error $(__SYSTEM__) is not supported)
endif

INCLUDES += -Iinclude -I$(LIBFT_INCLUDES) -I$(MLX_PATH)
CFLAGS = $(INCLUDES) -Wall -Wextra -Werror -O3 -g -fsanitize=address

## RULES ##

all: $(NAME)

### LIBS ###

$(LIBFT_ARCH):
	@make -C $(LIBFT_PATH) --no-print-directory --silent

$(MLX_ARCH):
	@make -C $(MLX_PATH) --no-print-directory --silent

### END OF LIBS ###

$(NAME): $(LIBFT_ARCH) $(MLX_ARCH) $(OBJS)
	@echo "$(TAG) compiling $(YELLOW)$(NAME)$(RESET).."
	@$(CC) $(OBJS) $(CFLAGS) $(PROGRAM_FLAGS) -o $(NAME)
	@echo "$(CYAN)Done!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@echo "$(TAG) compiling $(YELLOW)$<$(RESET).."
	@mkdir -p $(OBJ_DIR)/$(<D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJ_DIR) *.o
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@make -C $(MLX_PATH) clean --no-print-directory
	@echo "$(TAG) cleaned $(YELLOW)objects!$(RESET)"
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@make -C $(MLX_PATH) clean --no-print-directory
	@echo "$(TAG) cleaned $(YELLOW)archive!$(RESET)"
watch:
	@echo "$(TAG) watching for changes.."
	@while true; do ($(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory); sleep 1; done;

re: fclean all

vg: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re watch
