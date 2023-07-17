#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    vector<string> data;
    int H;
    int W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    // たて
    for (int i = 0; i < H; i++) {
        for (int j = 0; j + 4 < W; j++) {
            if (data.at(i).at(j) == 's' && data.at(i).at(j + 1) == 'n' &&
                data.at(i).at(j + 2) == 'u' && data.at(i).at(j + 3) == 'k' &&
                data.at(i).at(j + 4) == 'e') {
                    
            }
            if(data.at(i).at(j) == 'e' && data.at(i).at(j)=='k' && data.at(i).at(j)=='u' && data.at(i).at(j)=='n' && data.at(i).at(j)=='s'){
                cout << 
            }
        }
    }
}