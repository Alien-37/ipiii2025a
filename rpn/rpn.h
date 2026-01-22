/*#ifndef __MATRIX_H
#define __MATRIX_H
       
#define N 100

#endif */

#ifndef __MATRIX_H
#define __MATRIX_H

#include <math.h>   

#define N 100   

//スタック構造体
typedef struct {
    double data[N];
    int head;
} stack;

//プロトタイプ宣言 #9まで
void initStack(stack *sp);
double currentStack(stack *sp);
void pushStack(stack *sp, double val);
double pullStack(stack *sp);

void printStack(stack *sp);
void addStack(stack *sp);

#endif
