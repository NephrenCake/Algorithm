#include <iostream>

using namespace std;

// 返回10的x次方
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
    for (int i = 1; i <= cnt; i++) {  // 从右往左依次枚举每一位上的x总数
        // 以n=abcdefg为例，假设现在i=4，即计算第四位为x的次数
        // 先计算最高三位为000~abc-1的情况
        int r = power10(i - 1);  // d右边可取到000~999共power10(i-1)个数
        int l = n / power10(i);  // d左边可取到000~abc-1共abc=n/power10(i)=n/(r*10)种情况，当x是0则为001~abc-1共abc-1种
        if (x) res += l * r;
        else res += (l - 1) * r;

        // 再计算高三位等于abc的情况
        int d = (n / r) % 10;  // n/r=abcd;abcd%10=d;
        if (d == x)  // 前四位abcd均相同，后三位可取0~efg共efg+1种
            res += n % r + 1;  // efg+1=n%power(i-1)+1=n%r+1;
        else if (d > x)  // 此时后三位可取000~999共power10(i-1)种
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
