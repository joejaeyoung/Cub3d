BLUE := \033[0;36m
RESET := \033[0m

RED_START := 255
GREEN_START := 0
RED_END := 0
GREEN_END := 255

PROGRESS = 0
COUNT = $(words $(SRCS))
DONE = 0
BAR_FILLED = 0
BAR_EMPTY = 60

CC := cc
CFLAGS := -g
LIBXFLAGS = -L minilibx-linux -lmlx -lXext -lX11 -lm
HPATH = -I minilibx-linux
RM := rm -f

# MANDATORY PART
NAME := cub3D

SRC_DIR := .
INC_DIR := .
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

MAP = map.c map_utils.c map_color.c map_texture.c
TMP = tmp.c
VALIDATION = validation.c validation_field.c validation_field_utils.c
DRAW = draw_map.c draw_minimap.c draw_utils.c
KEY = key_hook.c key_move.c
RAY = ray.c ray_utils.c

SRCS := error.c main.c free.c $(MAP) $(KEY) $(VALIDATION) $(TMP) $(DRAW) $(RAY)
OBJS := $(SRCS:.c=.o)

.PHONY : all start clean fclean re

all : $(NAME)

$(NAME) : 
	@make -C $(LIBFT_DIR) all --no-print-directory
	@echo
	@echo
	@make start --no-print-directory
	@$(CC) $(CFLAGS) $(LIBXFLAGS) $(OBJS) $(LIBFT) minilibx-linux/libmlx.a -iquote $(INC_DIR) -o $(NAME)
	@echo "  Completed! "
	
start : $(OBJS)

%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I minilibx-linux -c $< -o $@
	@$(eval DONE := $(shell echo $$(($(DONE) + 1))))
	@$(eval PROGRESS := $(shell echo $$(($(DONE) * 100 / $(COUNT)))))
	@RED=$$(($(RED_START) + $(PROGRESS) * ($(RED_END) - $(RED_START)) / 100)); \
	GREEN=$$(($(GREEN_START) + $(PROGRESS) * ($(GREEN_END) - $(GREEN_START)) / 100)); \
	COLOR="\033[38;2;$$RED;$$GREEN;0m"; \
	printf "\033[2A\033[K  Currently working on: $(BLUE)$<$(RESET)\n"; \
	printf "$$COLOR\033[K    %3d$(RESET)%%│$$COLOR" $(PROGRESS); \
	BAR_FILLED=$$(($(PROGRESS) / 5 * 3)); \
	BAR_EMPTY=$$((60 - $$BAR_FILLED)); \
	for i in $$(seq 1 $$BAR_FILLED); do \
		printf "█"; \
	done; \
	for i in $$(seq 1 $$BAR_EMPTY); do \
		printf " "; \
	done; \
	printf "$(RESET)│\n"

clean :
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@$(RM) $(OBJS)
	@echo "  All object files are deleted."

fclean :
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "  All object files and $(BLUE)$(NAME)$(RESET) are deleted."
re :
	@make fclean --no-print-directory
	@echo
	@make all --no-print-directory

