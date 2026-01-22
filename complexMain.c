// a班 complexMain.c

// 複素数構造体を使う時には次の行を活かす
#include "complex.h"
#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* このプログラムはブランチを分けてから個々に作成してください */

// このファイルは 3323 武中優成 が記述

int main() {
    complex a1, a2, a3, b1, b2;
    complex t3a, t3b, t3c, t3d, t3e;
    
    
    //1
    a1 = makeComp(5.0, 5.0);
    a2 = makeComp(25.0 * sqrt(3), -25.0);
    a3 = makeComp(0.0, 10.0);

    printf("1(a) a1 = ");
    printCompRT(a1);

    printf("\n1(b) a2 = ");
    printCompRT(a2);

    printf("\n1(c) a3 = ");
    printCompRT(a3);
    
    //2
    b1 = makeComp(
        5 * cos(M_PI / 6),
        5 * sin(M_PI / 6)
    );

    b2 = makeComp(
        100 * cos(M_PI),
        100 * sin(M_PI)
    );

    printf("\n2(a) b1 = ");
    printComp(b1);

    printf("\n2(b) b2 = ");
    printComp(b2);

    //3
    t3a = addComp(a1, a2);
    t3b = subComp(a1, b1);
    t3c = mulComp(a2, b1);
    t3d = divComp(makeComp(1.0, 0.0), a1);
    t3e = divComp(mulComp(a1, b2), a3);
    
    printf("\n3(a) a1 + a2 = ");
    printComp(t3a);

    printf("\n3(b) a1 - b1 = ");
    printComp(t3b);

    printf("\n3(c) a2 * b1 = ");
    printComp(t3c);

    printf("\n3(d) 1 / a1 = ");
    printComp(t3d);

    printf("\n3(e) a3 / (a1 * b2) = ");
    printComp(t3e);

    //4
    complex zr, zl, zc, z4;

    double r4 = 5.0;
    double l4 = 0.02;
    double c4 = 0.000125;
    double w4 = 1000.0;

    zr = makeComp(r4, 0.0);
    zl = makeComp(0.0, w4 * l4);
    zc = makeComp(0.0, -1.0 / (w4 * c4));

    z4 = addComp(addComp(zr, zl), zc);

    printf("\n4. Z = ");
    printComp(z4);
    
    //5
    complex yr, yl, yc, y, z5;

    double r5 = 5.0;
    double l5 = 0.01;
    double c5 = 0.0003;
    double w5 = 1000.0;

    yr = makeComp(1.0 / r5, 0.0);
    yl = makeComp(0.0, -1.0 / (w5 * l5));
    yc = makeComp(0.0, w5 * c5);

    y = addComp(addComp(yr, yl), yc);
    //z5 = divComp(makeComp(1.0, 0.0), y);
    z5 = invComp(y);

    printf("\n5. Z = ");
    printCompRT(z5);

    /** 4, 5 **/
    //r = makeComp(......);
    //zl = ......;
    // 中略
    //z = // addCompなどを使って解く
    //以下続く　*/
    return 0;
}

