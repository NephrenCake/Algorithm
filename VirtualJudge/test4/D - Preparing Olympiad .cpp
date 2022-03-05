#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = 0;
int n, minimum, maximum, difference;
vector<int> problemSet;

void dfs(int index, long long sum, int p_min, int p_max) {
    if (index == n)
        return;  // 如果当前步违法，则返回
    if (problemSet[p_max] - problemSet[p_min] >= difference && sum >= minimum && sum <= maximum)
        ans++;  // 如果当前步符合要求，则加一
    for (int next_index = index + 1; next_index < problemSet.size(); ++next_index) {
        dfs(next_index, sum + problemSet[next_index], p_min, next_index);
    }  // 要注意dfs表示更新下一步的状态
}

int main() {
    cin >> n >> minimum >> maximum >> difference;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        problemSet.push_back(temp);
    }
    sort(problemSet.begin(), problemSet.end());

    for (int i = 0; i < problemSet.size(); ++i) {
        dfs(i, problemSet[i], i, i);
    }
    cout << ans;
}
