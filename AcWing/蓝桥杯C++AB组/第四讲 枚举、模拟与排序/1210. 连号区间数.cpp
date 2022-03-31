#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1212/

const int N = 10000;

int n, ans;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int min_ = a[i], max_ = a[i];
        for (int j = i; j < n; j++) {
            min_ = min(min_, a[j]);
            max_ = max(max_, a[j]);
            if (max_ - min_ == j - i)  // ºËÐÄ
                ans++;
        }
    }
    cout << ans;
}
