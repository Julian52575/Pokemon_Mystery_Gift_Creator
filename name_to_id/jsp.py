
#python

import sys

#defines
DELIMITER_LIST = " \t_-/\\"
END_OF_LINE = "\n\0"


def get_file_content(file_name : str) :
    with open( sys.argv[1], mode='r' ) as file :
        string = file.read()
    return string



if len(sys.argv) != 2 :
    exit(84)


string = get_file_content( sys.argv[1] )
string = string.replace("\n\n", "\n")

liste = string.rsplit('\n')

for i in range( 0, len(liste) ) :
    liste[i] = liste[i].rsplit( '\t' )
    if ( liste[i][3][-1] == '*' ) :
        print( liste[i][3][:-1] )
    else :
        print( liste[i][3] )

