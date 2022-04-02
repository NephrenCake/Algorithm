#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

// https://www.acwing.com/problem/content/1297/

/**
 * ��⣺https://www.acwing.com/solution/content/8589/
 * todo ֵ������
 */

typedef long long LL;

const int N = (1 << 20) + 10;

LL f[20 + 10];  // ���ڴ洢�׳˺�

int primes[N];  // ���ڴ������
int cnt;  // ��¼�����ĸ��� Ҳ��Ϊprimes������±�ʹ��
bool st[N];  // ��¼��ǰ�����Ƿ��б�ɸ��
int min_p[N];  // ���ڴ����С������

void get_primes(int n) {  // ѡ��0-n�����е�����
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
    get_primes(N - 1);    //���ڱ����Ƕ��������������ֱ��ɸ����������

    f[0] = 1;

    for (int i = 1; i <= 20; i++)
        f[i] = f[i - 1] * i;

    while (scanf("%d", &x) != -1) {
        LL sum = 1;
        LL total = 0; //��¼X��������

        while (x > 1) {
            int p = min_p[x];
            int k = 0;    //��¼ÿ�����ӵĳ��ִ���
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
