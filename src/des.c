#include "des.h"

int main()
{
    block a,b;
    uint64_t teste = 9223372036854775806; 
    
    a.doubleWord = teste;
    // b.bit._0 = 0;
    teste = teste >> 31;
    b.doubleWord = teste;

    printf("%u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t\n", b.bit._0, b.bit._1, b.bit._2, b.bit._3, b.bit._4, b.bit._5, b.bit._6, b.bit._7, b.bit._8, b.bit._9, b.bit._10, b.bit._11, b.bit._12, b.bit._13, b.bit._14, b.bit._15, b.bit._16, b.bit._17, b.bit._18, b.bit._19, b.bit._20, b.bit._21, b.bit._22, b.bit._23, b.bit._24, b.bit._25, b.bit._26, b.bit._27, b.bit._28, b.bit._29, b.bit._30, b.bit._31);
    printf("%i\t %i\t %i\t %i\t %i\t %i\t %i\t %i\t\n", b.nibble._0, b.nibble._1, b.nibble._2, b.nibble._3, b.nibble._4, b.nibble._5, b.nibble._6, b.nibble._7);
    printf("0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t\n", b.nibble._0, b.nibble._1, b.nibble._2, b.nibble._3, b.nibble._4, b.nibble._5, b.nibble._6, b.nibble._7);
    printf("\t %i\t\t %i\t\t %i\t\t %i\t\t\n", b.byte._0, b.byte._1, b.byte._2, b.byte._3);
    printf("\t 0x%0X\t\t 0x%0X\t\t 0x%0X\t\t 0x%0X\n", b.byte._0, b.byte._1, b.byte._2, b.byte._3);
    printf("\t\t\t %i\t\t\t\t %i\n", b.word._0, b.word._1);
    printf("\t\t\t 0x%03X\t\t\t\t 0x%0X\n", b.word._0, b.word._1);
    printf("\t\t\t\t\t\t\t %u\n", b.doubleWord);
    printf("\t\t\t\t\t\t\t 0x%X\n", b.doubleWord);
    printf("----------------------------------------------------------------------------\n");
    printf("%u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t %u%u%u%u\t\n", a.bit._0, a.bit._1, a.bit._2, a.bit._3, a.bit._4, a.bit._5, a.bit._6, a.bit._7, a.bit._8, a.bit._9, a.bit._10, a.bit._11, a.bit._12, a.bit._13, a.bit._14, a.bit._15, a.bit._16, a.bit._17, a.bit._18, a.bit._19, a.bit._20, a.bit._21, a.bit._22, a.bit._23, a.bit._24, a.bit._25, a.bit._26, a.bit._27, a.bit._28, a.bit._29, a.bit._30, a.bit._31);
    printf("%i\t %i\t %i\t %i\t %i\t %i\t %i\t %i\t\n", a.nibble._0, a.nibble._1, a.nibble._2, a.nibble._3, a.nibble._4, a.nibble._5, a.nibble._6, a.nibble._7);
    printf("0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t 0x%01X\t\n", a.nibble._0, a.nibble._1, a.nibble._2, a.nibble._3, a.nibble._4, a.nibble._5, a.nibble._6, a.nibble._7);
    printf("\t %i\t\t %i\t\t %i\t\t %i\t\t\n", a.byte._0, a.byte._1, a.byte._2, a.byte._3);
    printf("\t 0x%0X\t\t 0x%0X\t\t 0x%0X\t\t 0x%0X\n", a.byte._0, a.byte._1, a.byte._2, a.byte._3);
    printf("\t\t\t %i\t\t\t\t %i\n", a.word._0, a.word._1);
    printf("\t\t\t 0x%03X\t\t\t\t 0x%0X\n", a.word._0, a.word._1);
    printf("\t\t\t\t\t\t\t %u\n", a.doubleWord);
    printf("\t\t\t\t\t\t\t 0x%X\n", a.doubleWord);


    printf("%li\n ", teste);

}
