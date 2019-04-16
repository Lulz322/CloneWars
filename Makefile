#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 18:26:55 by mbiliaie          #+#    #+#              #
#    Updated: 2019/04/16 18:26:58 by mbiliaie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC 		= clang
NAME 	= asm
CFLAGS 	= -Wall -Werror -O3 -Wextra

SRC_DIR = source/
HDR_DIR = include/
OUT_DIR = obj/

L_NAME 	= libft
LIB_DIR = $(L_NAME)/
LIB_HDR = $(LIB_DIR)
LIBFT 	= $(LIB_DIR)$(L_NAME).a
LIB 	= -lft -L$(LIB_DIR)

INCL 	= -I$(HDR_DIR) -I$(LIB_HDR)
HDR 	= include/asm.h

SRC 	=	main.c

OBJ	= $(addprefix $(OUT_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OUT_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(INCL) $(OBJ) -o $(NAME)
	@echo "$(L_NAME).a is ready!"
	@echo "--- --- --- --- --- --- --- ---"
	@echo "obj directory has been made"
	@echo "o-files have been produced"
	@echo "--- --- --- --- --- --- --- ---"
	@echo "$(NAME) is ready!"

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -c $(INCL) $< -o $@

$(LIBFT):
	@echo "--- --- --- --- --- --- --- ---"
	@echo "compiling" $(L_NAME)"..."
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@echo "$(L_NAME).a has been removed"
	@rm -rf $(OUT_DIR)
	@echo "obj directory has been removed"
	@echo "o-files have been removed"

fclean: clean
	@rm -f $(LIBFT)
	@echo "--- --- --- --- --- --- --- ---"
	@rm -f $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all

.PHONY: all clean fclean re   