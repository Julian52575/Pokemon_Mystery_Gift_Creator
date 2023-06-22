# Hello world
#./PGT_patcher rom pgt
import sys

offset = 0x178200 + 0x50

if len( sys.argv ) != 3:
    print( "Usage: ./PGT_patcher\tROM file[.nds]\tMystery Gift file[.pgt]" )
    exit(1)

#Reading the pgt file
try:
    with open( sys.argv[2], mode='rb' ) as pgt_file :
        pgt_data = pgt_file.read()

except IOError:
    print( "[Error]\tThe Mystery Gift file does not exist !" )
    exit(84)

#Opening the rom for reading
try:
    with open( sys.argv[1], mode='rb' ) as rom :
        rom_data = rom.read()

except IOError:
    print( "[Error]\tThe ROM file does not exist !" )
    exit(84)

#Verifying the data of both files
    if len(rom_data) != 8388608:
        print( "[Error]\tThe ROM file has a wrong size." )
        exit(84)

    if len( pgt_data ) != 260 :
        print( "[Error]\tThe Mystery Gift file has a wrong size." )
        exit(84)


#Writing the new data to the rom
with open( sys.argv[1], mode='wb' ) as rom :
    rom_data = rom_data[:offset] + pgt_data + rom_data[ (offset + len(pgt_data)): ]
    rom.write(rom_data)


print( "The rom has been modified succesfully !" )