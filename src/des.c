#include "des.h"
#include "printf_block.h"

block32 permutationP(block32 in)
{
    block32 out;
    out.bit._31 = in.bit._24;
    out.bit._30 = in.bit._3;
    out.bit._29 = in.bit._10;
    out.bit._28 = in.bit._21;
    out.bit._27 = in.bit._5;
    out.bit._26 = in.bit._29;
    out.bit._25 = in.bit._12;
    out.bit._24 = in.bit._18;
    out.bit._23 = in.bit._8;
    out.bit._22 = in.bit._2;
    out.bit._21 = in.bit._26;
    out.bit._20 = in.bit._31;
    out.bit._19 = in.bit._13;
    out.bit._18 = in.bit._23;
    out.bit._17 = in.bit._7;
    out.bit._16 = in.bit._1;
    out.bit._15 = in.bit._9;
    out.bit._14 = in.bit._30;
    out.bit._13 = in.bit._17;
    out.bit._12 = in.bit._4;
    out.bit._11 = in.bit._25;
    out.bit._10 = in.bit._22;
    out.bit._9 = in.bit._14;
    out.bit._8 = in.bit._0;
    out.bit._7 = in.bit._16;
    out.bit._6 = in.bit._27;
    out.bit._5 = in.bit._11;
    out.bit._4 = in.bit._28;
    out.bit._3 = in.bit._20;
    out.bit._2 = in.bit._19;
    out.bit._1 = in.bit._6;
    out.bit._0 = in.bit._15;
    return out;
}

