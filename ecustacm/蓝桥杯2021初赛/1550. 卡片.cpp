#include <bits/stdc++.h>

using namespace std;

// http://oj.ecustacm.cn/problem.php?id=1550

int nums[10];

int main() {
    for (int& n : nums)
        n = 2021;
    for (int i = 1; i < 1e9; i++) {
        string str = to_string(i);
        for (char& c: str) {
            if (nums[c - '0'] == 0) {
                cout << i - 1;
                return 0;
            }
            nums[c - '0']--;
        }
    }
}
