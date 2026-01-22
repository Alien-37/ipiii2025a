#include "rpn.h"
#include <math.h>

//9
void initStack(stack *sp){
    sp->head = N;
}
double currentStack(stack *sp){
    if (sp->head == N) {
        return sqrt(-1.0);
    }
    return sp->data[sp->head];
}
void pushStack(stack *sp, double val){
    sp->data[--sp->head] = val;
}
double pullStack(stack *sp){
    if (sp->head == N) {
        return sqrt(-1.0);  
    }
    return sp->data[sp->head++];
}

// 10
void printStack(stack *sp){
    int i;
    if (sp->head == N) {
        printf("(empty)\n");
        return;
    }
    for (i = N - 1; i >= sp->head; i--) {
        printf("%f\n", sp->data[i]);
    }
}
void addStack(stack *sp){
    double a, b;
    a = pullStack(sp);
    b = pullStack(sp);
    if (isnan(a) || isnan(b)) {
        return;
    }
    pushStack(sp, a + b);
}


