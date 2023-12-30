##
## RULIAN PROJECT, 2023
## Pokemon Mystery Gift Generator
## File description:
## Makefile
##

NAME = Mystery_Gift_Generator
SONAME = backend/libMysteryGift.so

SRC = $(shell find src/ -type f -name '*.c')

CFLAGS 	= 	-Wall \
			-Wextra \
			-Wfatal-errors \
			-g

INCLUDES 	= 	-I./backEnd/library/includes/

#gcc -shared -Wl,-soname,libmystuff.so.1 \
 #   -o libmystuff.so.1.0.1 a.o b.o -lc


#.#.#.

all:
	make -C ./backEnd/
	gcc $(CFLAGS) \
		$(INCLUDES) \
		-o $(NAME) \
		$(SRC) \
		-L./$(SONAME) -lMysteryGift

fclean:
	rm $(NAME)

.Phony: fclean all
