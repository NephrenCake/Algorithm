#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1600/

int max_limit = 1000, min_limit = -1000;
vector<double> nums;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string temp;
        cin >> temp;

        // 精度
        int p = temp.find('.');
        if (p != -1 && p + 3 < temp.size()) {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
            continue;
        }

        // 不是数字
        bool is_num = true;
        for (int i = 0; i < temp.size(); i++) {
            char &c = temp[i];
            if (!(c >= '0' && c <= '9' || c == '-' && i == 0 && temp.size() != 1 || c == '.')) {
                is_num = false;
                break;
            }
        }
        if (!is_num) {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
            continue;
        }

        // 超出范围
        double val = stod(temp);
        if (val < min_limit || val > max_limit) {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
            continue;
        }

        // 符合
        nums.push_back(val);
    }
    if (nums.size() == 0)
        cout << "The average of 0 numbers is Undefined";
    else if (nums.size() == 1)
        printf("The average of 1 number is %.2lf", (double) nums[0]);
    else {
        double cnt = 0.;
        for (double &i: nums)
            cnt += i;
        printf("The average of %d numbers is %.2lf", (int) nums.size(), cnt / nums.size());
    }
}
