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
