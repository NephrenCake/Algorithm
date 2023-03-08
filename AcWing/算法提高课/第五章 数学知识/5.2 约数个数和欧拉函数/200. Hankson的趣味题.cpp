#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 50010;
int n, a0, a1, b0, b1, primes[N], cnt, used[N];
PII factor[N]; //存储 b1 的所有质因子及个数
int divider[N]; //记录 b1 的所有约数
int cntf, cntd;

void get_pri(int x) {
    for (int i = 2; i <= x; i++) {
        if (!used[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++) {
            used[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void get_fac(int x) {
    for (int i = 0, p = primes[i]; p <= x / p; p = primes[++i])
        if (x % p == 0) {
            int s = 0;
            while (x % p == 0) x /= p, s++;
            factor[cntf++] = {p, s};
        }
    if (x > 1) factor[cntf++] = {x, 1};
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

LL lcm(int a, int b) {
    return (LL) a * b / gcd(a, b);
}

void dfs(int idx, int cur) { //dfs 用质因子拼凑所有约数
    if (idx == cntf) {
        divider[cntd++] = cur;
        return;
    }
    for (int i = 0; i <= factor[idx].second; i++) {
        dfs(idx + 1, cur);
        cur *= factor[idx].first;
    }
}

int main() {
    get_pri(50000); //预处理出 1 ~ sqrt(2 * 1e9) 之间的所有质数
    cin >> n;
    while (n-- && cin >> a0 >> a1 >> b0 >> b1) {
        //将 b1 分解质因子并存入 factor
        cntf = 0;
        get_fac(b1);
        //用 d1 的所有质因子拼凑出 d1 的所有约数
        cntd = 0;
        dfs(0, 1);
        //枚举所有约数，记录满足条件的数的个数
        int ans = 0;
        for (int i = 0, x = divider[i]; i < cntd; x = divider[++i])
            if (gcd(x, a0) == a1 && lcm(x, b0) == b1)
                ans++;
        cout << ans << endl;
    }
}
