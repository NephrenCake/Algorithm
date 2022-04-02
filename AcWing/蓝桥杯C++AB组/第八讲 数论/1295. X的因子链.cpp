#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

// https://www.acwing.com/problem/content/1297/

/**
 * 题解：https://www.acwing.com/solution/content/8589/
 * todo 值得再做
 */

typedef long long LL;

const int N = (1 << 20) + 10;

LL f[20 + 10];  // 用于存储阶乘和

int primes[N];  // 用于存放素数
int cnt;  // 记录素数的个数 也作为primes数组的下标使用
bool st[N];  // 记录当前的数是否有被筛过
int min_p[N];  // 用于存放最小质因数

void get_primes(int n) {  // 选出0-n中所有的素数
    for (int i = 2; i < n; i++) {
        if (!st[i]) {
            st[i] = true;
            primes[cnt] = i;
            min_p[i] = i;
            cnt++;
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            st[i * primes[j]] = true;
            min_p[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}

int x;

int main() {
    get_primes(N - 1);    //由于本题是多个数据输入所以直接筛好所有素数

    f[0] = 1;

    for (int i = 1; i <= 20; i++)
        f[i] = f[i - 1] * i;

    while (scanf("%d", &x) != -1) {
        LL sum = 1;
        LL total = 0; //记录X的因子数

        while (x > 1) {
            int p = min_p[x];
            int k = 0;    //记录每个因子的出现次数
            while (x % p == 0) {
                k++;
                total++;
                x /= p;
            }
            sum *= f[k];
        }

        printf("%lld %lld\n", total, f[total] / sum);
    }
    return 0;
}
