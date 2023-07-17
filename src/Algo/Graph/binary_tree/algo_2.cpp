#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
struct Node {
    Node* parent;  // 親
    Node* left;    // 左の子
    Node* right;   // 右の子
    int value;     // ノードの値
    Node(const int& value = 0) : value(value) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};
Node* root = new Node();
void insert(Node* node_v) {
    int v = node_v->value;
    Node *par, *nex = root;
    while (nex) {
        par = nex;
        if (v <= par->value)
            nex = par->left;
        else
            nex = par->right;
    }
    // 挿入するノードnode_vと親parについて、parとnode_vのつながりを作る
    if (v <= par->value) {
        node_v->parent = par;
        par->left = node_v;
    } else {
        node_v->parent = par;
        par->right = node_v;
    }
}

vector<int> number;  // 頂点番号を記録する配列

// ノード nodeを視点に、行きがけじゅんでnumberに記録する関数
void rec(Node* node) {
    number.push_back(node->value);
    if (node->left) rec(node->left);

    if (node->right) rec(node->right);

    return;
}
int main(void) {
    int Q;
    cin >> Q;
    rep(i, Q) {
        int v;
        cin >> v;
        if (i == 0) {
            root->value = v;
            continue;
        }
        Node* node_v = new Node(v);
        insert(node_v);
    }
    rec(root);
    assert(number.size() == Q);
    rep(i, Q) { cout << number[i] << " "; }
    cout << endl;
}