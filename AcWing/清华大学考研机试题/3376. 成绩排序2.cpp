#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
int n;
vector<PII> ls;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ls.push_back({y, x});
    }
    sort(ls.begin(), ls.end());
    for (auto item: ls)
        cout << item.second << " " << item.first << endl;
}
