// X班 complex.c

#include "complex.h"

#include <math.h>
#include <stdio.h>

// テスト作成者は雛形までを作成し、コンパイルができるまでを責任とします。
// コンパイルができたところで、コミットしてください。
//奇数を武中、偶数を俺でやる。

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 3323 武中優成 記述部(雛形まで。この範囲以外には追加しない)

complex makeComp(double real, double image) {   //1
    complex ans;
        ans.real = real;
        ans.image = image;
    return ans;   
}

complex addComp(complex a, complex b) {         //3
    complex ans;
    ans.real = a.real + b.real;
    ans.image = a.image + b.image;
    return ans;
}

complex cmulComp(complex a, double k){
    complex ans;
    ans.real = a.real * k;
    ans.image = a.image * k;
    return ans;
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


//↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)



// ここから下には何も追記しないでください。