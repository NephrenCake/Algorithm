#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1232/

/**
 * 1. �ȿ��Ǳ���
 *      for r: 1~n
 *          for l: 1~r
 *              if s[r] - s[l - 1] % k == 0:
 *                  res++
 * 2. ���룺��r�̶�ʱ��l �� 1~r ֮���ҵ��ж���l���㣺(s[r] - s[l - 1]) % k == 0
 * 3. �ȼ۱��Σ���r�̶�ʱ��l �� 0~r-1 ֮���ҵ��ж���l���㣺(s[r] - s[l]) % k == 0
 *    �����ж��ٸ� s[r] �� s[l] ��ģk������ͬ
 *
 *       5 2
 * ԭ���� 1 2 3 4 5
 * ǰ׺�� 1 3 6 10 15
 * ȡģ�� 1 1 0 0 1
 */

typedef long long LL;

const int N = 100010;

int n, k;
LL s[N], cnt[N];  // ǰ׺������ ȡģ�������ͳ�ƣ���map�ã�

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = (s[i] + s[i - 1]) % k;  // ǰ׺�ͽ��豣��ȡģ���
    }

    LL res = 0;
    // cnt[0] = 1;
    for (int r = 1; r <= n; r++) {
        // ɨһ�����飬��ʵ�Ǳ���ÿ��r��ȡֵ
        res += cnt[s[r]];  // ����"��r�̶�ʱ"������ͬ����������
        cnt[s[r]]++;  // Ϊͳ�Ƶ�����++
    }
    // ʵ���ϣ�ǰһ����ֻ�Ǽ����˳��ȴ���1��������ϣ�������������û��ͳ�ƣ�������ȡģ�����Ϊ0
    cout << res + cnt[0];  // ��ǰһ�� `cnt[0] = 1;` �ǵȼ۵�
}
