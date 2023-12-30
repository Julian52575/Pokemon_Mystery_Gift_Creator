##
## RULIAN PROJECT, 2023
## Pokemon Mystery GIft Generator
## File description:
## Makefile
##

NAME 	= 	update_checksum
SHARED_NAME 	= 	update_checksum.o
CRITERIONNAME 	= 	unit_test

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

debug:
	gcc -g -o $(NAME) \
			$(SRC) \
			$(LIBSRC) \
			$(CFLAGS) \
			$(INCLUDES)

test_run:
	gcc -o $(CRITERIONNAME) \
			src/update_checksum.c \
			$(LIBSRC) \
			$(CRITERION) \
			$(CFLAGS) \
			$(CRITERIONFLAGS) \
			$(INCLUDES)
	./unit_test

shared:
	gcc src/update_checksum.c \
			$(LIBSRC) \
			$(CFLAGS) \
			$(INCLUDES) \
			-fPIC -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.Phony:
	all debug test_run clean fclean re
