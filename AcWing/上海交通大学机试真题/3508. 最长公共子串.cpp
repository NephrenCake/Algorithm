#include <iostream>

using namespace std;

const int N = 10010;
string a, b;
int f[N], ans;

int main() {
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 1; i < a.size(); i++)
        for (int j = b.size() - 1; j; j--) {
            // f[i][j] ��һ���ַ�����a[i]��β���ڶ����ַ�����b[j]��β����������Ӵ��ĳ���
            if (a[i] == b[j] && !('0' <= a[i] && a[i] <= '9'))
                f[j] = f[j - 1] + 1;
            else
                f[j] = 0;  // ����ά�Ż���һάʱ��һ��Ҫ�ֶ�������������ֵ�dpֵ��������Զ�ת��״̬
            ans = max(ans, f[j]);
        }
    cout << ans;
}
