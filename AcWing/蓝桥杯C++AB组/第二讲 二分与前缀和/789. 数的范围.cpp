#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/791/

const int N = 100010;

int n, m;  // 数组长度和询问个数
int nums[N];

void find() {
    int q;
    cin >> q;

    int l = 0, r = n - 1, mid;
    // 1. 左边界二分
    while (l < r) {  // 用 != 或者 < 都行
        mid = (l + r) >> 1;
        if (q <= nums[mid]) r = mid;
        else l = mid + 1;  // 注意错误 这边+1
    }
    // 2. 右边界二分
    if (q == nums[r]) {  // 注意错误 必须使用r或者l，但不能使用mid
        printf("%d", r);
        r = n - 1;
        while (l != r) {
            mid = (l + r + 1) >> 1;
            if (q >= nums[mid]) l = mid;
            else r = mid - 1;  // 注意错误 这边-1
        }
        printf(" %d\n", r);  // 注意错误 必须使用r或者l，但不能使用mid
    } else {
        // 3. 可能无解
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
