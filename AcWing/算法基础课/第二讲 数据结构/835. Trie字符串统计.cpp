#include <iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;  // 类似指针，指向当前节点
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a'; // 将字母转化为数字
        if (!son[p][u]) son[p][u] = ++idx;   // 该节点不存在，创建节点
        p = son[p][u];  // 使“p指针”指向下一个节点
    }
    cnt[p]++;  // 结束时的标记，也是记录以此节点结束的字符串个数
}

int query(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;  // 该节点不存在，即该字符串不存在
        p = son[p][u];
    }
    return cnt[p];  // 返回字符串出现的次数
}

int main() {
    int m;
    string str, op;
    cin >> m;
    while (m--) {
        cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }
}
