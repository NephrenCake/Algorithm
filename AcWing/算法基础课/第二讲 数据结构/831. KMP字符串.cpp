#include <iostream>

using namespace std;

const int N = 1000010;
// “next” 数组，若第 i 位存储值为 k
// 说明 p[0...i] 内最长相等前后缀的前缀的最后一位下标为 k
// 即 p[0...k] == p[i-k...i]
int n, m, ne[N];  // n 是模板串长度 m 是模式串长度
string p, s;

int main() {
    cin >> n >> p >> m >> s;
    p = " " + p;
    s = " " + s;
    // next
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];  // 若前后缀匹配不成功，反复令 j 回退，直至到 0 或是 p[i] == p[j + 1]
        if (p[i] == p[j + 1]) j++;  // 匹配成功时，最长相等前后缀变长，最长相等前后缀最后一位变大
        ne[i] = j;  // 令 ne[i] = j，以方便计算 next[i + 1]
    }
    // kmp
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;  // 匹配成功时，模板串指向下一位
        if (j == n) {  // 模板串匹配完成，第一个匹配字符下标为 0，故到 n
            // 匹配成功时，文本串结束位置减去模式串长度即为起始位置
            cout << i - j << ' ';
            j = ne[j];  // 模板串在模式串中出现的位置可能重叠
        }
    }
}
