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

complex cmulComp(complex a, double k){          //5
    complex ans;
    ans.real = a.real * k;
    ans.image = a.image * k;
    return ans;
}

double getR2(complex a){
    return a.real * a.real + a.image * a.image;
}

complex invComp(complex a) {
    complex ans;
    double r2 = getR2(a);   

    ans.real =  a.real / r2;
    ans.image = -a.image / r2;

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

complex subComp(complex a, complex b){
    complex ans;
    ans.real=a.real-b.real;
    ans.image=a.real-b.real;
    return ans;
}

complex mulComp(complex a,complex b){
    complex ans;
    ans.real=a.real*b.real;
    ans.image=a.image*b.image;
    return ans;
}

complex conjComp(complex a){
    complex ans;
    ans.real=a.real;
    ans.image=a.image*-1;
    return ans;
}

complex divComp(complex a,complex b){
    complex ans;
    ans.real=a.real/b.real;
    ans.image=a.image/b.image;
    return ans;
}

complex getTheta(complex a){
    
}


//↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)



// ここから下には何も追記しないでください。