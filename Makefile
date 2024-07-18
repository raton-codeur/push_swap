NAME = push_swap
NAME_BONUS = checker
FLAG = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SOURCE_BONUS = src/bonus/bonus.c
OBJECT_BONUS = tmp/bonus.o
OBJECT = $(addprefix tmp/, $(notdir $(SOURCE:.c=.o)))
SOURCE = $(addprefix src/, \
	base_3_bottom_a_1.c \
	base_3_bottom_a_2.c \
	base_3_bottom_b_1.c \
	base_3_bottom_b_2.c \
	base_3_generic.c \
	base_3_top_a.c \
	base_3_top_b_1.c \
	base_3_top_b_2.c \
	base_case.c \
	get_from_sub_stack_1.c \
	get_from_sub_stack_2.c \
	initialization.c \
	initialize_arguments.c \
	list.c \
	main.c \
	operation_1.c \
	operation_2.c \
	operation_3.c \
	operation_generic.c \
	operation_generic_utils.c \
	optimize.c \
	push_sub_stack.c \
	sort.c \
	wrong_input.c \
	input_test_overflow.c \
	sort_5.c \
	free.c)

$(NAME) : $(OBJECT)
	make -C libft
	cc $(FLAG) $^ $(LIBFT) -o $@

tmp/%.o : src/%.c
	@ if [ ! -d tmp ]; then mkdir tmp; fi
	cc $(FLAG) -c $< -o $@

all : $(NAME)

clean :
	make clean -C libft
	rm -rf tmp

fclean : clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

$(NAME_BONUS) : $(filter-out tmp/main.o, $(OBJECT)) $(OBJECT_BONUS)
	make -C libft
	cc $(FLAG) $^ $(LIBFT) -o $@

tmp/%.o : src/bonus/%.c
	cc $(FLAG) -c $< -o $@

bonus : $(NAME_BONUS)

.PHONY : all clean fclean re bonus
