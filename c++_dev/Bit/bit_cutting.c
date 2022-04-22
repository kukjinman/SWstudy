#include <stdio.h>

int main(void)
{
    /* define a small bit-field that can hold values from 0 .. 7 */
    struct
    {

	// This uint3 : 3 <- contains only 3 bits
	// uint 3 : 5 <- contains 5 bits    
	    unsigned int uint3: 4;
    } small;

    /* extract the right 3 bits from a value */
    unsigned int value = 255 - 2; /* Binary 11111101 */
    small.uint3 = value;          /* Binary      101 */
    printf("%d", small.uint3);

    /* This is in effect an infinite loop */
    for (small.uint3 = 0; small.uint3 < 16; small.uint3++)
    {
        printf("%d\n", small.uint3);
    }

    return 0;
}



