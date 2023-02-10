#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, primes[N], cnt, used[N];

void get_primes() {
    for (int i = 2; i <= n; i++) {
        if (used[i] == 0) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {  // 不需要筛大于n的合数
            used[primes[j] * i] = 1;  // 筛掉 primes[j] * i，他有一个质因子 primes[j]
            // 第一次出现 i % primes[j] == 0 时, 说明 i 的最小质因子是 primes[j], 同时 primes[j] * i 的最小质因子也是 prime[j]。
            // 如果继续用 primes[j + 1] 筛合数时，primes[j + 1] * i = primes[j + 1] * prime[j] * k,
            // 当 i 循环到 prime[j + 1] * k 时会筛 i * prime[j] = prime[j + 1] * k * prime[j]，与前面重复
            printf("i(%d) * primes[%d](%d) = %d\n", i, j, primes[j], primes[j] * i);
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_primes();
    cout << cnt;
}
