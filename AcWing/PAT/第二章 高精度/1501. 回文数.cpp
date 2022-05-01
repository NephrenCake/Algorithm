#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1503/

vector<int> addReverse(vector<int> a) {
    int len = a.size(), t = 0;
    vector<int> b;
    for (int i = 0; i < len; i++) {
        int v = a[i] + a[len - 1 - i] + t;
        t = v / 10;
        b.push_back(v % 10);
    }
    if (t == 1) b.push_back(1);

    return b;
}

bool isReverse(vector<int> &a) {
    int len = a.size();
    for (int i = 0; i < len; i++)
        if (a[i] != a[len - 1 - i])
            return false;
    return true;
}

int main() {
    int op_limit;
    string str;
    cin >> str >> op_limit;
    vector<int> num;
    for (int i = 0; i < str.size(); i++)
        num.push_back(str[str.size() - 1 - i] - '0');

    int op_cnt = 0;
    while (op_cnt < op_limit) {
        if (isReverse(num)) break;
        op_cnt++;
        num = addReverse(num);
    }

    // 注意：翻转数组 vector<int> b(a.rbegin(), a.rend());

    for (int i = num.size() - 1; i >= 0; i--)
        cout << num[i];
    cout << endl << op_cnt;
}
