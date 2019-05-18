#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 01:58:26 by mbiliaie          #+#    #+#              #
#    Updated: 2019/04/30 01:58:30 by mbiliaie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= 	asm
CFLAGS 	= 	-Wall -Werror -Wextra
CC 		= 	clang

SRC_DIR = 	src/
HDR_DIR = 	includes/
OUT_DIR = 	obj/

L_NAME 	= 	libft
LIB_DIR = 	$(L_NAME)/
LIB_HDR = 	$(LIB_DIR)
LIBFT 	= 	$(LIB_DIR)$(L_NAME).a
LIB 	= 	-lft -L$(LIB_DIR)

INCL 	= 	-I$(HDR_DIR) -I$(LIB_HDR)
HDR 	= 	$(HDR_DIR)asm.h \
		 	$(HDR_DIR)op.h

SRC 	=	main.c \
			compl.c 		\
			compl_sys.c 		\
			asm_decompiler.c \
			gd_static.c \
			get_bwd_and_utilities.c \
			gen_functions.c \
			gen_functions_2.c \
			validate_starting_commands.c \
			handler_decompl.c \
			load_entering_info.c \
			load_starting_vals.c \
			loader_start.c \
			loader.c			\
			utilities_for_loading.c \
			markers.c \
			markers_set_indir.c \
			markers_set_dir.c \
			markers_functions.c \
			markers_starter.c \
			op.c			\
			reader_sys.c \
			tokenizer_sys.c \
			tokenizer_functions.c

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