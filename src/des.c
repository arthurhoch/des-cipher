#include "des.h"

int main()
{
    block a;
    a.doubleWord = 4294967295;
    a.bit._0 = 0;

    printf("%u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t\n", a.bit._0, a.bit._1, a.bit._2, a.bit._3, a.bit._4, a.bit._5, a.bit._6, a.bit._7, a.bit._8, a.bit._9, a.bit._10, a.bit._11, a.bit._12, a.bit._13, a.bit._14, a.bit._15, a.bit._16, a.bit._17, a.bit._18, a.bit._19, a.bit._20, a.bit._21, a.bit._22, a.bit._23, a.bit._24, a.bit._25, a.bit._26, a.bit._27, a.bit._28, a.bit._29, a.bit._30, a.bit._31);
    printf("%i\t %i\t %i\t %i\t %i\t %i\t %i\t %i\t\n", a.nibble._0, a.nibble._1, a.nibble._2, a.nibble._3, a.nibble._4, a.nibble._5, a.nibble._6, a.nibble._7);
    printf("0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t\n", a.nibble._0, a.nibble._1, a.nibble._2, a.nibble._3, a.nibble._4, a.nibble._5, a.nibble._6, a.nibble._7);
    printf("\t %i\t\t %i\t\t %i\t\t %i\t\t\n", a.byte._0, a.byte._1, a.byte._2, a.byte._3);
    printf("\t 0x%02X\t\t 0x%02X\t\t 0x%02X\t\t 0x%02X\n", a.byte._0, a.byte._1, a.byte._2, a.byte._3);
    printf("\t\t\t %i\t\t\t\t %i\n", a.word._0, a.word._1);
    printf("\t\t\t 0x%03X\t\t\t\t 0x%03Xx\n", a.word._0, a.word._1);
    printf("\t\t\t\t\t\t\t %u\n", a.doubleWord);
    printf("\t\t\t\t\t\t\t 0x%X\n", a.doubleWord);

}
