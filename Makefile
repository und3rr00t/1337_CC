NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I .
HEADER = libft.h

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
        ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
        ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
        ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
        ft_tolower.c ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c ft_calloc.c

SBNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
        ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJBNS = $(SBNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all $(OBJBNS)
	ar rcs $(NAME) $(OBJBNS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJBNS)

fclean: clean
	rm -rf $(NAME) libft.so

re: fclean all

# ---------- Shared Library (for libft-unit-test) ----------
so:
	$(CC) -fPIC $(CFLAGS) $(INCLUDES) -c $(SRCS) $(SBNS)
	$(CC) -shared -o libft.so $(OBJS) $(OBJBNS)

.PHONY: all bonus clean fclean re so

