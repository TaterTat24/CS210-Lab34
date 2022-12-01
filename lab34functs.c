/** lab34functs.c
* ===========================================================
* Name: Benjamin Tat
* Section: T6
* Project: Lab 34
* =========================================================== 
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "lab34functs.h"


/** ----------------------------------------------------------
 * @fn void print_bits(void* ptr, int num_bytes)
 * @brief prints char representation of any variables individual bits
 * @param ptr is a pointer to the variable being printed
 * @param num_bytes is the number of bytes in the variable
 * @return void, prints each bit as a character, ends with a new line
 * ----------------------------------------------------------
 */
void print_bits(void* ptr, int num_bytes) {
    // Cast the pointer as an unsigned byte
    uint8_t* byte = ptr;

    // For each byte, (bytes are little endian ordered)
    for (int i = num_bytes - 1; i >= 0; --i) {

        // For each bit, (inside the byte, bits are big endian ordered)
        for (int j = 7; j >= 0; --j) {

            // Print a character 1 or 0, given the bit value
            printf("%c", (byte[i] >> j) & 1 ? '1' : '0');
        }

        // Separate bytes
        printf(" ");
    }

    // End with a new line
    printf("\n");
}

int check_bit(int value, int bit){
    return ((value >> bit) & 1);
}

int reverse_bits(unsigned value){
    // Initialize the output to 0
    unsigned int output = 0;

    // For each bit in the input
    for (int i = 0; i < 32; ++i) {

        // Shift the output left by 1
        output <<= 1;

        // Add the current bit to the output
        output |= (value >> i) & 1;
    }

    // Return the output
    return output;
}

int bit_rotate_left(unsigned int input, int num_bits) {

    // Returns bits rotated left by num_bits
    return (input << num_bits) | (input >> (32 - num_bits));
}

int bit_rotate_right(unsigned int input, int num_bits) {

    // Returns bits rotated right by num_bits
    return (input >> num_bits) | (input << (32 - num_bits));
}

int make_crc(char string[]) {

        // Initialize the crc32 value to all ones
        unsigned int crc32 = 0xFFFFFFFF;

        // For each byte in the string
        for (int i = 0; i < strlen(string); ++i) {

            // Calculate the table index
            int index = (crc32 ^ string[i]) & 0xFF;

            // Update the crc32 value
            crc32 = (crc32 >> 8) ^ CRCTAB[index];
        }

        // Return the inverse of the crc32 value
        return ~crc32;
}
        