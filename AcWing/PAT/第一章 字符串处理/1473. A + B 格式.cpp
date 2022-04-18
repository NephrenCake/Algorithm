#include <bits/stdc++.h>

// https://www.acwing.com/problem/content/1475/

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string num = to_string(c);
    string res;
    for (int i = num.size() - 1, j = 0; i >= 0; i--) {
        res = num[i] + res;
        j++;
        if (j % 3 == 0 && i != 0 && num[i - 1] != '-')
            res = ',' + res;
    }
    cout << res;
}

/**
 * 解1 在输出时构建。逻辑繁琐，不建议使用
 */
/*
int main() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    bool f = sum < 0;
    int temp = abs(sum);
    int ans[3];
    for (int i = 2; i >= 0; i--) {
        ans[i] = temp % 1000;
        temp /= 1000;
    }
    if (sum == 0) {
        cout << 0;
        return 0;
    }
    if (f) cout << "-";
    bool first = true;
    for (int i = 0; i < 3; i++) {
        int& s = ans[i];
        if (first && s == 0) continue;
        else if (first && s != 0) {
            first = false;
            printf("%d", s);
            if (i != 2) printf(",");
        } else {
            printf("%03d", s);
            if (i != 2) printf(",");
        }
    }
}
*/