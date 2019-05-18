ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
#	LIBS := -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
#	LIBSINC := -F $(CURDIR)/frameworks
#	LIBS := -F $(CURDIR)/frameworks -rpath $(CURDIR)/frameworks -framework SDL2 \
		-framework SDL2_mixer -framework SDL2_ttf
endif

#	-march=native		- Setups compiler to use all available CPU instructions for
#							optimizing compiling time
#	-mtune=native		- Setups compiler to compiling all correctly for
#							current system architecture on which project compiling
#	-flto				- Enable Link Time Optimization
#	-Ofast				- MAXIMUM OPTIMIZATION

all:
	make -C WM/
	make -C asm/

LIBFT :
	make -C WM/
	make -C asm/

$(NAME): $(LIBFT)
		
clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: all fclean clean re
