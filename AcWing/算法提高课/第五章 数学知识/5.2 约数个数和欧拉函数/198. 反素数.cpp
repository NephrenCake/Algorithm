#include<iostream>

using namespace std;

typedef long long LL;
int n, maxd, number;  // ������n��ӵ�����Լ����������С��
int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

void dfs(int idx, int limit, int cur, int sum) {
    // idx ö�ٵ��ڼ�������  limit ��ǰ���������ָ��  cur ��ǰ��  sum ��ǰ����Լ��֮��
    if (sum > maxd || sum == maxd && cur < number) {
        maxd = sum;//���Ǿ�Ҫ����һ��
        number = cur;//Ȼ��number����p���԰�
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
