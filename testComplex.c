#include <math.h>
#include <stdio.h>

// 複素数構造体を使う時には次の行を活かす
#include "complex.h"
#include "testCommon.h"

//12/8 コンパイル通ったけど、M_PIの定義されてないってVScodeに言われたので自分で定義してます↓
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 各自の場所に記載してください。順番が違ってもテストには問題ないので気にしないでください。

/* テスト関数の記述部 */
// ↓↓↓↓ 3323 武中優成 記述部(この範囲以外には追加しない)

void testFirst() {
    testStart("first");
    assertEqualsInt(1 * 1, 1);
    assertEqualsInt(2 * 2, 4);
}

void testMakeComp() {
    complex ans;
    testStart("makeComp");
    // 1+2jを作成
    ans = makeComp(1.0, 2.0);
    assertEqualsDouble(ans.real, 1.0);
    assertEqualsDouble(ans.image, 2.0);
    // 3.4+5.6jを作成
    ans = makeComp(3.4, 5.6);
    assertEqualsDouble(ans.real, 3.4);
    assertEqualsDouble(ans.image, 5.6);
}

void testAddComp() {
    complex in1, in2, ans;
    testStart("addComp");

    // (1+2j) + (3+4j) = 4+6j
    in1 = makeComp(1.0, 2.0);
    in2 = makeComp(3.0, 4.0);
    ans = addComp(in1, in2);
    assertEqualsComplex(ans, makeComp(4.0, 6.0));

    // (-1.5+2.5j) + (2.5-1.0j) = 1.0+1.5j
    in1 = makeComp(-1.5, 2.5);
    in2 = makeComp(2.5, -1.0);
    ans = addComp(in1, in2);
    assertEqualsComplex(ans, makeComp(1.0, 1.5));
}

void testCmulComp(){
    complex in ,ans;
    testStart("cmulComp");

    // (1+2j) * 3 = 3+6j
    in = makeComp(1.0, 2.0);
    ans = cmulComp(in, 3.0);
    assertEqualsComplex(ans, makeComp(3.0, 6.0));

    // (-1.5+2.0j) * (-2) = 3.0-4.0j
    in = makeComp(-1.5, 2.0);
    ans = cmulComp(in, -2.0);
    assertEqualsComplex(ans, makeComp(3.0, -4.0));
}

void testGetR2() {
    complex in;
    double ans;
    testStart("getR2");

    // |3+4j|^2 = 25
    in = makeComp(3.0, 4.0);
    ans = getR2(in);
    assertEqualsDouble(ans, 25.0);

    // |1-2j|^2 = 5
    in = makeComp(1.0, -2.0);
    ans = getR2(in);
    assertEqualsDouble(ans, 5.0);
}

void testInvComp() {
    complex in, ans;
    testStart("invComp");

    // 1/(1+0j) = 1+0j
    in = makeComp(1.0, 0.0);
    ans = invComp(in);
    assertEqualsComplex(ans, makeComp(1.0, 0.0));

    // 1/(1+1j) = 0.5 - 0.5j
    in = makeComp(1.0, 1.0);
    ans = invComp(in);
    assertEqualsComplex(ans, makeComp(0.5, -0.5));
}

void testGetR() {
    complex in;
    double ans;
    testStart("getR");

    // |3+4j|= 5
    in = makeComp(3.0, 4.0);
    ans = getR(in);
    assertEqualsDouble(ans, 5.0);

    // |1+0j| = 1
    in = makeComp(1.0, 0.0);
    ans = getR(in);
    assertEqualsDouble(ans, 1.0);
}

void testPrintComp() {
    complex a = makeComp(3.0, 4.0);
    complex b = makeComp(5.0, -2.0);

    testStart("printComp");

    printComp(a);   // 3+4j
    printComp(b);   // 5-2j
}

// ↑↑↑↑ ここまでを 3323 武中優成 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

// ↓↓↓↓ 3342 宮坂卓真 記述部(この範囲以外には追加しない)

void testSecond() {
    testStart("second");
    assertEqualsDouble(sqrt(4.0), 2.0);
    assertEqualsDouble(sqrt(9.0), 3.0);
}

void testMakeCompRT() {
    complex ans;
    testStart("makeCompRT");

    // 3∠0 → 3 + 0j
    ans = makeCompRT(3.0, 0.0);
    assertEqualsComplex(ans, makeComp(3.0, 0.0));

    // 2∠π/2 → 0 + 2j
    ans = makeCompRT(2.0, M_PI/2.0);
    assertEqualsComplex(ans, makeComp(0.0, 2.0));

    // 1∠-π/4 → (cos(-π/4), sin(-π/4))
    ans = makeCompRT(1.0, -M_PI/4.0);
    assertEqualsComplex(ans, makeComp(
        cos(-M_PI/4.0),
        sin(-M_PI/4.0)
    ));
}

