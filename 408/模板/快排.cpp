#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &arr, int l, int r) {
        if (l >= r)
            return;
        int p = partition_ACWing(arr, l, r);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, r);
    }

    int partition_ACWing(vector<int> &a, int l, int r) {
        int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
        while (i < j) {
            do i++; while (a[i] < x);
            do j--; while (a[j] > x);
            if (i < j) swap(a[i], a[j]);
        }
        return j;
    }

    int partition_408(vector<int> &a, int l, int r) {
        int p = a[l];
        while (l < r) {
            while (l < r && a[r] >= p)
                r--;
            a[l] = a[r];
            while (l < r && a[l] <= p)
                l++;
            a[r] = a[l];
        }
        a[l] = p;
        return l;
    }

    int partition_lyd(vector<int> &a, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pivotVal = a[pivot];
        while (l <= r) {
            while (a[l] < pivotVal)
                l++;
            while (a[r] > pivotVal)
                r--;
            if (l == r)
                break;
            if (l < r) {
                int temp = a[l];
                a[l] = a[r];
                a[r] = temp;
                l++;
                r--;
            }
        }
        return r;
    }
};

int main() {
    vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution s;
    s.sortArray(a);
    for (auto i: a)
        cout << i << " ";
}
