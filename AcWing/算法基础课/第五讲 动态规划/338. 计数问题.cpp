#include <iostream>

using namespace std;

// ����10��x�η�
int power10(int n) {
    int t = 10, res = 1;
    while (n) {
        if (n & 1) res *= t;
        t = t * t;
        n >>= 1;
    }
    return res;
}

unsigned long cnt(int n, int x) {
    unsigned long res = 0, cnt = to_string(n).size();
    for (int i = 1; i <= cnt; i++) {  // ������������ö��ÿһλ�ϵ�x����
        // ��n=abcdefgΪ������������i=4�����������λΪx�Ĵ���
        // �ȼ��������λΪ000~abc-1�����
        int r = power10(i - 1);  // d�ұ߿�ȡ��000~999��power10(i-1)����
        int l = n / power10(i);  // d��߿�ȡ��000~abc-1��abc=n/power10(i)=n/(r*10)���������x��0��Ϊ001~abc-1��abc-1��
        if (x) res += l * r;
        else res += (l - 1) * r;

        // �ټ������λ����abc�����
        int d = (n / r) % 10;  // n/r=abcd;abcd%10=d;
        if (d == x)  // ǰ��λabcd����ͬ������λ��ȡ0~efg��efg+1��
            res += n % r + 1;  // efg+1=n%power(i-1)+1=n%r+1;
        else if (d > x)  // ��ʱ����λ��ȡ000~999��power10(i-1)��
            res += r;
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << cnt(b, i) - cnt(a - 1, i) << " ";
        cout << endl;
    }
}
