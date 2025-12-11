#include <math.h>
#include <stdio.h>

// 複素数構造体を使う時には次の行を活かす
#include "complex.h"
#include "testCommon.h"

//コンパイル通ったけど、M_PIの定義されてないってVScodeに言われたので自分で定義してます↓
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

    // テスト1: 1/(1+0j) = 1+0j
    in = makeComp(1.0, 0.0);
    ans = invComp(in);
    assertEqualsComplex(ans, makeComp(1.0, 0.0));

    // テスト2: 1/(1+1j) = 0.5 - 0.5j
    in = makeComp(1.0, 1.0);
    ans = invComp(in);
    assertEqualsComplex(ans, makeComp(0.5, -0.5));
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
    // ↑↑↑↑ ここまでを 3323 武中優成 が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

    // ↓↓↓↓ 3342 宮坂卓真 記述部(この範囲以外には追加しない)
    testSecond();
    testMakeCompRT();
    
    // ↑↑↑↑ ここまでを 3342 宮坂卓真 が記述(この範囲以外には追加しない)

    
    // ここから下は追加・変更しないでください。

    testErrorCheck();  // これは消さないこと
    return 0;
}
