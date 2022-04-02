#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int arr[N];
int st[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int l = 1, r = 1;  // cnt统计不同值个数
    for (int i = 1, j = 0, cnt = 0; j <= n;) {
        while (cnt <= k) {
            j++;
            if (j > n) break;
            if (st[arr[j]] == 0)
                cnt++;
            st[arr[j]]++;
            // cout << i << " " << j << " " << cnt << endl;
        }
        if (j - i > r - l + 1) {
            r = j - 1, l = i;
        }
        st[arr[i]]--;  // 左指针指向数值占用-1
        if (st[arr[i]] == 0)
            cnt--;
        i++;  // 左指针右移
    }
    printf("%d %d", l, r);
}
