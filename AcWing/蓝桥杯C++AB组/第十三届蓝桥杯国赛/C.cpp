#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;  // M <= N ** 2

int n, m;
vector<pair<int, int>> cards; // n种卡牌和n中手牌有几张；m张空白牌

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        cards.push_back({t, 0});
    }
    for (int i = 0; i < n; i++)
        cin >> cards[i].second;

    sort(cards.begin(), cards.end());

    while (m > 0) {
        // for (auto i: cards)
        //     cout << i.first << " " << i.second << endl;

        if (cards[0].second == 0)
            break;  // 最少的牌无补充

        int d = cards[1].first - cards[0].first + 1;  // 进入下一轮需要的数量

        // cout << "d: " << d << endl;

        int change = min(d, cards[0].second);
        if (d > cards[0].second) {
            cards[0].first += change;
            cards[0].second -= change;
            m -= change;
            break;
        } else {
            cards[0].first += change;
            cards[0].second -= change;
            m -= change;
            sort(cards.begin(), cards.end());
            // cout << "m: " << m << endl;
        }
    }

    cout << cards[0].first;

    return 0;
}
/*
4 6
7 2 6 8
1 5 1 1

 */
