#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 50010;
int n, a0, a1, b0, b1, primes[N], cnt, used[N];
PII factor[N]; //�洢 b1 �����������Ӽ�����
int divider[N]; //��¼ b1 ������Լ��
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

void dfs(int idx, int cur) { //dfs ��������ƴ������Լ��
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
    get_pri(50000); //Ԥ����� 1 ~ sqrt(2 * 1e9) ֮�����������
    cin >> n;
    while (n-- && cin >> a0 >> a1 >> b0 >> b1) {
        //�� b1 �ֽ������Ӳ����� factor
        cntf = 0;
        get_fac(b1);
        //�� d1 ������������ƴ�ճ� d1 ������Լ��
        cntd = 0;
        dfs(0, 1);
        //ö������Լ������¼�������������ĸ���
        int ans = 0;
        for (int i = 0, x = divider[i]; i < cntd; x = divider[++i])
            if (gcd(x, a0) == a1 && lcm(x, b0) == b1)
                ans++;
        cout << ans << endl;
    }
}
