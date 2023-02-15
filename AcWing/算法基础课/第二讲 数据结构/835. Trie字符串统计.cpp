#include <iostream>

using namespace std;

const int N = 2e5 + 10;
string s, x;
int n, ne[N][26], cnt[N], idx = 1;  // 0既是根节点，又是空节点。ne就是next指针，每个节点最多有26个孩子

void insert(string x) {
    int cur = 0;
    for (auto c: x) {
        int ch = c - 'a';
        if (ne[cur][ch] == 0) ne[a][b] = idx++;
        cur = ne[cur][ch];
    }
    cnt[cur]++;
}

int query(string x) {
    int cur = 0;
    for (auto c: x) {
        int ch = c - 'a';
        if (ne[cur][ch] == 0) return 0;
        cur = ne[cur][ch];
    }
    return cnt[cur];
}

int main() {
    cin >> n;
    while (n--) {
        cin >> s >> x;
        if (s == "I") insert(x);
        else cout << query(x) << endl;
    }
}
