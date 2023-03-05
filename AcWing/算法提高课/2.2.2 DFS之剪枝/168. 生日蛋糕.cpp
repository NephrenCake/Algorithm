#include<iostream>
#include<cmath>

using namespace std;

const int N = 24;
int n, m, v[N], s[N], res = 1e9, R[N], H[N];  //记录每层的半径和高，因为会用到上一层的高度

void dfs(int idx, int cv, int cs) {  // idx当前层次，cv当前处理的体积和，cs当前处理的面积和
    if (cv + v[idx] > n) return;
    if (cs + s[idx] >= res) return;
    if (cs + 2 * (n - cv) / R[idx + 1] >= res) return;  // 注意公式推导
    if (idx == 0) {
        if (cv == n) res = cs;
        return;
    }
    //搜索顺序，先R后H，从大到小
    for (int r = min(R[idx + 1] - 1, (int) sqrt((n - cv - v[idx - 1]) / idx)); r >= idx; r--)
        for (int h = min(H[idx + 1] - 1, (n - cv - v[idx - 1]) / r / r); h >= idx; h--) {
            H[idx] = h, R[idx] = r;
            //最底层的时候需要加上r*r
            int t = idx == m ? r * r : 0;
            dfs(idx - 1, cv + r * r * h, cs + 2 * r * h + t);
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        v[i] += + i * i * i, s[i] += + 2 * i * i;
    //m+1层不存在，作为哨兵，减少边界情况的判断
    R[m + 1] = H[m + 1] = 1e9;
    dfs(m, 0, 0);
    if (res == 1e9) res = 0;
    cout << res;
}
