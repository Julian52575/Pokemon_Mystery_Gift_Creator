##
## RULIAN PROJECT, 2023
## Pokemon Mystery Gift Generator
## File description:
## Makefile
##

NAME = libMysteryGift.so.0.1

LIB_SRC 	= 	$(shell find ./library/src/ -type f -name '*.c')
DECRYPT_SRC 	= 	./decrypt/src/decrypt.c

LIB_OBJ 	= 	$(LIB_FILES:.c=.o)
DECRYPT_OBJ 	= 	$(DECRYPT_FILES:.c=.o)

OBJ_DIR 	= 	./obj

CFLAGS 	= 	-Wall \
			-Wextra \
			-Wfatal-errors \
			-g

INCLUDES 	= 	-I./library/includes/ \
				-I./decrypt/

#gcc -shared -Wl,-soname,libmystuff.so.1 \
 #   -o libmystuff.so.1.0.1 a.o b.o -lc


#.#.#.
decrypt:
	gcc -fPIC -c \
		$(CFLAGS) \
		$(DECRYPT_FILES) \
		-o 


decrypt_clean:
	rm $(DECRYPT_OBJ)

#.#.#.
library:
	gcc -fPIC -c \
		$(CFLAGS) \
		$(LIB_FILES)

library_clean:
	rm $(LIB_OBJ)


fclean:
	rm $(NAME)



all: library decrypt
	gcc -shared -fPIC -c \
		$(CFLAGS) \
		$(INCLUDES) \
		-o $(NAME) \
		$(LIB_OBJ) \
		$(DECRYPT_OBJ)


.Phony: fclean decrypt library
