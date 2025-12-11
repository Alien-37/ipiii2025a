// X班 complex.c

#include "complex.h"

#include <math.h>
#include <stdio.h>

// テスト作成者は雛形までを作成し、コンパイルができるまでを責任とします。
// コンパイルができたところで、コミットしてください。
//奇数を武中、偶数を俺でやる。

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 3323 武中優成 記述部(雛形まで。この範囲以外には追加しない)
complex makeComp(double real, double image) {
    complex ans;
        ans.real = real;
        ans.image = image;
    

    return ans;   // 作った複素数を返す
}


//↑↑↑↑ ここまでを 3323 武中優成 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 3342 宮坂卓真 記述部(雛形まで。この範囲以外には追加しない)
complex makeCompRT(double r, double theta) {
    return makeComp(
        r * cos(theta),
        r * sin(theta)
    );
}

complex subComp(complex a, complex b){
    complex ans;

}


//↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)



// ここから下には何も追記しないでください。