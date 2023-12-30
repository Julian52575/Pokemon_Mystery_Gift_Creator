##
## RULIAN PROJECT, 2023
## Pokemon Mystery Gift Generator
## File description:
## Makefile
##
YEL=\033[1;33m # thx StackOverflow
NC=\033[0m # No Color



NAME = libMysteryGift.so
LIB_NAME = ./library/libmy.a
FOLDER_LIST = 	./decrypt/ \
				./update_checksum/


CFLAGS 	= 	-Wall \
			-Wextra \
			-Wfatal-errors \
			-g


		#Calling makefile in each subfolder
#Rule name $@ is the current folder 	
all: cleanSO cleanOBJ
	make re -C ./library/
	$(foreach folder,$(FOLDER_LIST), make shared -C $(folder);) #call a makefile for each folder in folder_list
	gcc -shared -fPIC \
		-o $(NAME) \
		$(CFLAGS) \
		-L$(LIB_NAME) \
		./obj/*.o

cleanOBJ:
	test -d ./obj/ || mkdir --verbose ./obj #Only mkdir obj if obj is not found
	(find ./obj/ -empty | grep obj) || rm --verbose ./obj/*.o #Only rm .* if obj folder is empty

cleanSO:
	test $(NAME) || rm --verbose $(NAME)

fclean: cleanSO cleanOBJ

.Phony: all cleanSO cleanOBJ fclean decrypt library
