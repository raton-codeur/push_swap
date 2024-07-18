NAME = libft.a
FLAG = -Wall -Wextra -Werror
OBJECT = $(addprefix tmp/, $(notdir $(SOURCE:.c=.o)))
SOURCE = $(addprefix src/, \
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
	ft_memset.c \
	ft_print_char_and_string.c \
	ft_printf.c \
	ft_print_hex_and_pointer.c \
	ft_print_int_and_unsigned.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
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
	ft_strstr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c)

$(NAME) : $(OBJECT)
	ar rc $@ $^

tmp/%.o : src/%.c
	@ if [ ! -d tmp ]; then mkdir tmp; fi
	cc $(FLAG) -c $< -o $@

all : $(NAME)

clean :
	rm -rf tmp

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re