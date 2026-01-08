// ○班 complexMain.c

// 複素数構造体を使う時には次の行を活かす


/* このプログラムはブランチを分けてから個々に作成してください */


// このファイルは 3342 宮坂 卓真 が記述
#include <stdio.h>
#include <math.h>
#include "complex.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    complex a1, a2, a3,b1, b2;
    complex t3a, t3b, t3c, t3d, t3e;
    double r4 = 5.0, l4 = 0.02 , c4 = 0.000125, w4 = 1000;
    double r5 = 5.0, l5 = 0.01, c5 = 0.000300, w5 = 1000;
    complex z4, z5;

    a1 = makeComp(5.0,5.0);
    a2 = makeComp(25.0*sqrt(3),-25);
    a3 = makeComp(0.0 , 10.0);
    //以下続く
    printf("1(a) a1 = ");
    printCompRT(a1);
    printf("\n1(b) a2 = ");
    printCompRT(a2);
    printf("\n1(c) a3 = ");
    printCompRT(a3);
    
    b1 = makeCompRT(0.2,M_PI/6);
    b2 = makeCompRT(100,M_PI);

    printf("\n2(a) b1 = ");
    printComp(b1);
    printf("\n2(b) b2 = ");
    printComp(b2);

    t3a = addComp(a1,a2);
    t3b = subComp(a1,a2);
    t3c = mulComp(a2,b1);
    t3d = invComp(a1);
    t3e = divComp(mulComp(a1,b2),a3);

    printf("\n3(a) t3a =");
    printComp(t3a);
    printf("\n3(b) t3b =");
    printComp(t3b);
    printf("\n3(c) t3c =");
    printComp(t3c);
    printf("\n3(d) t3d =");
    printComp(t3d);
    printf("\n3(e) t3e =");
    printComp(t3e);
    

    //4  
    complex Zr,Zl,Zc;
    Zr = makeComp(5,0);
    Zl = makeComp(0,w4*l4);
    Zc = makeComp(0,-1/(w4*c4));

    printf("\n4(r) Zr= ");
    printComp(Zr);
    printf("\n4(l) Zl= ");
    printComp(Zl);
    printf("\n4(c) Zc= ");
    printComp(Zc);

    z4 = addComp(Zr,addComp(Zl,Zc));
    printf("\n4(z4) Z4= ");
    printComp(z4);// addCompなどを使って解く
    
    //5
    complex Zr5,Zl5,Zc5,ZZ5;
    Zr5 = makeComp(1/r5,0);
    Zl5 = makeComp(0,-1/(w5*l5));
    Zc5 = makeComp(0,(w5*c5));

    printf("\n5(r) Zr5= ");
    printCompRT(Zr5);
    printf("\n5(l) Zl5= ");
    printCompRT(Zl5);
    printf("\n5(c) Zc5= ");
    printCompRT(Zc5);

    ZZ5= addComp(addComp(Zr5,Zl5),Zc5);
    z5 = divComp(makeComp(1.0,0.0),ZZ5);

    printf("\n5(z5) Z5= ");
    printCompRT(z5);
    //以下続く*/
    return 0;

    
}


