#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/790/

const int N = 100010;

int arr[N], t[N];  // �����е�Ԫ�ص�ȡֵ��Χ [1,109]��
int n;
long long ans;

long long mergeSort(int l, int r) {
    if (l >= r) return 0;

    // ����
    int m = (l + r) >> 1;
    long long res = mergeSort(l, m) + mergeSort(m + 1, r);

    // �鲢
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            t[k++] = arr[i++];
        } else {
            t[k++] = arr[j++];
            res += m - i + 1;
        }
    }
    // ɨβ
    while (i <= m) t[k++] = arr[i++];
    while (j <= r) t[k++] = arr[j++];
    // �Ż�
    for (i = l, k = 0; i <= r;)  // �Ż�
        arr[i++] = t[k++];
    return res;
}

int main() {
    cin >> n;  // ���еĳ��ȡ�
    for (int i = 0; i < n; i++)
        cin >> arr[i];  // �������С�

    cout << mergeSort(0, n - 1);  // ���һ����������ʾ����Եĸ�����
}
