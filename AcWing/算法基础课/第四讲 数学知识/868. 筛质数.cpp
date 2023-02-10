#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, primes[N], cnt, used[N];

void get_primes() {
    for (int i = 2; i <= n; i++) {
        if (used[i] == 0) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {  // ����Ҫɸ����n�ĺ���
            used[primes[j] * i] = 1;  // ɸ�� primes[j] * i������һ�������� primes[j]
            // ��һ�γ��� i % primes[j] == 0 ʱ, ˵�� i ����С�������� primes[j], ͬʱ primes[j] * i ����С������Ҳ�� prime[j]��
            // ��������� primes[j + 1] ɸ����ʱ��primes[j + 1] * i = primes[j + 1] * prime[j] * k,
            // �� i ѭ���� prime[j + 1] * k ʱ��ɸ i * prime[j] = prime[j + 1] * k * prime[j]����ǰ���ظ�
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
