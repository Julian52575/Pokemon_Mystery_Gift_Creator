/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** bin_to_ascii
*/

char binary_to_ascii(unsigned char c, int half)
{
    if (half == 2) {
        c |= 0b11110000;
        c ^= 0b11110000;
    } else {
        c /= 16;
    }
    if (c <= 9) {
        return (char) 48 + c;
    } else {
        return (char) 65 + (c % 10);
    }
}
