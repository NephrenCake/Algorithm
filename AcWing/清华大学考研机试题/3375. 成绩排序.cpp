#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
int n, inc;
vector<pair<PII, pair<string, int>>> ls;

int main() {
    cin >> n >> inc;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        if (inc)
            ls.push_back({{score, i}, {name, score}});
        else
            ls.push_back({{-score, i}, {name, score}});
    }
    sort(ls.begin(), ls.end());
    for (auto item: ls)
        cout << item.second.first << " " << item.second.second << endl;
}
