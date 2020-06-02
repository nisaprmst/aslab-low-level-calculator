#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned char num)
{
   for(int bit=0;bit<(sizeof(unsigned char) * 8); bit++)
   {
      printf("%i ", num & 0x1);
      num = num >> 1;
   }
}

int main() {
    unsigned char c;
    unsigned int d;
    scanf("%c", &c);
    d = (unsigned int) c;
    printf("%d\n", d);
    printBits(c);
    return 0;
}