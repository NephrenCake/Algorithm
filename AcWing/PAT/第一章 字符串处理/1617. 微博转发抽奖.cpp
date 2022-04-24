#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1619/

int m, n, s, group;
vector<string> lists;
unordered_set<string> in_list;
string temp;

int main() {
    cin >> m >> n >> s;  // 转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        if (i < s) continue;  // 还没到第一位中奖
        if (group == 0) {  // 中奖
           if (in_list.count(temp) != 0)
               continue;
           in_list.insert(temp);
           lists.push_back(temp);
        }
        group = (group + 1) % n;
    }
    if (lists.size() == 0) {
        cout << "Keep going...";
        return 0;
    }
    for (auto& item: lists)
        cout << item << endl;
}
