// X班 graphMain.c
#include <stdio.h>
#include <math.h>
#include "complex.h"
/* このプログラムはブランチを分けてから個々に作成してください */

// このファイルは 33aa AAAAA が記述


#include <stdio.h>
#include <math.h>
#include "complex.h"
#define  N  100
#define R1 1
#define R2 20
#define L 0.01
#define C 0.001
#define W 500
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// define の後ろに式を書く時には絶対に () でくくること。展開部で意味が変わることがあります

int main() {
    complex v, z, i ,zr1,zr2,zc,zl,z1,z2;
    double t, vt, it, period;

    
    //v, z, i の計算 (z が計算できればvとzからiが計算できる)
    zr1 = makeComp(R1,0);
    zr2 = makeComp(R2,0);
    zl = makeComp(0.0, W * L);          // jωL
    zc = makeComp(0.0, -1.0 / (W * C)); // -j/(ωC)
    printf("\n(zr1) zr1 = ");
    printComp(zr1);
    printf("\n(zr2) zr2 = ");
    printComp(zr2);
    printf("\n(zc) zc = ");
    printComp(zc);
    printf("\n(zl) zl = ");
    printComp(zl);
    z1 = divComp(makeComp(1.0,0.0),addComp(zr1,zl)); //アドミタンス
    z2 = divComp(makeComp(1.0,0.0),addComp(zr2,zc)); //アドミタンス
    z = addComp(z1,z2); //アドミタンス
    printf("\n(z) z = ");
    printComp(z);
    period = 2 * M_PI / W;  /* 周期 */
    v = makeComp(1.0, 0.0);   // 電圧（フェーザ）
    i = mulComp(v, z);       // 電流（フェーザ）
    printf("\nphase(v) = %e rad\n", getTheta(v));
    printf("phase(i) = %e rad\n", getTheta(i));
    printf("phase diff = %e rad\n", getTheta(i) - getTheta(v));

    for (t = 0; t < period; t += period / N) {
        vt = sqrt(2.0) * getR(v) * sin(W * t + getTheta(v));
        it = sqrt(2.0) * getR(i) * sin(W * t + getTheta(i));
        printf("%f\t%f\t%f\n", t, vt, it);
    } 

    return 0;
}