int S1[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
            0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
            4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
            15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

int boxS1(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._0;
    col.bit._28 = box.bit._1;
    col.bit._29 = box.bit._2;
    col.bit._30 = box.bit._3;
    col.bit._31 = box.bit._4;
    row.bit._31 = box.bit._5;

    return S1[(row.doubleWord * 16) + col.doubleWord];
}

int S2[] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
            3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
            0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
            13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

int boxS2(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._6;
    col.bit._28 = box.bit._7;
    col.bit._29 = box.bit._8;
    col.bit._30 = box.bit._9;
    col.bit._31 = box.bit._10;
    row.bit._31 = box.bit._11;

    return S2[(row.doubleWord * 16) + col.doubleWord];
}

int S3[] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
            13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
            13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
            1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

int boxS3(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._12;
    col.bit._28 = box.bit._13;
    col.bit._29 = box.bit._14;
    col.bit._30 = box.bit._15;
    col.bit._31 = box.bit._16;
    row.bit._31 = box.bit._17;

    return S3[(row.doubleWord * 16) + col.doubleWord];
}

int S4[] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
            13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
            10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
            3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

int boxS4(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._18;
    col.bit._28 = box.bit._19;
    col.bit._29 = box.bit._20;
    col.bit._30 = box.bit._21;
    col.bit._31 = box.bit._22;
    row.bit._31 = box.bit._23;

    return S4[(row.doubleWord * 16) + col.doubleWord];
}

int S5[] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
            14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
            4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
            11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

int boxS5(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._24;
    col.bit._28 = box.bit._25;
    col.bit._29 = box.bit._26;
    col.bit._30 = box.bit._27;
    col.bit._31 = box.bit._28;
    row.bit._31 = box.bit._29;

    return S5[(row.doubleWord * 16) + col.doubleWord];
}

int S6[] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
            10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
            9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
            4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

int boxS6(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._30;
    col.bit._28 = box.bit._31;
    col.bit._29 = box.bit._32;
    col.bit._30 = box.bit._33;
    col.bit._31 = box.bit._34;
    row.bit._31 = box.bit._35;

    return S6[(row.doubleWord * 16) + col.doubleWord];
}

int S7[] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
            13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
            1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
            6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

int boxS7(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._36;
    col.bit._28 = box.bit._37;
    col.bit._29 = box.bit._38;
    col.bit._30 = box.bit._39;
    col.bit._31 = box.bit._40;
    row.bit._31 = box.bit._41;

    return S7[(row.doubleWord * 16) + col.doubleWord];
}

int S8[] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
            1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
            7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
            2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

int boxS8(block64 box)
{
    block32 row, col;
    row.doubleWord = 0x0;
    col.doubleWord = 0x0;

    row.bit._30 = box.bit._42;
    col.bit._28 = box.bit._43;
    col.bit._29 = box.bit._44;
    col.bit._30 = box.bit._45;
    col.bit._31 = box.bit._46;
    row.bit._31 = box.bit._47;

    return S8[(row.doubleWord * 16) + col.doubleWord];
}

//Step 1: Create 16 subkeys, each of which is 48-bits long

void key_permutation(block64 key, block64 *key_permutated_final)
{
    // printf_block32 pb32 = init_printf_block32();

    block64 key_permutated[16];
    // block64 key_permutated_final[16];

    key_permutated[0].quadword = 0x0;

    key_permutated[0].bit._55 = key.bit._3;
    key_permutated[0].bit._54 = key.bit._11;
    key_permutated[0].bit._53 = key.bit._19;
    key_permutated[0].bit._52 = key.bit._27;
    key_permutated[0].bit._51 = key.bit._4;
    key_permutated[0].bit._50 = key.bit._12;
    key_permutated[0].bit._49 = key.bit._20;
    key_permutated[0].bit._48 = key.bit._28;
    key_permutated[0].bit._47 = key.bit._36;
    key_permutated[0].bit._46 = key.bit._44;
    key_permutated[0].bit._45 = key.bit._52;
    key_permutated[0].bit._44 = key.bit._60;
    key_permutated[0].bit._43 = key.bit._5;
    key_permutated[0].bit._42 = key.bit._13;
    key_permutated[0].bit._41 = key.bit._21;
    key_permutated[0].bit._40 = key.bit._29;
    key_permutated[0].bit._39 = key.bit._37;
    key_permutated[0].bit._38 = key.bit._45;
    key_permutated[0].bit._37 = key.bit._53;
    key_permutated[0].bit._36 = key.bit._61;
    key_permutated[0].bit._35 = key.bit._6;
    key_permutated[0].bit._34 = key.bit._14;
    key_permutated[0].bit._33 = key.bit._22;
    key_permutated[0].bit._32 = key.bit._30;
    key_permutated[0].bit._31 = key.bit._38;
    key_permutated[0].bit._30 = key.bit._46;
    key_permutated[0].bit._29 = key.bit._54;
    key_permutated[0].bit._28 = key.bit._62;
    key_permutated[0].bit._27 = key.bit._35;
    key_permutated[0].bit._26 = key.bit._43;
    key_permutated[0].bit._25 = key.bit._51;
    key_permutated[0].bit._24 = key.bit._59;
    key_permutated[0].bit._23 = key.bit._2;
    key_permutated[0].bit._22 = key.bit._10;
    key_permutated[0].bit._21 = key.bit._18;
    key_permutated[0].bit._20 = key.bit._26;
    key_permutated[0].bit._19 = key.bit._34;
    key_permutated[0].bit._18 = key.bit._42;
    key_permutated[0].bit._17 = key.bit._50;
    key_permutated[0].bit._16 = key.bit._58;
    key_permutated[0].bit._15 = key.bit._1;
    key_permutated[0].bit._14 = key.bit._9;
    key_permutated[0].bit._13 = key.bit._17;
    key_permutated[0].bit._12 = key.bit._25;
    key_permutated[0].bit._11 = key.bit._33;
    key_permutated[0].bit._10 = key.bit._41;
    key_permutated[0].bit._9 = key.bit._49;
    key_permutated[0].bit._8 = key.bit._57;
    key_permutated[0].bit._7 = key.bit._0;
    key_permutated[0].bit._6 = key.bit._8;
    key_permutated[0].bit._5 = key.bit._16;
    key_permutated[0].bit._4 = key.bit._24;
    key_permutated[0].bit._3 = key.bit._32;
    key_permutated[0].bit._2 = key.bit._40;
    key_permutated[0].bit._1 = key.bit._48;
    key_permutated[0].bit._0 = key.bit._56;

    // pb32.bits(key_permutated[0].doubleWord._0);
    // pb32.bits(key_permutated[0].doubleWord._1);

    for (int i = 0; i < 17; i++)
    {
        // printf("%d \n", i);
        if (i != 0)
        {
            if (i == 1 || i == 2 || i == 9 || i == 16)
            {
                key_permutated[i].quadword = key_permutated[i - 1].quadword << 1;
                key_permutated[i].bit._27 = key_permutated[i - 1].bit._0;
                key_permutated[i].bit._55 = key_permutated[i - 1].bit._28;
            }
            else
            {
                key_permutated[i].quadword = key_permutated[i - 1].quadword << 2;
                key_permutated[i].bit._27 = key_permutated[i - 1].bit._1;
                key_permutated[i].bit._26 = key_permutated[i - 1].bit._0;
                key_permutated[i].bit._55 = key_permutated[i - 1].bit._29;
                key_permutated[i].bit._54 = key_permutated[i - 1].bit._28;
            }
        }

        key_permutated_final[i].bit._47 = key_permutated[i].bit._31;
        key_permutated_final[i].bit._46 = key_permutated[i].bit._28;
        key_permutated_final[i].bit._45 = key_permutated[i].bit._35;
        key_permutated_final[i].bit._44 = key_permutated[i].bit._49;
        key_permutated_final[i].bit._43 = key_permutated[i].bit._41;
        key_permutated_final[i].bit._42 = key_permutated[i].bit._45;
        key_permutated_final[i].bit._41 = key_permutated[i].bit._52;
        key_permutated_final[i].bit._40 = key_permutated[i].bit._33;
        key_permutated_final[i].bit._39 = key_permutated[i].bit._55;
        key_permutated_final[i].bit._38 = key_permutated[i].bit._38;
        key_permutated_final[i].bit._37 = key_permutated[i].bit._48;
        key_permutated_final[i].bit._36 = key_permutated[i].bit._43;
        key_permutated_final[i].bit._35 = key_permutated[i].bit._47;
        key_permutated_final[i].bit._34 = key_permutated[i].bit._32;
        key_permutated_final[i].bit._33 = key_permutated[i].bit._44;
        key_permutated_final[i].bit._32 = key_permutated[i].bit._50;
        key_permutated_final[i].bit._31 = key_permutated[i].bit._39;
        key_permutated_final[i].bit._30 = key_permutated[i].bit._29;
        key_permutated_final[i].bit._29 = key_permutated[i].bit._54;
        key_permutated_final[i].bit._28 = key_permutated[i].bit._46;
        key_permutated_final[i].bit._27 = key_permutated[i].bit._36;
        key_permutated_final[i].bit._26 = key_permutated[i].bit._30;
        key_permutated_final[i].bit._25 = key_permutated[i].bit._51;
        key_permutated_final[i].bit._24 = key_permutated[i].bit._40;
        key_permutated_final[i].bit._23 = key_permutated[i].bit._1;
        key_permutated_final[i].bit._22 = key_permutated[i].bit._12;
        key_permutated_final[i].bit._21 = key_permutated[i].bit._19;
        key_permutated_final[i].bit._20 = key_permutated[i].bit._26;
        key_permutated_final[i].bit._19 = key_permutated[i].bit._6;
        key_permutated_final[i].bit._18 = key_permutated[i].bit._15;
        key_permutated_final[i].bit._17 = key_permutated[i].bit._7;
        key_permutated_final[i].bit._16 = key_permutated[i].bit._25;
        key_permutated_final[i].bit._15 = key_permutated[i].bit._3;
        key_permutated_final[i].bit._14 = key_permutated[i].bit._11;
        key_permutated_final[i].bit._13 = key_permutated[i].bit._18;
        key_permutated_final[i].bit._12 = key_permutated[i].bit._22;
        key_permutated_final[i].bit._11 = key_permutated[i].bit._9;
        key_permutated_final[i].bit._10 = key_permutated[i].bit._20;
        key_permutated_final[i].bit._9 = key_permutated[i].bit._5;
        key_permutated_final[i].bit._8 = key_permutated[i].bit._14;
        key_permutated_final[i].bit._7 = key_permutated[i].bit._27;
        key_permutated_final[i].bit._6 = key_permutated[i].bit._2;
        key_permutated_final[i].bit._5 = key_permutated[i].bit._4;
        key_permutated_final[i].bit._4 = key_permutated[i].bit._0;
        key_permutated_final[i].bit._3 = key_permutated[i].bit._23;
        key_permutated_final[i].bit._2 = key_permutated[i].bit._10;
        key_permutated_final[i].bit._1 = key_permutated[i].bit._16;
        key_permutated_final[i].bit._0 = key_permutated[i].bit._13;
        // pb32.bits(key_permutated_final[i].doubleWord._0);
        // pb32.bits(key_permutated_final[i].doubleWord._1);
    }
}

block64 ip_permutation(block64 in)
{
    block64 out;
    out.bit._63 = in.bit._6;
    out.bit._62 = in.bit._14;
    out.bit._61 = in.bit._22;
    out.bit._60 = in.bit._30;
    out.bit._59 = in.bit._38;
    out.bit._58 = in.bit._46;
    out.bit._57 = in.bit._54;
    out.bit._56 = in.bit._62;
    out.bit._55 = in.bit._4;
    out.bit._54 = in.bit._12;
    out.bit._53 = in.bit._20;
    out.bit._52 = in.bit._28;
    out.bit._51 = in.bit._36;
    out.bit._50 = in.bit._44;
    out.bit._49 = in.bit._52;
    out.bit._48 = in.bit._61;
    out.bit._47 = in.bit._2;
    out.bit._46 = in.bit._10;
    out.bit._45 = in.bit._18;
    out.bit._44 = in.bit._26;
    out.bit._43 = in.bit._34;
    out.bit._42 = in.bit._42;
    out.bit._41 = in.bit._50;
    out.bit._40 = in.bit._58;
    out.bit._39 = in.bit._0;
    out.bit._38 = in.bit._8;
    out.bit._37 = in.bit._16;
    out.bit._36 = in.bit._24;
    out.bit._35 = in.bit._32;
    out.bit._34 = in.bit._40;
    out.bit._33 = in.bit._48;
    out.bit._32 = in.bit._56;
    out.bit._31 = in.bit._7;
    out.bit._30 = in.bit._15;
    out.bit._29 = in.bit._23;
    out.bit._28 = in.bit._31;
    out.bit._27 = in.bit._39;
    out.bit._26 = in.bit._47;
    out.bit._25 = in.bit._55;
    out.bit._24 = in.bit._63;
    out.bit._23 = in.bit._5;
    out.bit._22 = in.bit._13;
    out.bit._21 = in.bit._21;
    out.bit._20 = in.bit._29;
    out.bit._19 = in.bit._37;
    out.bit._18 = in.bit._45;
    out.bit._17 = in.bit._53;
    out.bit._16 = in.bit._61;
    out.bit._15 = in.bit._3;
    out.bit._14 = in.bit._11;
    out.bit._13 = in.bit._19;
    out.bit._12 = in.bit._27;
    out.bit._11 = in.bit._35;
    out.bit._10 = in.bit._43;
    out.bit._9 = in.bit._51;
    out.bit._8 = in.bit._59;
    out.bit._7 = in.bit._1;
    out.bit._6 = in.bit._9;
    out.bit._5 = in.bit._17;
    out.bit._4 = in.bit._25;
    out.bit._3 = in.bit._33;
    out.bit._2 = in.bit._41;
    out.bit._1 = in.bit._49;
    out.bit._0 = in.bit._57;
    return out;
}

block64 ip_permutation_after(block64 in)
{
    block64 out;
    out.bit._63 = in.bit._24;
    out.bit._62 = in.bit._56;
    out.bit._61 = in.bit._16;
    out.bit._60 = in.bit._48;
    out.bit._59 = in.bit._8;
    out.bit._58 = in.bit._40;
    out.bit._57 = in.bit._0;
    out.bit._56 = in.bit._32;
    out.bit._55 = in.bit._25;
    out.bit._54 = in.bit._57;
    out.bit._53 = in.bit._17;
    out.bit._52 = in.bit._49;
    out.bit._51 = in.bit._9;
    out.bit._50 = in.bit._41;
    out.bit._49 = in.bit._1;
    out.bit._48 = in.bit._33;
    out.bit._47 = in.bit._26;
    out.bit._46 = in.bit._58;
    out.bit._45 = in.bit._18;
    out.bit._44 = in.bit._50;
    out.bit._43 = in.bit._10;
    out.bit._42 = in.bit._42;
    out.bit._41 = in.bit._2;
    out.bit._40 = in.bit._34;
    out.bit._39 = in.bit._27;
    out.bit._38 = in.bit._59;
    out.bit._37 = in.bit._19;
    out.bit._36 = in.bit._51;
    out.bit._35 = in.bit._11;
    out.bit._34 = in.bit._43;
    out.bit._33 = in.bit._3;
    out.bit._32 = in.bit._35;
    out.bit._31 = in.bit._28;
    out.bit._30 = in.bit._60;
    out.bit._29 = in.bit._20;
    out.bit._28 = in.bit._52;
    out.bit._27 = in.bit._12;
    out.bit._26 = in.bit._44;
    out.bit._25 = in.bit._4;
    out.bit._24 = in.bit._36;
    out.bit._23 = in.bit._29;
    out.bit._22 = in.bit._61;
    out.bit._21 = in.bit._21;
    out.bit._20 = in.bit._53;
    out.bit._19 = in.bit._13;
    out.bit._18 = in.bit._45;
    out.bit._17 = in.bit._5;
    out.bit._16 = in.bit._37;
    out.bit._15 = in.bit._30;
    out.bit._14 = in.bit._62;
    out.bit._13 = in.bit._22;
    out.bit._12 = in.bit._54;
    out.bit._11 = in.bit._14;
    out.bit._10 = in.bit._46;
    out.bit._9 = in.bit._6;
    out.bit._8 = in.bit._38;
    out.bit._7 = in.bit._31;
    out.bit._6 = in.bit._63;
    out.bit._5 = in.bit._23;
    out.bit._4 = in.bit._55;
    out.bit._3 = in.bit._15;
    out.bit._2 = in.bit._47;
    out.bit._1 = in.bit._7;
    out.bit._0 = in.bit._39;
    return out;
}

block64 e_bit_selection(block32 in)
{
    block64 out;
    out.bit._47 = in.bit._0;
    out.bit._46 = in.bit._31;
    out.bit._45 = in.bit._30;
    out.bit._44 = in.bit._29;
    out.bit._43 = in.bit._28;
    out.bit._42 = in.bit._27;
    out.bit._41 = in.bit._28;
    out.bit._40 = in.bit._27;
    out.bit._39 = in.bit._26;
    out.bit._38 = in.bit._25;
    out.bit._37 = in.bit._24;
    out.bit._36 = in.bit._23;
    out.bit._35 = in.bit._24;
    out.bit._34 = in.bit._23;
    out.bit._33 = in.bit._22;
    out.bit._32 = in.bit._21;
    out.bit._31 = in.bit._20;
    out.bit._30 = in.bit._19;
    out.bit._29 = in.bit._20;
    out.bit._28 = in.bit._19;
    out.bit._27 = in.bit._18;
    out.bit._26 = in.bit._17;
    out.bit._25 = in.bit._16;
    out.bit._24 = in.bit._15;
    out.bit._23 = in.bit._16;
    out.bit._22 = in.bit._15;
    out.bit._21 = in.bit._14;
    out.bit._20 = in.bit._13;
    out.bit._19 = in.bit._12;
    out.bit._18 = in.bit._11;
    out.bit._17 = in.bit._12;
    out.bit._16 = in.bit._11;
    out.bit._15 = in.bit._10;
    out.bit._14 = in.bit._9;
    out.bit._13 = in.bit._8;
    out.bit._12 = in.bit._7;
    out.bit._11 = in.bit._8;
    out.bit._10 = in.bit._7;
    out.bit._9 = in.bit._6;
    out.bit._8 = in.bit._5;
    out.bit._7 = in.bit._4;
    out.bit._6 = in.bit._3;
    out.bit._5 = in.bit._4;
    out.bit._4 = in.bit._3;
    out.bit._3 = in.bit._2;
    out.bit._2 = in.bit._1;
    out.bit._1 = in.bit._0;
    out.bit._0 = in.bit._31;
    return out;
}

//Create subkeys end

block64 ecryption()
{
    printf_block32 pb32 = init_printf_block32();

    block64 key;
    block64 subkeys[16];

    //Senha
    key.quadword = 0x133457799bbcdff1;
    key_permutation(key, subkeys);
    //subkeys[i] 48 bits 0 - 47

    //crypt 64 bits
    block64 in, ip;
    //Mensagem
    in.quadword = 0x123456789ABCDEF;

    pb32.bits(in.doubleWord._0);
    pb32.bits(in.doubleWord._1);

    //ip = ip_permutation(in);
    ip = in;

    block32 l[16];
    block32 r[16];

    l[0] = ip.doubleWord._0;
    r[0] = ip.doubleWord._1;
    // pb32.bits(l);
    // pb32.bits(r);

    //n - 16
    block64 result_e;
    block32 afterBox;
    for (int i = 0; i < 16; i++)
    {
        result_e.quadword = 0x0;
        result_e = e_bit_selection(r[i]);

        block64 keyXORebit;
        keyXORebit.quadword = result_e.quadword ^ subkeys[i + 1].quadword;

    

        afterBox.nibble._7 = boxS8(keyXORebit);
        afterBox.nibble._6 = boxS7(keyXORebit);
        afterBox.nibble._5 = boxS6(keyXORebit);
        afterBox.nibble._4 = boxS5(keyXORebit);
        afterBox.nibble._3 = boxS4(keyXORebit);
        afterBox.nibble._2 = boxS3(keyXORebit);
        afterBox.nibble._1 = boxS2(keyXORebit);
        afterBox.nibble._0 = boxS1(keyXORebit);

        afterBox = permutationP(afterBox);
        // pb32.bits(l[i+1]);
        l[i + 1].doubleWord = r[i].doubleWord;
        r[i + 1].doubleWord = l[i].doubleWord ^ afterBox.doubleWord;
        // printf("%d - ", i);
    }
    block64 afterInteration;
    afterInteration.doubleWord._0 = r[16];
    afterInteration.doubleWord._1 = l[16];
    //afterInteration = ip_permutation_after(afterInteration);

    // pb32.bits(afterInteration.doubleWord._0);
    // pb32.bits(afterInteration.doubleWord._1);

    return afterInteration;
}

block64 decryption(block64 encrypted)
{
    printf_block32 pb32 = init_printf_block32();
    block64 key;
    block64 subkeys[16];

    //Senha
    key.quadword = 0x133457799bbcdff1;
    key_permutation(key, subkeys);

    block32 l[16];
    block32 r[16];


    l[0] = encrypted.doubleWord._0;
    r[0] = encrypted.doubleWord._1;

    block64 result_e;
    block32 afterBox;
    int count = 16;
    for (int i = 0; i < 16; i++)
    {
        result_e.quadword = 0x0;
        result_e = e_bit_selection(r[i]);

        block64 keyXORebit;
        keyXORebit.quadword = result_e.quadword ^ subkeys[count - i].quadword;

        // pb32.bits(keyXORebit.doubleWord._0);
        // pb32.bits(keyXORebit.doubleWord._1);

        afterBox.nibble._7 = boxS8(keyXORebit);
        afterBox.nibble._6 = boxS7(keyXORebit);
        afterBox.nibble._5 = boxS6(keyXORebit);
        afterBox.nibble._4 = boxS5(keyXORebit);
        afterBox.nibble._3 = boxS4(keyXORebit);
        afterBox.nibble._2 = boxS3(keyXORebit);
        afterBox.nibble._1 = boxS2(keyXORebit);
        afterBox.nibble._0 = boxS1(keyXORebit);

        afterBox = permutationP(afterBox);
        // pb32.bits(l[i+1]);
        l[i + 1].doubleWord = r[i].doubleWord;
        r[i + 1].doubleWord = l[i].doubleWord ^ afterBox.doubleWord;
        // printf("%d - ", i);
    }
    block64 afterInteration;
    afterInteration.doubleWord._0 = r[16];
    afterInteration.doubleWord._1 = l[16];
    //afterInteration = ip_permutation_after(afterInteration);
    //afterInteration = ip_permutation(afterInteration);

    pb32.bits(afterInteration.doubleWord._0);
    pb32.bits(afterInteration.doubleWord._1);
}

int main()
{
    printf_block32 pb32 = init_printf_block32();
    block64 encrypted = ecryption();
    pb32.bits(encrypted.doubleWord._0);
    pb32.bits(encrypted.doubleWord._1);
    decryption(encrypted);
}
