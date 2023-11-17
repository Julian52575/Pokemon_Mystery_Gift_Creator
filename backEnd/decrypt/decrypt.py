import sys
import struct

def printHexFile(hexFile):
    for i in range(0, len(hexFile), 2 ):

        if ( i % 16 == 0 ):
            print(end=" ")

        if ( i % 32 == 0 ):
            print("\n", hex( int(i / 2) ), "\t", end="")

        print(f"{hexFile[i]}{hexFile[i+1]}", end=" ")
    print(end="\n")


#.#.#.
def PRNG_call(int : seed):
    return (0x41C64E6Du * seed) + 0x00006073u


def decryptPokemonFile(str : pokemonFile) :
    for int i in range(0, 0x104, 1):
        pokemonFile[i]
    return pokemonFile



#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#
if ( len(sys.argv) != 2 ) :
    print("Usage: decrypt {file}")
    exit (84)



file_path = sys.argv[1]
hexFile = ""
try:
    with open(file_path, 'rb') as file:
        hexFile = file.read().hex()

except FileNotFoundError:
    print(f"The file '{file_path}' does not exist.")
except Exception as e:
    print(f"An error occurred: {e}")

if ( (len(hexFile) / 2) != 0x104 ):
    print("Error:\tInvalid file lenght.\nExpected 0x104 but got ", (len(hexFile) / 2), ".")
    exit(84)


printHexFile(hexFile)
print("---")
UnecryptedFile = decryptPokemonFile(hexFile)
printHexFile(UnecryptedFile)


#
#
#file lenght : 260d / 104x.

