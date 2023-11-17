##
## RULIAN PROJECT, 2023
## Pokemon Mystery Gift Generator
## File description:
## Makefile
##

NAME = libMysteryGift.so

LIB_FILES 	= 	$(shell find ./library/src/ -type f -name '*.c')
DECRYPT_FILES 	= 	$(shell find ./decrypt/src/ -type f -name '*.c')

OBJ 	= 	$(LIB_FILES:.c=.o) \
			$(DECRYPT_FILES:.c=.o)

CFLAGS 	= 	-shared -Wall -Wextra -Wfatal-errors -pedantic-errors -g
INCLUDES 	= 	-I./library/


all:
	gcc -o $(NAME) \
			$(LIB_FILES) 	\
			$(DECRYPT_FILES) \
			$(INCLUDES) 	\
			$(INCLUDES)

clean:
	make -C asm/ clean

.Phony:
