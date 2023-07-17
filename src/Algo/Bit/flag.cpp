#include <bitset>
#include <iostream>
#include <vector>
using namespace std;


// 　ビットbitにi番目のフラグが立っているかどうか：　if (bit & (1<<i))
// 　ビット bit に i 番目のフラグが消えているかどうか：　if (!(bit & (1<<i)))
// 　ビット bit に i 番目のフラグを立てる：　bit |= (1<<i)
// 　ビット bit に i 番目のフラグを消す：　bit &= ~(1<<i)
// 　ビット bit に i 番目のフラグを反転する：　bit ^= (1<<i)

const unsigned int BIT_FLAG_0 = (1 << 0);  // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1);  // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2);  // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3);  // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4);  // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5);  // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6);  // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7);  // 0000 0000 1000 0000

int main(void) {
    unsigned int bit = BIT_FLAG_1 | BIT_FLAG_3 | BIT_FLAG_5;
    cout << "{1, 3, 5} = " << bitset<8>(bit) << endl;
}