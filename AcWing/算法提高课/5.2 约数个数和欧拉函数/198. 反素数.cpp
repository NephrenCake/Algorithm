#include<iostream>

using namespace std;

typedef long long LL;
int n, maxd, number;  // 不超过n，拥有最多约数的数中最小的
int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

void dfs(int idx, int limit, int cur, int sum) {
    // idx 枚举到第几个素数  limit 当前素数的最大指数  cur 当前数  sum 当前所有约数之和
    if (sum > maxd || sum == maxd && cur < number) {
        maxd = sum;//我们就要更新一下
        number = cur;//然后number等于p，对吧
    }
    if (idx == 9) return;
    for (int i = 1; i <= limit; i++) {
        if ((LL) cur * primes[idx] > n) break;
        cur *= primes[idx];
        dfs(idx + 1, i, cur, sum * (i + 1));
    }
}

int main() {
    cin >> n;
    dfs(0, 30, 1, 1);
    cout << number << endl;
}
