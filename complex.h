#ifndef __COMPLEX_H__
#define __COMPLEX_H__

// 二重読み込みを防ぐために、complex 構造体の定義などはここに記述

<<<<<<< HEAD
// ↓↓↓↓ complex の定義 by 3323 武中優成
typedef struct {
    double real;   // 実部
    double image;   // 虚部
} complex;

//↑↑↑↑ ここまでを 3323 武中優成 が記述
=======
// ↓↓↓↓ complex の定義 by 33aa AAAA

//↑↑↑↑ ここまでを 33aa AAAA が記述
>>>>>>> a97ddeb9bc5edd0ead77606ff86da0edef36c7d1

//////////////////////////////////////////////////////////////////////////////////////////

// プロトタイプ宣言部
<<<<<<< HEAD
//↓↓↓↓ 3323 武中優成 記述部(この範囲以外に追加しない)
complex makeComp(double real, double image);    //1
complex addComp(complex a, complex b);          //3
complex cmulComp(complex a, double k);          //5
double getR2(complex a);                        //7
complex invComp(complex a);                     //9
double getR(complex a);                         //11
void printComp(complex a);                      //13
//↑↑↑↑ ここまでを 3323 武中優成 が記述(この範囲以外に追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 3342 宮坂卓真 記述部(この範囲以外に追加しない)
complex makeCompRT(double r, double theta);     //2
complex subComp(complex a, complex b);          //4
complex mulComp(complex a, complex b);          //6
complex conjComp(complex a);                    //8
complex divComp(complex a,complex b);           //10
double getTheta(complex a);                     //12
void printCompRT(complex a);                    //14



//↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外に追加しない)

=======
//↓↓↓↓ 33xx XXXX 記述部(この範囲以外に追加しない)



//↑↑↑↑ ここまでを 33xx XXXX が記述(この範囲以外に追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 33yy YYYY 記述部(この範囲以外に追加しない)



//↑↑↑↑ ここまでを 33yy YYYY が記述(この範囲以外に追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 33zz ZZZZ 記述部(この範囲以外に追加しない)



//↑↑↑↑ ここまでを 33zz ZZZZ が記述(この範囲以外に追加しない)
>>>>>>> a97ddeb9bc5edd0ead77606ff86da0edef36c7d1

// ここから下には何も追記しないでください。

#endif