##
## RULIAN PROJECT, 2023
## Pokemon Mystery GIft Generator
## File description:
## Makefile
##
YEL=\033[1;33m # thx StackOverflow
NC=\033[0m # No Color


NAME 	= 	update_checksum.out
SHARED_NAME 	= 	update_checksum.o
CRITERIONNAME 	= 	unit_test
LIB_PATH = ../library/libmy.a

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
	echo -e "$(YEL)\tCompiling src/update_checksum.c\t$(NC)"
	gcc src/update_checksum.c \
			-L../library/lmy -lmy \
			$(CFLAGS) \
			$(INCLUDES) \
			-c
	mv ./update_checksum.o ../obj

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.Phony:
	all debug test_run clean fclean re
