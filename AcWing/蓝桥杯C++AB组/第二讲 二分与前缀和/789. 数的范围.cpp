#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/791/

const int N = 100010;

int n, m;  // ���鳤�Ⱥ�ѯ�ʸ���
int nums[N];

void find() {
    int q;
    cin >> q;

    int l = 0, r = n - 1, mid;
    // 1. ��߽����
    while (l < r) {  // �� != ���� < ����
        mid = (l + r) >> 1;
        if (q <= nums[mid]) r = mid;
        else l = mid + 1;  // ע����� ���+1
    }
    // 2. �ұ߽����
    if (q == nums[r]) {  // ע����� ����ʹ��r����l��������ʹ��mid
        printf("%d", r);
        r = n - 1;
        while (l != r) {
            mid = (l + r + 1) >> 1;
            if (q >= nums[mid]) l = mid;
            else r = mid - 1;  // ע����� ���-1
        }
        printf(" %d\n", r);  // ע����� ����ʹ��r����l��������ʹ��mid
    } else {
        // 3. �����޽�
        printf("%d %d\n", -1, -1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < m; i++)
        find();
}
