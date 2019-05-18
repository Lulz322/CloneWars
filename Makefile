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

COREWAR := corewar
ASM := asm

all:
	make -C WM/
	make -C Assambler/
	mv WM/corewar ./
	mv Assambler/asm ./
	
clean:
	make clean -C WM/
	make clean -C Assambler/

fclean: 
	make fclean -C WM/
	make fclean -C Assambler/
	@rm -rf $(COREWAR) $(ASM) 
re: fclean all

.PHONY: all fclean clean re