// 4. 減算のテスト
void testSubComp() {
    complex a, b, ans;
    testStart("subComp");
    
    // (5+3i) - (2+1i) = 3+2i
    a = makeComp(5.0, 3.0);
    b = makeComp(2.0, 1.0);
    ans = subComp(a, b);
    assertEqualsComplex(ans, makeComp(3.0, 2.0));

    // (1-1i) - (1-1i) = 0+0i
    a = makeComp(1.0, -1.0);
    b = makeComp(1.0, -1.0);
    ans = subComp(a, b);
    assertEqualsComplex(ans, makeComp(0.0, 0.0));
}

// 6. 乗算のテスト
void testMulComp() {
    complex a, b, ans;
    testStart("mulComp");

    // (2+3i) * (4+5i) = (8-15) + (10+12)i = -7+22i
    a = makeComp(2.0, 3.0);
    b = makeComp(4.0, 5.0);
    ans = mulComp(a, b);
    assertEqualsComplex(ans, makeComp(-7.0, 22.0));

    // i * i = -1
    a = makeComp(0.0, 1.0);
    b = makeComp(0.0, 1.0);
    ans = mulComp(a, b);
    assertEqualsComplex(ans, makeComp(-1.0, 0.0));
}

// 8. 共役複素数のテスト
void testConjComp() {
    complex a, ans;
    testStart("conjComp");

    // conj(3+4i) = 3-4i
    a = makeComp(3.0, 4.0);
    ans = conjComp(a);
    assertEqualsComplex(ans, makeComp(3.0, -4.0));
}

// 10. 除算のテスト
void testDivComp() {
    complex a, b, ans;
    testStart("divComp");

    // (10+5i) / (1+2i) = 4-3i
    // 検算: (4-3i)(1+2i) = 4 + 8i - 3i - 6i^2 = 10+5i OK
    a = makeComp(10.0, 5.0);
    b = makeComp(1.0, 2.0);
    ans = divComp(a, b);
    assertEqualsComplex(ans, makeComp(4.0, -3.0));
}

// 12. 偏角のテスト (全象限)
void testGetTheta() {
    testStart("getTheta");

    // 第1象限 (1, 1) -> 45度 (PI/4)
    assertEqualsDouble(getTheta(makeComp(1.0, 1.0)), M_PI/4.0);

    // 第2象限 (-1, 1) -> 135度 (3PI/4)
    assertEqualsDouble(getTheta(makeComp(-1.0, 1.0)), 3.0*M_PI/4.0);

    // 第3象限 (-1, -1) -> -135度 (-3PI/4)
    assertEqualsDouble(getTheta(makeComp(-1.0, -1.0)), -3.0*M_PI/4.0);

    // 第4象限 (1, -1) -> -45度 (-PI/4)
    assertEqualsDouble(getTheta(makeComp(1.0, -1.0)), -M_PI/4.0);
}

// 14. 表示のテスト
void testPrintCompRT() {
    testStart("printCompRT");
    
    // 1+1i -> sqrt(2) ∠ 45度 -> 1.414∠45.000
    printf("  [Expect]: 1.414∠45.000\n");
    printf("  [Actual]: ");
    printCompRT(makeComp(1.0, 1.0));

    // 0+2i -> 2 ∠ 90度 -> 2.000∠90.000
    printf("  [Expect]: 2.000∠90.000\n");
    printf("  [Actual]: ");
    printCompRT(makeComp(0.0, 2.0));
}



// ↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////



// ここから main の始まりまでは追加・変更しないでください。

/* main関数の記述部 */
int main() {
    // ↓↓↓↓ 3323 武中優成 記述部(この範囲以外には追加しない)
    testFirst();
    testMakeComp(); //1
    testAddComp();  //3
    testCmulComp(); //5
    testGetR2();    //7
    testInvComp();  //9
    testGetR();     //11
    testPrintComp();//13
    // ↑↑↑↑ ここまでを 3323 武中優成 が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

    // ↓↓↓↓ 3342 宮坂卓真 記述部(この範囲以外には追加しない)
    testSecond();
    testMakeCompRT();
    testSubComp();    //4 (追加)
    testMulComp();    //6 (追加)
    testConjComp();   //8 (追加)
    testDivComp();    //10 (追加)
    testGetTheta();   //12 (追加)
    testPrintCompRT();//14 (追加)
    // ↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)

    
    // ここから下は追加・変更しないでください。

    testErrorCheck();  // これは消さないこと
    return 0;
}
