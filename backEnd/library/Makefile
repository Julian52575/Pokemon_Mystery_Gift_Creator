##
## RULIAN PROJECT, 2023
## Pokemon Mystery GIft Generator
## File description:
## Makefile
##

OUT 	= 	lib.a

SRC_FILES 	= 	bin_to_ascii.c \
			compare_hex_array.c \
			my_compute_power.c \
			my_open_file.c \
			print_hex_file.c \
			write_in_new_file.c
SRC_DIR = 	src

OBJ_FILES 	= 	bin_to_ascii.o \
			compare_hex_array.o \
			my_compute_power.o \
			my_open_file.o \
			print_hex_file.o \
			write_in_new_file.o
OBJ_DIR 	= 	obj
OBJ_DIR_FILES = $(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))
# % is the wildcard *
# Places OBJ_FILES after OBJ_DIR

CFLAGS 	= 	-Wall -Wextra -Wfatal-errors -g -O
INCLUDES 	= 	-I./includes/


		#Compiling source code#
#Output name $@ is the rule name 	aka 	object_dir/%current file.o
#File to compile $< 	aka 	source_dir/%current file.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c \
		-Iinc \
		-o $@ \
		$< \
		$(CFLAGS) \
		$(INCLUDES)


		#Building the lib#
#$^  
all: $(OBJ_DIR_FILES)
	ar rvs $(OUT) $^

.Phony:
	all test_run clean fclean re

clean:
	rm -f --verbose $(OBJ_DIR_FILES)

fclean: clean
	(test -f $(OUT) && rm --verbose $(OUT)) || exit 0

re: fclean all

