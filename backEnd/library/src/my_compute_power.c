/*
** RULIAN PROJECT, 2023
** Pokemon Mystery Gift Generator
** File description:
** my_compute_power
*/

long long int
my_compute_power(int nb, int pow)
{
    int result = nb;

    for (; pow > 1; pow--) {
        result = result * nb;
    }
    return result;
}
