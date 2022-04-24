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
        int zeroCnt = 0;  // ����ÿ4λ����0�������������4��0���������
        bool zero = false;  // �޸ĵĵط���ֻ���������Ƿ����0
        for (int j = (len - 1) % 4; j >= 0; j--) {  // ö�ٸ�ʮ��ǧ
            // ��ȡ���λ������
            int num = str[str.size() - len] - '0';

            if (num > 0) {
                if (zero) {  // �����һλ��0
                    ans += "ling ";
                    zero = false;
                }
                // �������+��λ
                ans += Num[num] + ' ';
                if (j != 0) ans += Dict[j] + ' ';
            } else {  // �����ǰ����Ϊ0
                zeroCnt++;
                zero = true;
            }
            len--;
        }
        // λ������4λ���Ҹöβ�ȫΪ0������ڻ�����
        if (len / 4 > 0 && zeroCnt != 4) ans += Dict[3 + len / 4] + ' ';
    }
    return ans.substr(0, ans.size() - 1);
}

int main() {
    string str;
    getline(cin, str);
    cout << convertNum(str) << endl;
}
