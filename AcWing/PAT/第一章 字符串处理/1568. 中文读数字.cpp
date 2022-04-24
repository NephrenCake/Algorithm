#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1570/

string Dict[] = {"Ge", "Shi", "Bai", "Qian", "Wan", "Yi"};
string Num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

string convertNum(string str) {
    string ans;
    if (str[0] == '0') return "ling";

    if (str[0] == '-') {
        ans = "Fu ";
        str.erase(0, 1);
    }

    int len = str.size();
    while (len) {
        int zeroCnt = 0;  // 计算每4位数中0个数量，如果有4个0则不用输出万
        bool zero = false;  // 修改的地方，只考虑组内是否出现0
        for (int j = (len - 1) % 4; j >= 0; j--) {  // 枚举个十百千
            // 获取最高位的数字
            int num = str[str.size() - len] - '0';

            if (num > 0) {
                if (zero) {  // 如果上一位是0
                    ans += "ling ";
                    zero = false;
                }
                // 输出数字+单位
                ans += Num[num] + ' ';
                if (j != 0) ans += Dict[j] + ' ';
            } else {  // 如果当前数字为0
                zeroCnt++;
                zero = true;
            }
            len--;
        }
        // 位数大于4位，且该段不全为0，输出亿或者万
        if (len / 4 > 0 && zeroCnt != 4) ans += Dict[3 + len / 4] + ' ';
    }
    return ans.substr(0, ans.size() - 1);
}

int main() {
    string str;
    getline(cin, str);
    cout << convertNum(str) << endl;
}
