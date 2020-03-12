# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 00:30:05 by fallard           #+#    #+#              #
#    Updated: 2020/02/23 00:30:10 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
parse.c \
print_result.c \
print_flags.c \
base.c \
pf_itoa.c \
dec_numbers.c \
dec_treatment.c \
specifier.c \
macros.c \
floats.c \
float_valide.c \
float_round_up.c \
long_arithmetic_int.c \
long_arithmetic_frac.c \
long_float_treatment.c \
print_bin.c \
print_iso_time.c \
print_iso_func.c \
helpers.c

TEMP = $(SRCS:.c=.o)

RD = \x1b[31m
GR = \x1b[32m
YW = \x1b[33m
BL = \x1b[34m
PK = \x1b[35m
CN = \x1b[36m
EOC = \x1b[0m

PF_H = -I .
LIB_H = -I libft/libft.h

LIB = libft

all: $(NAME)

$(NAME): $(LIB)/libft.a $(TEMP)
	@printf "$(YW)Copying libft.a to root directory...\n$(EOC)"
	@cp libft/libft.a .
	@printf "$(YW)Rename $(LIB).a to $(NAME)...\n$(EOC)"
	@mv libft.a $(NAME)
	@ar rc $(NAME) $(TEMP)
	@printf "$(GR)LIBFTPRINTF SUCCESSFULLY COMPILED!\n$(EOC)"

%.o:%.c
	@gcc $(FLAGS) $(PF_H) $(LIB_H) -o $@ -c $< 

$(LIB)/libft.a:
	@printf "\n$(PK)COMPILING PROJECT...\n\n$(EOC)"
	@make -C libft/
	@printf "$(GR)Libft.a compiled!\n$(EOC)"

clean: cleanlib
	@rm -f $(TEMP)
	@printf "$(YW)TEMP OBJECTS HAS BEED DELETED.\n$(EOC)"

fclean: clean fcleanlib
	@rm -f $(NAME)
	@printf "$(RD)LIBFTPRINTF, TEMP OBJECTS AND LIBFT HAS BEEN DELETED.\n$(EOC)"

re: fclean all

cleanlib:
	@make clean -C libft/

fcleanlib:
	@make fclean -C libft/
