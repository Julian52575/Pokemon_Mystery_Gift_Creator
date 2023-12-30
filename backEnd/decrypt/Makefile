##
## RULIAN PROJECT, 2023
## Pokemon Mystery GIft Generator
## File description:
## Makefile
##
YEL=\033[1;33m # thx StackOverflow
NC=\033[0m # No Color

NAME 	= 	decrypt_pokemon_file.out
SHARED_NAME 	= 	decrypt_pokemon_file.o
CRITERIONNAME 	= 	unit_test
LIB_NAME = 	../library/libmy.a


SRC 	= 	$(shell find src/ -type f -name '*.c')
LIBSRC 	= 	$(shell find ../library/src/ -type f -name '*.c')
CRITERION 	= 	$(shell find criterion/*.c)

OBJ 	= 	$(SRC.c=.o)

CFLAGS 	= 	-Wall -Wextra -Wfatal-errors -g
INCLUDES 	= 	-I../library/includes/ -I./
CRITERIONFLAGS 	= 	-lcriterion

all:
	gcc -o $(NAME) \
			$(SRC) \
			$(LIBSRC) \
			$(CFLAGS) \
			$(INCLUDES)

test_run:
	gcc -o $(CRITERIONNAME) \
			src/decrypt.c \
			$(LIBSRC) \
			$(CRITERION) \
			$(CFLAGS) \
			$(CRITERIONFLAGS) \
			$(INCLUDES)
	./unit_test

shared:
	echo -e "$(YEL)\tCompiling src/decrypt.c\t$(NC)"
	gcc src/decrypt.c \
		-L../library/my -lmy \
			$(CFLAGS) \
			$(INCLUDES) \
			-c
	mv ./decrypt.o ../obj

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.Phony:
	all test_run clean fclean re
