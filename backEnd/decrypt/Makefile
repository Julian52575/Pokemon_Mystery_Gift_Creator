##
## RULIAN PROJECT, 2023
## Pokemon Mystery GIft Generator
## File description:
## Makefile
##

NAME 	= 	decrypt_pokemon_file
CRITERIONNAME 	= 	unit_test

SRC 	= 	$(shell find src/ -type f -name '*.c')
LIBSRC 	= 	$(shell find ../library/src/ -type f -name '*.c')
CRITERION 	= 	$(shell find criterion/*_t.c)


OBJ 	= 	$(SRC.c=.o)

CFLAGS 	= 	-Wall -Wextra -Wfatal-errors -g
INCLUDES 	= 	-I../library/ -I./
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

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.Phony:
	all test_run clean fclean re
