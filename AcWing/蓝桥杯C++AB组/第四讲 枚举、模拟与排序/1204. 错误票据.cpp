#include <cstring>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1206/

/**
 * 解1
 */

const int M = 1e5 + 10, INF = 0x3f3f3f;

int cnt[M];
int Min = INF, Max = -INF;
int ans1, ans2;

int main() {
    int n, t;
    cin >> n;
    string line;
    getline(cin, line);
    while (n--) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> t) {
            cnt[t]++;
            Max = max(Max, t);
            Min = min(Min, t);
        }
    }

    for (int j = Min; j <= Max; j++) {
        if (cnt[j] == 0) ans1 = j;
        else if (cnt[j] == 2) ans2 = j;
    }
    cout << ans1 << " " << ans2 << endl;
}

/**
 * 解2
 */

/*
const int N = 1e4 + 10;

int n;
int a[N];

int main() {
    int cnt;
    cin >> cnt;

    string line;
    getline(cin, line);  // 或cin.get()或getchar()  ---- 滤去上次的空格
    while (cnt--) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> a[n]) n++;
    }

    sort(a, a + n);

    int res1, res2;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) res1 = a[i];
        else if (a[i] == a[i - 1] + 2) res2 = a[i] - 1;
    }

    cout << res2 << ' ' << res1 << endl;
}
*/