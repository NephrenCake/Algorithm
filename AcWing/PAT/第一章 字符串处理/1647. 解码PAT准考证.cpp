#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1649/

struct Stu {
    string ctf;
    string lv;
    string room;
    string date;
    string id;
    int score;
};

int n, m;
vector<Stu> stu;

string order1(string arg) {
    string res;
    for (auto &item: stu)
        if (item.lv == arg)
            res += item.ctf + " " + to_string(item.score) + "\n";
    if (res.empty())
        return "NA\n";
    return res;
}

string order2(string arg) {
    int num = 0, sum = 0;
    for (auto &item: stu)
        if (item.room == arg)
            num++, sum += item.score;
    if (num == 0)
        return "NA\n";
    return to_string(num) + " " + to_string(sum) + "\n";
}

string order3(string arg) {
    unordered_map<string, int> room_num;
    for (auto &item: stu)
        if (item.date == arg)
            room_num[item.room]++;
    set<pair<int, string>> set;
    for (auto &item: room_num)
        set.insert({-item.second, item.first});
    string res;
    for (auto &item: set)
        res += item.second + " " + to_string(-item.first) + "\n";
    if (res.empty())
        return "NA\n";
    return res;
}

int main() {
    cin >> n >> m;  // 考生人数和统计要求的个数
    string ctf;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> ctf >> score;
        // cout << ctf.substr(0, 1) << " " << ctf.substr(1, 3) << " " << ctf.substr(4, 6) <<
        //      " " << ctf.substr(10, 3) << endl;
        stu.push_back({ctf,
                       ctf.substr(0, 1),
                       ctf.substr(1, 3),
                       ctf.substr(4, 6),
                       ctf.substr(10, 3)
                       ,score});
    }
    sort(stu.begin(), stu.end(), [](Stu &s1, Stu &s2) {
        if (s1.score != s2.score)
            return s1.score >= s2.score;
        else
            return s1.ctf <= s2.ctf;
    });

    string order, arg;
    for (int i = 0; i < m; i++) {
        cin >> order >> arg;
        cout << "Case " + to_string(i + 1) + ": " + order + " " + arg << endl;
        if (order == "1") cout << order1(arg);
        else if (order == "2") cout << order2(arg);
        else cout << order3(arg);
    }
}
