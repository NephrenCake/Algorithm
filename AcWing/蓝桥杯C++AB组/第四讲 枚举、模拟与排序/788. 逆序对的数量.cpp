#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/790/

const int N = 100010;

int arr[N], t[N];  // 数列中的元素的取值范围 [1,109]。
int n;
long long ans;

long long mergeSort(int l, int r) {
    if (l >= r) return 0;

    // 分治
    int m = (l + r) >> 1;
    long long res = mergeSort(l, m) + mergeSort(m + 1, r);

    // 归并
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            t[k++] = arr[i++];
        } else {
            t[k++] = arr[j++];
            res += m - i + 1;
        }
    }
    // 扫尾
    while (i <= m) t[k++] = arr[i++];
    while (j <= r) t[k++] = arr[j++];
    // 放回
    for (i = l, k = 0; i <= r;)  // 放回
        arr[i++] = t[k++];
    return res;
}

int main() {
    cin >> n;  // 数列的长度。
    for (int i = 0; i < n; i++)
        cin >> arr[i];  // 整个数列。

    cout << mergeSort(0, n - 1);  // 输出一个整数，表示逆序对的个数。
}
