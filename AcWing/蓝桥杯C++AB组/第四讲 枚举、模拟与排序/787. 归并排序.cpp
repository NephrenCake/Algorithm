#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/789/

const int N = 100010;

int n;
int arr[N];

void merge(int l, int m, int r) {
    // int tmp[r - l + 1];
    vector<int> tmp(r - l + 1);
    int i = l, j = m + 1, k = 0;  // 三指针拷贝
    while (i <= m && j <= r)
        tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    while (i <= m)  // 收尾
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (i = l, k = 0; i <= r;)  // 放回
        arr[i++] = tmp[k++];
}

void mergeSort(int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
