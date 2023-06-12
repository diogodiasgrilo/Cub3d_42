NAME = libft.a

SRCS =	ft_printf.c \
		ft_hex_printer.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strenlarge.c \
		ft_memset.c \
		ft_countchar.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		get_next_line_utils.c \

BONUS_SRC = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

OBJS :=$(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all bonus clean fclean re

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

