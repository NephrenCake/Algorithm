#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/1218/

int n, m;
int ans;

int main() {
    cin >> n;
    do {
        n += m / 3;  // ƿ�ǻ�ƿ
        m %= 3;  // ʣ��ƿ��
        ans += n;  // ��nƿ
        m += n;  // ���ƿ��
        n = 0;  // ƿ��
    } while (m >= 3);
    cout << ans;
}
