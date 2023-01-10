#include <bits/stdc++.h>

using namespace std;

// int binarySearch(int nums[], int tar, int len) {
//     int l = -1, r = len - 1, m;
//     while (l < r) {
//         m = (l + r + 1) / 2;
//         printf("l: %d, m: %d, r: %d\n", l, m, r);
//         if (nums[m] <= tar)
//             l = m;
//         else
//             r = m - 1;
//     }
//     return l;
// }

int binarySearch(int nums[], int tar, int len) {
    int l = 0, r = len, m;
    while (l < r) {
        m = (l + r) / 2;
        printf("l: %d, m: %d, r: %d\n", l, m, r);
        if (tar <= nums[m])
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main() {
    int nums[] = {1, 2, 3, 6, 6, 6, 7, 8, 9, 10};
    cout << binarySearch(nums, 6, 10);
}

/*
// 1. 查找lower_bound【第一个>=target的数】。所有解中最小的
// 条件改为 array[mid] > target 就是查找 upper_bound【第一个>target的数】
int left = 0, right = n;
while (left < right) {
    int mid = (left + right) / 2;
    if (array[mid] >= target)
        right = mid;
    else
        left = mid + 1;
}
return right;

// 1. 查找【第一个<=target的数】。所有解中最大的
// 条件改为 array[mid] < target 就是查找 upper_bound【第一个<target的数】
int left = -1, right = n - 1;
while (left < right) {
    int mid = (left + right + 1) / 2;
    if (array[mid] <= taget)
        left = mid;
    else
        right = mid - 1;
}
return right;

// 若必定合法，则可以：left = 0, right = n - 1; 但没有必要
// 终止于 left == right
// 永远包含合法并抛弃非法
 */
