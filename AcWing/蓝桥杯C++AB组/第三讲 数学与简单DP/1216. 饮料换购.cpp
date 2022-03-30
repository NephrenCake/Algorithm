#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/1218/

int n, m;
int ans;

int main() {
    cin >> n;
    do {
        n += m / 3;  // Æ¿¸Ç»»Æ¿
        m %= 3;  // Ê£ÓàÆ¿¸Ç
        ans += n;  // ºÈnÆ¿
        m += n;  // ±ä³ÉÆ¿¸Ç
        n = 0;  // Æ¿¿Õ
    } while (m >= 3);
    cout << ans;
}
