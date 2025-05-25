#include <stdio.h>
#include <inttypes.h>


int x = 0x76543210;
char *c = (char*) &x;
/*
Big endian format:
------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 |
              +++++++++++++++++++++++++++++
Byte content  | 0x76 | 0x54 | 0x32 | 0x10 |

Little endian format:
---------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 |
              +++++++++++++++++++++++++++++
Byte content  | 0x10 | 0x32 | 0x54 | 0x76 |
*/



typedef enum {
    LITTLE_ENDIAN,
    BIG_ENDIAN
} endianess_t;


/*
   Function check_for_endianness() returns 1, if architecture
   is little endian, 0 in case of big endian.
 */

int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}


endianess_t GetEndiannessArchi()
{
   unsigned int x = 0x76543210;
   char *c = (char*) &x;
   return (*c == 0x10)? LITTLE_ENDIAN : BIG_ENDIAN;

}

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    if (GetEndiannessArchi() == LITTLE_ENDIAN)
    {
        for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
      }
    }
    else
    {

    }

    puts("");
}

int main(int argc, char* argv[])
{
    int i = 23;
    uint32_t ui = INT32_MAX;
    float f = 23.45f;
    printBits(sizeof(i), &i);
    printBits(sizeof(ui), &ui);
    printBits(sizeof(f), &f);
    if (GetEndiannessArchi() == LITTLE_ENDIAN)
    {
      printf ("Underlying architecture is little endian. \n");
    }
    else
    {
     printf ("Underlying architecture is big endian. \n");
    }
    const int n = 1; // object of const-qualified type
    int* p = (int*)&n;
    *p = 2; // undefined behavior

    //int* p = 0;
    const int* cp = p; // OK: adds qualifiers (int to const int)
    p = cp; // Error: discards qualifiers (const int to int)
    p = (int*)cp; // OK: cast

    return 0;
}
