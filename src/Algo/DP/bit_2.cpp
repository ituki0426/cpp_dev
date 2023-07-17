// ビット演算を用いたフラグ管理
#include <bitset>
#include <iostream>
using namespace std;

const unsigned int BIT_FLAG_0 = (1 << 0);  // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1);  // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2);  // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3);  // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4);  // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5);  // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6);  // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7);  // 0000 0000 1000 0000

//ビットi番目のフラグが立っているかどうか : if (bit & (1<<i))
//ビットi番目のフラグが消えているかどうか : if (!(bit & (1<<i)))
//ビットi番目のフラグを立てる : bit |= (1<<i)
//ビットi番目のフラグを消す : bit &= ~(1<<i)

int main(void) {
    //{1,3,5}にフラグが立ったビット
    unsigned int bit = BIT_FLAG_1 | BIT_FLAG_3 | BIT_FLAG_5;
    cout << "{1, 3,5}" << bitset<8>(bit) << endl;
    // ビット{1,3,5}について、３番目のフラグが立っていること
    if (bit & BIT_FLAG_3) cout << "3 is in" << bitset<8>(bit) << endl;

    // ビット{1,3,5}について、0番目のフラグが立っていないこと
    if (!(bit & BIT_FLAG_0)) {
        cout << "0 is not in " << bitset<8>(bit) << endl;
    }
}