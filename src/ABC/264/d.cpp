#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
const string atcoder = "atcoder";
int main(void) {
    string S;
    cin >> S;
    queue<string> que;
    map<string, int> dist;
    que.push(S);
    dist[S] = 0;
    while (!que.empty()) {
        string v = que.front();
        que.pop();
        for (int i = 0; i + 1 < atcoder.size(); i++) {
            string v2 = v;
            swap(v2[i], v2[i + 1]);
            if (!dist.count(v2)) {
                que.push(v2);
                dist[v2] = dist[v] + 1;
            }
        }
    }
    cout << dist[atcoder] << endl;
}