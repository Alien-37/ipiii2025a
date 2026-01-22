#include <math.h>
#include <stdio.h>

#include "rpn.h"
#include "testCommon.h"

//initStack のテスト
void testInitStack(){
    stack my_stack;
    testStart("initStack");
    my_stack.head = 0;   
    initStack(&my_stack);
    assertEqualsInt(my_stack.head, N);
}

//currentStack のテスト
void testCurrentStack(){
    stack my_stack;
    double ans;
    testStart("currentStack");
    initStack(&my_stack);

    ans = currentStack(&my_stack);
    assertNotEqualsInt(isnan(ans), 0);

    my_stack.head = N - 1;
    my_stack.data[N - 1] = 1.0;

    ans = currentStack(&my_stack);
    assertEqualsDouble(ans, 1.0);
}

//pushStack のテスト
void testPushStack(){
    stack my_stack;
    testStart("pushStack");

    initStack(&my_stack);

    pushStack(&my_stack, 1.0);
    assertEqualsDouble(currentStack(&my_stack), 1.0);
    assertEqualsInt(my_stack.head, N - 1);

    pushStack(&my_stack, 3.14);
    assertEqualsDouble(currentStack(&my_stack), 3.14);
    assertEqualsInt(my_stack.head, N - 2);
}

//pullStack のテスト
void testPullStack(){
    stack my_stack;
    double ans;
    testStart("pullStack");

    initStack(&my_stack);

    pushStack(&my_stack, 1.0);
    pushStack(&my_stack, 3.14);

    ans = pullStack(&my_stack);
    assertEqualsDouble(ans, 3.14);
    assertEqualsInt(my_stack.head, N - 1);

    ans = pullStack(&my_stack);
    assertEqualsDouble(ans, 1.0);
    assertEqualsInt(my_stack.head, N);

    ans = pullStack(&my_stack);
    assertNotEqualsInt(isnan(ans), 0);
}

//addStack のテスト
void testAddStack(){
    stack s;
    testStart("addStack");
    initStack(&s);

    pushStack(&s, 2.0);
    pushStack(&s, 3.0);
    addStack(&s);

    assertEqualsDouble(currentStack(&s), 5.0);
    assertEqualsInt(s.head, N - 1);

    initStack(&s);
    pushStack(&s, 1.0);
    addStack(&s);

    assertEqualsDouble(currentStack(&s), 1.0);
    assertEqualsInt(s.head, N - 1);

    initStack(&s);
    addStack(&s);
    assertEqualsInt(s.head, N);
}


int main()
{
    testInitStack();
    testCurrentStack();
    testPushStack();
    testPullStack();

    testAddStack();  

    testErrorCheck();
}

