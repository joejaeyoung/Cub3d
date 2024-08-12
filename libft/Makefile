YELLOW := \033[38;2;255;255;0m
BLUE := \033[0;36m
RESET := \033[0m
RED_START := 255
GREEN_START := 0
RED_END := 0
GREEN_END := 255
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar rc
RM := rm -f
NAME := libft.a
SRC_DIR := .
INC_DIR := .

LIST = ft_lstnew_field.c ft_lstnew_point.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdel_node.c ft_lstfind_node.c ft_lstlast.c ft_lstsize.c
ISFILE = ft_isrgb.c ft_issign.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isspace.c
NUM = ft_atoi.c ft_atoi_one.c ft_itoa.c
MEMORY = ft_memcpy.c ft_memmove.c ft_memset.c ft_realloc.c
PRINT = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STRING = ft_split.c ft_split_str.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c get_next_line.c
SRCS = $(LIST) $(ISFILE) $(NUM) $(MEMORY) $(PRINT) $(STRING)
OBJS := $(SRCS:.c=.o)
PROGRESS = 0
COUNT = $(words $(SRCS))
DONE = 0
BAR_FILLED = 0
BAR_EMPTY = 60
.PHONY : all start clean fclean re
all : $(NAME)
$(NAME) :
	@echo
	@make start --no-print-directory
	@$(AR) $(NAME) $(OBJS)
	@echo "  $(YELLOW)$(NAME)$(RESET) is ready!"
start : $(OBJS)
%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval DONE := $(shell echo $$(($(DONE) + 1))))
	@$(eval PROGRESS := $(shell echo $$(($(DONE) * 100 / $(COUNT)))))
	@RED=$$(($(RED_START) + $(PROGRESS) * ($(RED_END) - $(RED_START)) / 100)); \
	GREEN=$$(($(GREEN_START) + $(PROGRESS) * ($(GREEN_END) - $(GREEN_START)) / 100)); \
	COLOR="\033[38;2;$$RED;$$GREEN;0m"; \
	printf "\033[2A\033[K  $(YELLOW)$(NAME)$(RESET) is in progress: $(BLUE)$<$(RESET)\n"; \
	printf "$$COLOR\033[K	%3d$(RESET)%%│$$COLOR" $(PROGRESS); \
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
	@$(RM) $(OBJS)
fclean :
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "  $(YELLOW)$(NAME)$(RESET) is deleted."
re :
	@make fclean --no-print-directory
	@echo
	@make all --no-print-directory


