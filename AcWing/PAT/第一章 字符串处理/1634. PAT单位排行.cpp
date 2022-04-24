#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1636/

unordered_map<string, pair<int, double>> cnt;
vector<pair<int, pair<int, string>>> lists;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string id, from;
        double score;
        cin >> id >> score >> from;

        for (char &c: from)
            if (c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
        char &lv = id[0];
        if (lv == 'B') score /= 1.5;
        else if (lv == 'T') score *= 1.5;

        cnt[from].second += score;
        cnt[from].first++;
    }

    for (auto &item: cnt)
        lists.push_back({-(item.second.second + 1e-8),  // double精度，防止出现.9999
                         {item.second.first, item.first}});
    sort(lists.begin(), lists.end());

    cout << lists.size() << endl;
    int last_rank = 0;
    int last_score = -1;
    for (int i = 0; i < lists.size(); i++) {
        auto &item = lists[i];
        int score = -item.first;
        string from = item.second.second;
        int num = item.second.first;

        if (last_score != score)
            last_rank = i + 1;
        last_score = score;
        cout << last_rank << " " << from << " " << score << " " << num << endl;
    }
}
