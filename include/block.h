
typedef union {
    struct
    {
        unsigned _31 : 1;
        unsigned _30 : 1;
        unsigned _29 : 1;
        unsigned _28 : 1;
        unsigned _27 : 1;
        unsigned _26 : 1;
        unsigned _25 : 1;
        unsigned _24 : 1;
        unsigned _23 : 1;
        unsigned _22 : 1;
        unsigned _21 : 1;
        unsigned _20 : 1;
        unsigned _19 : 1;
        unsigned _18 : 1;
        unsigned _17 : 1;
        unsigned _16 : 1;
        unsigned _15 : 1;
        unsigned _14 : 1;
        unsigned _13 : 1;
        unsigned _12 : 1;
        unsigned _11 : 1;
        unsigned _10 : 1;
        unsigned _9 : 1;
        unsigned _8 : 1;
        unsigned _7 : 1;
        unsigned _6 : 1;
        unsigned _5 : 1;
        unsigned _4 : 1;
        unsigned _3 : 1;
        unsigned _2 : 1;
        unsigned _1 : 1;
        unsigned _0 : 1;
    } bit;
    struct
    {
        unsigned _7 : 4;
        unsigned _6 : 4;
        unsigned _5 : 4;
        unsigned _4 : 4;
        unsigned _3 : 4;
        unsigned _2 : 4;
        unsigned _1 : 4;
        unsigned _0 : 4;
    } nibble;

    struct
    {
        unsigned _3 : 8;
        unsigned _2 : 8;
        unsigned _1 : 8;
        unsigned _0 : 8;
    } byte;

    struct
    {
        unsigned _1 : 16;
        unsigned _0 : 16;
    } word;
    unsigned doubleWord : 32;
} block;
