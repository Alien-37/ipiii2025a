// a班 graphMain.c
#include <stdio.h>
#include <math.h>
#include "complex.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* このプログラムはブランチを分けてから個々に作成してください */

// このファイルは 3323 武中優成 が記述

#include <stdio.h>
#include <math.h>
#include "complex.h"

#define N 100

#define R1 (10.0)
#define R2 (20.0)
#define C  (0.0001)
#define L  (0.05)
#define W  (1000.0)

int main() {
    complex v, z, i;
    complex z1,z2,y1,y2,y;
    double t, vt, it, period;

    // 電源電圧 V̇
    v = makeComp(
        50 * cos(M_PI / 4),
        50 * sin(M_PI / 4)
    );

    //インピーダンス
    z1 = makeComp(R1, W*L);
    z2 = makeComp(R2, -1.0/(W*C));

    y1 = invComp(z1);
    y2 = invComp(z2);

    y  = addComp(y1,y2);
    z  = invComp(y);

    
    // 電流 İ
    i = divComp(v, z);

    //周期
    period = 2 * M_PI / W;

    //時間波形出力
    for (t = 0; t < period; t += period / N) {
        vt = sqrt(2) * getR(v) * sin(W * t + getTheta(v));
        it = sqrt(2) * getR(i) * sin(W * t + getTheta(i));

        printf("%f\t%f\t%f\n", t, vt, it);
    }

    return 0;
}
