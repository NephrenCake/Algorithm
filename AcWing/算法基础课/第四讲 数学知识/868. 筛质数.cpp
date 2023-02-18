#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
int n, used[N];
vector<int> primes;

void get_primes(int x) {
    for (int i = 2; i <= x; i++) {
        if (!used[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= x / i; j++) {  // ����Ҫɸ����n�ĺ���
            used[primes[j] * i] = 1;  // ɸ�� primes[j] * i������һ�������� primes[j]
            // ��һ�γ��� i % primes[j] == 0 ʱ, ˵�� i ����С�������� primes[j], ͬʱ primes[j] * i ����С������Ҳ�� prime[j]��
            // ��������� primes[j + 1] ɸ����ʱ��primes[j + 1] * i = primes[j + 1] * prime[j] * k,
            // �� i ѭ���� prime[j + 1] * k ʱ��ɸ i * prime[j] = prime[j + 1] * k * prime[j]����ǰ���ظ�
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;
    get_primes(n);
    cout << primes.size();
}
