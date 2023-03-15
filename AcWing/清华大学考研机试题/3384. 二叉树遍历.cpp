#include <iostream>

using namespace std;

string s;

struct Node {
    char v;
    Node *l;
    Node *r;
};

void make_tr(Node *root, unsigned long long &idx) {
    root->v = s[idx];
    if (s[idx++] == '#') return;
    root->l = new Node();
    root->r = new Node();
    make_tr(root->l, idx);
    make_tr(root->r, idx);
}

void dfs(Node *root) {
    if (root == nullptr) return;
    if (root->v == '#') return;
    dfs(root->l);
    cout << root->v << " ";
    dfs(root->r);
}

int main() {
    cin >> s;
    Node *tr = new Node();
    unsigned long long idx = 0;
    make_tr(tr, idx);
    dfs(tr);
}
