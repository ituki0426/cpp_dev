#include <iostream>
using namespace std;
int main(void) {
    int i;
    cin >> i;
    int table[i];
    int s, e;
    for (int j = 0; j < i; j++) table[j] = 0;
    for (int j = 0; j < i; j++) {
        cin >> s >> e;
        table[s]++;
        table[e]--;
    }
    for (int j = 1; j < i; j++) table[j] += table[j - 1];
    int M = 0;
    for (int j = 0; j < i; j++) M = max(M, table[j]);
}