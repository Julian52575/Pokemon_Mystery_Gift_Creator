# Hello world
#./PGT_patcher rom pgt
import sys

offset = 0x178200 + 0x50

if len( sys.argv ) != 2:
    print( "Usage: python3 PGT_extract\tROM file[.nds]\n")
    exit(84)

try:
    with open( sys.argv[1], mode='rb' ) as rom_data :
        pgt_data = rom_data.read()[offset : (offset + 260)]
        
except IOError:
    print( "[Error]\tThe Mystery Gift file does not exist !" )
    exit(84)

if len( pgt_data ) != 260 :
    print( "[Error]\tThe Mystery Gift file has a wrong size." )
    exit(84)


new_pgt_name = sys.argv[1].replace(".nds", ".pgt")
#Writing the new data to the rom
with open( new_pgt_name, mode='wb' ) as file :
    file.write(pgt_data)


print( "The pgt has been extracted succesfully !" )
