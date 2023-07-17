#include <iostream>
#include <vector>
using namespace std;
const int MAX_V = 2100;   // ツリーのサイズのありうる最大値
int N;                    // ツリーのサイズ
vector<int> tree[MAX_V];  // ツリーの隣接リスト表現

int sizeSubtree[MAX_V];  // 部分木のサイズ
vector<int> centroids;   // 重心列挙の答えがここに入る

void SubFindCentroids(int v, int parent_of_v = -1) {
    sizeSubtree[v] = 1;
    bool isCentroid = true;
    for (int child : tree[v]) {
        if (child == parent_of_v) continue;
        SubFindCentroids(child, v);
        sizeSubtree[v] += sizeSubtree[child];
        if (sizeSubtree[child] > N / 2) isCentroid = false;
    }
    if (N - sizeSubtree[v] > N / 2) isCentroid = false;
    if (isCentroid) centroids.push_back(v);
}

void FindCentroids() {
    centroids.clear();
    SubFindCentroids(0);
}