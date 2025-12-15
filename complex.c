// X班 complex.c

#include "complex.h"

#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

double getR(complex a) {
    return sqrt(getR2(a));
}

void printComp(complex a) {
    if (a.image >= 0) {
        printf("%g+%gj\n", a.real, a.image);
    } else {
        printf("%g%gj\n", a.real, a.image);
    }
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
    ans.image=a.image-b.image;
    return ans;
}

complex mulComp(complex a,complex b){
    complex ans;
    ans.real=a.real*b.real - a.image *b.image;
    ans.image=a.real*b.image + a.image * b.real;
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
    double denominator = b.real * b.real + b.image * b.image;
    ans.real = (a.real * b.real + a.image * b.image) / denominator;
    ans.image = (a.image * b.real - a.real * b.image) / denominator;
    return ans;
}

double getTheta(complex a){
    return atan2(a.image, a.real);
}

void printCompRT(complex a){
    double r = sqrt(a.real * a.real + a.image * a.image);
    
    // 偏角 θ を計算 (getThetaを利用)
    double thetaRad = getTheta(a);
    
    // 表示例が「45.000」となっているため、ラジアンを度に変換する
    double thetaDeg = thetaRad * (180.0 / M_PI);

    printf("%.3f∠%.3f\n", r, thetaDeg);
}

//↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)



// ここから下には何も追記しないでください。