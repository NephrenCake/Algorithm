#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 70;
int n, a[N], sum, len, used[N];

bool dfs(int cnt, int cur, int start){  // ��cnt��  cur��ǰ������г���  start��ʾ��u���ö��λ��;
    if (cnt * len + cur == sum) return true;  // ����ܳ��ȵ�����,����true
    if (cur == len) return dfs(cnt + 1, 0, n - 1);
    for (int i = start; i >= 0; i--)
        if (!used[i] && a[i] + cur <= len) {
            used[i] = 1;
            if (dfs(cnt, a[i] + cur, i - 1)) return true;
            used[i] = 0;
            // �������һ��ĵ�һ�������ܴ��룬���߷���һ������һ�����ܴ��룬��һ��ʧ��
            if (!cur || a[i] + cur == len) return false;
            while (i - 1 >= 0 && a[i - 1] == a[i]) i--;  // ȥ��
        }
    return false;
}

int main() {
    // ע��������ÿ�������պ���ͬ������dfs���ǰ�漸�ⲻҪ��ÿ����ͬ������dfs����
    while (cin >> n, n) {
        memset(used, 0, sizeof used);
        sum = 0, len = 1;
        for (int i = 0; i < n; i++)  cin >> a[i], sum += a[i];
        sort(a, a + n);
        for (len = 1; len < sum; len++)
            if (sum % len == 0 && dfs(0, 0, n - 1))
                break;
        cout << len << endl;
    }
}
