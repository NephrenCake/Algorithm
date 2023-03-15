#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;
vector<int> v = {0};
int n, f[1000010];

int main() {
    cin >> n;
    for (long long t = 1; t <= n; t *= 2) v.push_back(t);
    // f[i][j] 前i个数，可以组成j的方案数
    f[0] = 1;
    for (int i = 1; i < v.size(); i++)
        for (int j = 0; j <= n; j++) {
            if (j - v[i] >= 0)
                f[j] = (f[j] + f[j - v[i]]) % MOD;
            // cout << v[i] << " " << j << " " << f[i][j] << endl;
        }
    cout << f[n];
}
