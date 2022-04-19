#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1495/

const int M = 31 * 1440 + 10;

struct Record {
    string time;
    string state;
    int minute;

    bool operator<(const Record &r) const {
        return minute < r.minute;
    }
};

int charge[24], n, month;
map<string, vector<Record>> persons;
double sum[M];  // 存储一个月内所有分钟数的前缀和

int main() {
    for (auto &i: charge)
        cin >> i;
    for (int i = 1; i <= M; i++)
        sum[i] = sum[i - 1] + charge[(i - 1) % 1440 / 60] / 100.0;  // 注意，前缀和优化区间和

    cin >> n;
    char name[50], state[10], time[20];
    int dd, hh, mm, tt;
    while (n--) {
        scanf("%s %d:%d:%d:%d %s", name, &month, &dd, &hh, &mm, state);
        sprintf(time, "%02d:%02d:%02d", dd, hh, mm);
        tt = (((dd - 1) * 24 + hh) * 60) + mm;
        persons[name].push_back({time, state, tt});
    }
    for (auto &p: persons) {
        auto &_name = p.first;
        auto &record = p.second;
        sort(record.begin(), record.end());
        double total = 0, each;
        for (int i = 0; i + 1 < record.size(); i++) {
            auto &a = record[i], &b = record[i + 1];
            if (a.state == "on-line" && b.state == "off-line") {
                if (total == 0)
                    printf("%s %02d\n", _name.c_str(), month);  // 注意，通过钱的总数来确定是否需要输出开头
                cout << a.time << " " << b.time;
                each = sum[b.minute] - sum[a.minute];
                printf(" %d $%.2lf\n", b.minute - a.minute, each);
                total += each;
            }
        }
        if (total != 0)
            printf("Total amount: $%.2lf\n", total);
    }
}
